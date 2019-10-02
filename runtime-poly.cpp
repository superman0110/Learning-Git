#include <iostream>
using namespace std;

class figures{
public:
	virtual void area()=0;
};

class rectangle:public figures{
	int c,d;
public:
	rectangle(int x,int y){
		c=x;
		d=y;
	}
	void area(){
		cout<<"Area of rectangle is : "<<c*d<<"\n";
	}
};

class triangle : public figures{
	int height,breadth;
public:
	triangle(int c,int d){
		height=c;
		breadth=d;
	}
	void area(){
		cout<<"Area of triangle is : "<<(height*breadth)/2<<"\n";
	}
};
int main(){
	triangle mTriangle(20,10);
	rectangle mRectangle(20,10);
	figures* fig[2]={&mTriangle, &mRectangle};
	fig[0]->area();fig[1]->area();
	return 0;
}
