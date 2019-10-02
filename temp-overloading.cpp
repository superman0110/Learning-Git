#include <iostream>
#include <string.h>
using namespace std;


class person{
	char name[20];
	int age;
public:
	person(){
		strcpy(name, "");
		age=0;
		}

	void output(){
		cout<<"Name : "<<name<<", Age : "<<age<<endl;
	}
	void input(const char s[],int a){
		strcpy(name,s);
		age=a;
	}
};

template <class T1, class T2>
void Print(T1 x, T2 y){
	cout<<"First print was called : "<<x<<" "<<y<<endl;
}

void Print(char* x, char* y){
	cout<<"Second print was called : "<<x<<" "<<y<<endl;
}

//Horwitz and Sahani
void Print(person x, person y){
	cout<<"Third print was called : \n";
	x.output();
	y.output();
}

void Print(int* x, int* y){
	cout<<"Fourth print was called : "<<*x<<" "<<*y<<endl;
}


void Print(float x, float y){
	cout<<"Fifth print was called : "<<x<<" "<<y<<endl;
}

int main(){
	float a=0.2f,b=0.3f;
	const char arr[100]="Hello ", arr1[100]="World";
	int* x=new int;*x=5;
	int* y=new int;*y=9;
	person ap,bp;
	ap.input("XYZ",10);
	bp.input("ABCD",20);

	cout<<"Printing floats :\n ";
	Print(a,b);
	cout<<"Printing integer pointers :\n ";
	Print(x,y);
	cout<<"Printing strings :\n ";
	Print(arr,arr1);
	cout<<"Printing persons :\n ";
	Print(ap,bp);
	
	return 0;
}
