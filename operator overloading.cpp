#include<iostream>
using namespace std;

template<class T>
class CMyclass{
private:
	T _a;
public:
	CMyclass(T a=0){_a=a;}
	~CMyclass(){_a=0;}
	template<class U>friend ostream& operator<< (ostream&, const CMyclass<U>&);
	template<class U>friend istream& operator>> (istream&, const CMyclass<U>&);
	template<class U>friend CMyclass<U> operator-(CMyclass<U>, CMyclass<U>);
	CMyclass<T>& operator=(T);
	bool operator==(const CMyclass&);
	const CMyclass<T>& operator++();//pre 
	const CMyclass<T> operator++(T);//pos 
	CMyclass<T> operator+(const CMyclass&);
};

template<class U>//重载左移运算符 
ostream& operator<<(ostream& os, const CMyclass<U>& c){
	os<<c._a;
	return os;
}

template<class T>//重载++pre 
const CMyclass<T>& CMyclass<T>::operator++(){
	_a++; 
	return *this;
}

template<class T>//重载++pos 
const CMyclass<T> CMyclass<T>::operator++(T){
	CMyclass<T> temp;
	temp._a=_a++;
	return temp;
}

template<class T>//重载=赋值 
CMyclass<T>& CMyclass<T>::operator=(T a){
	_a=a;
	return *this;
}

template<class T>//重载==比较
bool CMyclass<T>::operator==(const CMyclass& x){
	if(this->_a==x._a)return true;
	else return false;
}

template<class T>//类成员重载+赋值 
CMyclass<T> CMyclass<T>::operator+(const CMyclass& x){
	CMyclass<T> temp;
	temp._a=this->_a+x._a;
	return temp;
}

template<class U>//全局重载-赋值 
CMyclass<U> operator-(CMyclass<U> x, CMyclass<U> y){
	CMyclass<U> temp;
	temp._a=x._a-y._a;
	return temp;
}



int main(){
	CMyclass<int> a(10),b(20),c,d;
	cout<<"a="<<a<<" b="<<b<<endl; 
	a=20;
	cout<<"a="<<a<<" b="<<b<<endl; 
	c=a+b;
	cout<<"c=a+b  c="<<c<<endl;
	d=a-b;
	cout<<"d=a-b  d="<<d<<endl;
	
	if(a==b)cout<<"a==b"<<endl;
	else cout<<"a!=b"<<endl;
	
	if(c==d)cout<<"c==d"<<endl;
	else cout<<"c!=d"<<endl;
	
	cout<<"注：gcc 4.9.1及以下先运算a++再输出a，会出现错误"<<endl; 
	cout<<"a="<<a<<" a++="<<a++<<" a="<<a<<endl;
	cout<<"b="<<b<<" ++b="<<++b<<" b="<<b<<endl;
}
