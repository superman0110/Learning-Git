#include <bits/stdc++.h>
using namespace std;

#define pb push_back

double drivers[15][5] = {

	{0.75, 0.88, 1, 1.15, 1.40},
	{ 1.00, 0.94, 1, 1.08, 1.16},
	{0.70, 0.85,  1.15, 1.30},
	{ 1.00, 1.00, 1, 1.11, 1.30},
	{ 1.00, 1.00, 1, 1.06, 1.21},
	{ 1.00, 0.87, 1, 1.15, 1.30},
	{ 1.00, 0.87, 1, 1.07, 1.15},
	{1.46, 1.19, 1, 0.86, 0.71},
	{1.29, 1.13, 1.00, 0.91, 0.82},
	{1.42, 1.17, 1, 0.86, 0.70},
	{1.21, 1.10, 1, 0.90, 1.00},
	{1.14, 1.07, 1, 0.95, 1.00},
	{1.24, 1.10, 1.00, 0.91, 0.82},
	{1.24, 1.10, 1, 0.91, 0.83},
	{1.23, 1.08, 1, 1.04, 1.10}

};

vector<string> preProcessStrings() {

	vector<string> vs;
	vs.pb("Required Software Reliability");
	vs.pb("Size of application database");
	vs.pb("Complexity of the product");
	vs.pb("Run-time performance constraints");
	vs.pb("Memory constraints");
	vs.pb("Volatility of the virtual machine environment");
	vs.pb("Required turnabout time");
	vs.pb("Analyst capability");
	vs.pb("Application experience");
	vs.pb("Software enginner capability");
	vs.pb("Virtual machine experience");
	vs.pb("Programming language experience");
	vs.pb("Application of software enginnering methods");
	vs.pb("Use of software tools");
	vs.pb("Required of development schedule");
	return vs;

}
void printOptions() {
	cout << "\n\ta. Very Low";
	cout << "\n\tb. Low";
	cout << "\n\tc. Nominal";
	cout << "\n\td. High";
	cout << "\n\te. Very High";
	cout << "\nEnter choice : ";
}
double getEaf() {

	cout << "\nRate all the following attributes on a scale of 1 to 5\n";
	vector<string> vs = preProcessStrings();
	int i = 0;
	double eafVal = 1.00;
	int choice;
	while (i < vs.size()) {
		cout << "\n" << i + 1 << ". " << vs[i] << " : ";
		printOptions();
		cin >> choice;
		if (choice >= 1 && choice <= 5) {
			eafVal = eafVal * drivers[i][choice - 1];
		} else {
			eafVal = eafVal * 1.00;
		}
		i++;
	}
	return eafVal;

}

int main() {

	double kloc, a, b;
	cout << "\nEnter kloc : ";
	cin >> kloc;

	if (kloc >= 2 && kloc <= 50 ) {
		a = 3.2; b = 1.05;
	} else if (kloc > 50 && kloc <= 300) {
		a = 3.0; b = 1.12;
	} else {
		a = 2.8; b = 1.20;
	}

	double eafValue = getEaf();
	double ans = a * (pow(kloc, b)) * eafValue;

	cout << "Effort Applied :  " << ans << "man-months\n";
	return 0;

}
