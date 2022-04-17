#include<iostream>
using namespace std;

class animal{
public:
	virtual void speak()=0;
	animal(){cout<<"animal 构造函数"<<endl;}
	virtual ~animal(){cout<<"animal 析构函数"<<endl;}
};

class cat:public animal{
public:
	void speak(){cout<<"喵"<<endl;}
	cat(){cout<<"cat 构造函数"<<endl;}
	~cat(){cout<<"cat 析构函数"<<endl;}
};

class dog:public animal{
public:
	void speak(){cout<<"汪"<<endl;}
	dog(){cout<<"dog 构造函数"<<endl;}
	~dog(){cout<<"dog 析构函数"<<endl;}
};
int main(){
	//直接声明dog对象 
	dog a;
	a.speak(); 
	
	cout<<"——————————分界线————————————" <<endl;
	
	//直接声明cat对象 
	cat b;
	b.speak(); 
	 
	cout<<"——————————分界线————————————" <<endl;
	
	//动态声明dog对象 
	animal *c=new dog;
	c->speak();
	delete c;
	
	cout<<"——————————分界线————————————" <<endl;
	
	//动态声明cat对象 
	animal *d=new cat;
	d->speak();
	delete d;
	
	cout<<"——————————分界线————————————" <<endl;
} 
