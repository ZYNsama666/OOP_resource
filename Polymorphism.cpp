#include<iostream>
using namespace std;

class animal{
public:
	virtual void speak()=0;
	animal(){cout<<"animal ���캯��"<<endl;}
	virtual ~animal(){cout<<"animal ��������"<<endl;}
};

class cat:public animal{
public:
	void speak(){cout<<"��"<<endl;}
	cat(){cout<<"cat ���캯��"<<endl;}
	~cat(){cout<<"cat ��������"<<endl;}
};

class dog:public animal{
public:
	void speak(){cout<<"��"<<endl;}
	dog(){cout<<"dog ���캯��"<<endl;}
	~dog(){cout<<"dog ��������"<<endl;}
};
int main(){
	//ֱ������dog���� 
	dog a;
	a.speak(); 
	
	cout<<"���������������������ֽ��ߡ�����������������������" <<endl;
	
	//ֱ������cat���� 
	cat b;
	b.speak(); 
	 
	cout<<"���������������������ֽ��ߡ�����������������������" <<endl;
	
	//��̬����dog���� 
	animal *c=new dog;
	c->speak();
	delete c;
	
	cout<<"���������������������ֽ��ߡ�����������������������" <<endl;
	
	//��̬����cat���� 
	animal *d=new cat;
	d->speak();
	delete d;
	
	cout<<"���������������������ֽ��ߡ�����������������������" <<endl;
} 
