#include<iostream>
using namespace std;

class bass{
public:
	int bass_a;
	bass(int a=0,int b=0,int c=0){
		bass_a=a;
		bass_b=b;
		bass_c=c;
	}
private:
	int bass_b;
protected:
	int bass_c;
};

class derived1:public bass{
public:
	void show(){
		cout<<bass_a<<endl;
		//cout<<bass_b<<endl;
		//���ۺ��ּ̳з�ʽ���ܷ���bass��private
		cout<<bass_c<<endl;
	}
};
class derived2:private bass{
public:
	void show(){
		cout<<bass_a<<endl;
		//cout<<bass_b<<endl;
		//���ۺ��ּ̳з�ʽ���ܷ���bass��private
		cout<<bass_c<<endl;
	}
};
class derived3:protected bass{
public:
	void show(){
		cout<<bass_a<<endl;
		//cout<<bass_b<<endl;
		//���ۺ��ּ̳з�ʽ���ܷ���bass��private
		cout<<bass_c<<endl;
	}
};
int main(){
	derived1 a;
	cout<<a.bass_a<<endl; 
	//cout<<a.bass_b<<endl; 
	//cout<<a.bass_c<<endl; 
	//�����̳У�ά��ԭ״�����Է��ʵ�bass_a
 
	
	derived2 b;
	//cout<<b.bass_a<<endl; 
	//cout<<b.bass_b<<endl; 
	//cout<<b.bass_c<<endl; 
	//˽�м̳У�public��protectedȫ��private��һ�����ܷ��� 
	
	derived3 c;
	//cout<<c.bass_a<<endl; 
	//cout<<c.bass_b<<endl; 
	//cout<<c.bass_c<<endl; 
	//�����̳У�public��protectedȫ��protected��һ�����ܷ��� 
} 
