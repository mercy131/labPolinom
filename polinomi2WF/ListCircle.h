#pragma once
#include "Monom.h"
#include <iostream>
class ListCircle
{
private:
	Monom* head;
public:
	ListCircle();
	ListCircle(const ListCircle& tmp);
	~ListCircle();
	ListCircle& operator= (const ListCircle& tmp);
	void Add(const Monom& tmp);
	ListCircle operator+ (const ListCircle& tmp);
	ListCircle operator- (const ListCircle& tmp);
	ListCircle operator* (double k);
	void minus(const Monom& tmp);
	ListCircle mult(const ListCircle& _1, int max_step, int n);
	std::string getList(int max_st, int n);
	void erase(const Monom& tmp);
	Monom* get_head() const
	{
		return head;
	}
};

