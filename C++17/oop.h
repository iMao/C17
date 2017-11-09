#ifndef _OOP_H_
#define _OOP_H_

#include <iostream>
#include <string>


using std::cout;
using std::wcout;

using std::cin;
using std::wcin;

using std::endl;


using std::string;





//---------------------------------���� ���---------------------------------------------

class Stock
{
private:
	static int counter;																	//������� ���������� ��������
	std::string company;																//��� ��������
	long shares;																		//���������� �����
	double share_val;																	//���� 1 �����
	double total_val;																	//����� ���� ��������

	void set_tot() { total_val = shares * share_val; }

public:
	Stock();																			//����������� �� ���������	
	Stock(double total_val);															//����������� � ����� ����������			
	Stock(const std::string & company, long shares = 0, double share_val = 0.0);		//����������� � ����������� �����������
	Stock(const Stock & stock);															//����������� �����������	
	~Stock();																			//����������

	std::string getCompany()const	{ return company;   }
	long getShares()const			{ return shares;    }
	double getShareVal()const		{ return share_val; }
	double getTotalVal()const		{ return total_val; }

	void buy(long shares, double price);
	void sell(long shares, double price);
	void show()const;

	static void set_counter(int init_val);												//����������� ������� ������������� �������� ��������			

};





class A {
public:
	std::string s;

	A() :s("Default class A") { std::cout << "Default constructor of class A()" << std::endl; }
	A(std::string s) :s(s)    { std::cout << "Constructor of class A(p)" << std::endl; }
	A(const A& a) :s(a.s)     { std::cout << "Copy constructor of class A(A&)" << std::endl; }
	A(A&& a)                  
	{ 
		s = std::move(a.s);  
		std::cout << "Move constructor of class A(A&&)" << std::endl; 
	}

	~A() { std::cout << "Destructor of class A - " + s << std::endl; }

	void p() { std::cout << "s - " << s << std::endl; }
};





//-------------------------------------������������------------------------------------------------------------------------------
class Base {
private:
	int i;
	int j;
public:
	Base() { i = 0; j = 0; }
	Base(int i, int j) :i(i), j(j) { std::cout << "Constructor Base" << std::endl; }
	~Base() { std::cout << "Destructor Base" << std::endl; }

	void setij(int a, int b) { i = a; j = b; }
	void showij() { std::cout << "i = " << i << " " << "j = " << j << std::endl; }
};




class OpenBase : public Base
{
private:
	int k;
public:
	OpenBase() :Base(){
		k = 0;
		cout << "Default OpenBase constructor " << endl; 
	}
	
	OpenBase(int i, int j, int k) : Base(i,j), k(k) {
		cout << "OpenBase(p1,p2,p3) constructor " << endl; 
	}
	
	~OpenBase() {
		cout << "Destructor OpenBase" << endl; 
	}

	void setk(int k) { this->k = k; }
	void showk()const { cout << "k = " << k << endl; }
	
};

class PrivateBase : private Base
{
private:
	int m;
public:
	PrivateBase() :Base(),m(0) {
		cout << "Default PrivateBase constructor " << endl;
	}

	PrivateBase(int i, int j, int m) :Base(i, j),m(m) {
		cout << "PrivateBase(p1,p2,p3) constructor " << endl;
	}

	~PrivateBase() {
		cout << "Destructor PrivateBase" << endl;
	}

	void showijm(){
		showij();						//��������� � �������� ��������-������ �������� ������
		cout << "m = " << m << endl;
	}
};





















void test_class();





























#endif
