#include <bits/stdc++.h>
using namespace std;

int numOfLines = 0, numOfComments = 0, isComment = false, numOfEmptyLines = 0;

int indOfEndMulti_Comment(string s) {
	for (int i = 0; i + 1 < s.length(); i++) {
		if (s[i] == '*' && s[i + 1] == '/') {
			return i + 2;
		}
	}
	return -1;
}

void solve(string s) {
	if (isComment) {
		int index = indOfEndMulti_Comment(s);
		if (index == -1) {
			// end of multiline comment not found, do nothing
			return;
		}
		isComment = false;
		// solve further for the remaining string
		s = s.substr(index);
	}

	int beg = 0;
	while (beg < s.length() && s[beg] == ' ' || s[beg] == '\t')	beg++;

	// empty line
	if (beg == s.length()) {
		numOfEmptyLines++;
		return;
	}
	// entire line is a single line comment
	if (beg + 1 < s.length() && s[beg] == '/' && s[beg + 1] == '/') {
		numOfComments++;
		return;
	}
	// entire line is beginning of a multiline comment
	if (beg + 1 < s.length() && s[beg] == '/' && s[beg + 1] == '*') {
		numOfComments++;
		isComment = true;
		return;
	}
	// contains some text, and then may contain some comment
	numOfLines++;
	for (int i = beg; i + 1 < s.length(); i++) {
		if (s[i] == '/' && s[i + 1] == '/') {
			numOfComments++;
			break;
		} if (s[i] == '/' && s[i + 1] == '*') {
			numOfComments++;
			isComment = true;
			break;
		}
	}
}

int main() {
	ifstream infile;
	infile.open("inputfile.txt");
	if (!infile) {
		cout << "Could not open file\n";
		exit(1);
	}
	string s;
	while (getline(infile, s)) {
		solve(s);
	}
	cout << "\nNumber Of lines : " << numOfLines;
	cout << "\nNumber Of Empty lines : " << numOfEmptyLines;
	cout << "\nNumber Of Comments : " << numOfComments;
	cout << "\n";
	return 0;
}
