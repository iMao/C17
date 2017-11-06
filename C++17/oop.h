#ifndef _OOP_H_
#define _OOP_H_

#include <iostream>
#include <string>

//---------------------------------���� ���---------------------------------------------

class Stock
{
private:
	std::string company;						//��� ��������
	long shares;								//���������� �����
	double share_val;							//���� 1 �����
	double total_val;							//����� ���� ��������

	void set_tot() { total_val = shares * share_val; }

public:
	Stock();
	Stock(const Stock & stock);
	Stock(const std::string & company, long shares = 0, double share_val = 0.0);
	Stock(double total_val);
	~Stock();

	std::string getCompany()const	{ return company;   }
	long getShares()const			{ return shares;    }
	double getShareVal()const		{ return share_val; }
	double getTotalVal()const		{ return total_val; }



	void buy(long shares, double price);
	void sell(long shares, double price);
	void show()const;
};




void test_class();





























#endif
