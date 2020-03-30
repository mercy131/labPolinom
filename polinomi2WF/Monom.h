#pragma once
#include <string>
class Monom
{

private:
	double k;
	int sv;
	Monom* next;
	double calc_k(std::string s);
	int calc_sv(std::string s, int max_st, int n);


public:
	int calc_sv(int* pw, int max_step, int n);
	void get_pw(int _sv, int n, int max_st, int* pw);
	Monom(double _k = 1, int _sv = -1);
	~Monom();
	Monom(std::string s, int max_st, int n);
	Monom(const Monom& tmp);
	Monom& operator=(const Monom tmp);
	void set_sv(int k);
	void set_k(double k);
	void set_next(Monom* k);
	double getk()const;
	int get_sv()const;
	Monom* get_next()const;
	Monom operator*(const double tmp);
	Monom mult(Monom tmp, int max_st, int n);
	//	Monom operator*(const double tmp);
	std::string getmonom(int max_st, int n);
	bool operator==(const Monom& a) const {
		return sv == a.sv && k == a.k;
	}


};

