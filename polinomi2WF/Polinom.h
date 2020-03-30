#pragma once
#include "ListCircle.h"
class Polinom
{
private:
	int count;
	int max_st;
	ListCircle CL;
	std::string* processing_string(std::string s, int& k);
	void get_words_diff_razdel(std::string st, std::string zn, std::string* w, int& k);

public:
	Polinom(std::string _s = "", int _cnt = 3, int _max_step = 10);
	Polinom(const Polinom& tmp);
	~Polinom();
	Polinom& operator=(const Polinom& tmp);
	void add(const Monom& tmp);
	void erase(const Monom& tmp);
	Polinom operator+(const Polinom& tmp);
	Polinom operator-(const Polinom& tmp);
	Polinom operator*(const Polinom& tmp);
	Polinom operator* (double kk);
	int get_cnt() const {
		return count;
	}
	int get_max_step() const {
		return max_st;
	}
	void set_cnt(int _cnt) {
		count = _cnt;
	}
	void set_max_step(int _max_step) {
		max_st = _max_step;
	}
	std::string to_string();
};

