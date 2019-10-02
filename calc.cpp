#include <iostream>
using namespace std;


class calculator{
	int a,b;
	char op;
public :
	calculator(){
		op='+';
		a=0;
		b=0;
	}
	calculator(int x,int y,char o){
		op=o;
		a=x;
		b=y;
	}
	int result(){
		switch(op){
			case '*' : return (a*b);
			case '+' : return (a+b);
			case '/' : 
			if(b==0)
				return -1;
			return (a/b);
			case '-' : return (a-b);

		}
	}

};

int main(){
	int a,b;
	char o,choice;
	do{
		cout<<"\nEnter two numbers and the operator : ";
		cin>>a>>o>>b;
		calculator cal(a,b,o);
		cout<<"\nAnswer of a "<<o<<" b : "<<cal.result()<<".";
		cout<<"\nWant to continue : ";
		cin>>choice;
	}while(choice=='Y');
	return 0;
}
