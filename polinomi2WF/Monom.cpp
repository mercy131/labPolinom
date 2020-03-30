#include "pch.h"
#include "Monom.h"


#include <string>
#include <algorithm>




Monom::Monom(std::string s, int max_st, int n)
{
	k = calc_k(s);
	sv = calc_sv(s, max_st, n);
	next = this;
}
Monom& Monom:: operator=(const Monom tmp)
{
	k = tmp.k;
	sv = tmp.sv;
	next = this;
	return *this;
}
Monom::Monom(double tmp, int Sv_)
{
	k = tmp;
	sv = Sv_;
	next = this;
}

void Monom::get_pw(int _sv, int max_st, int n, int* pw)
{



	for (int i = 0; i < n; i++) pw[i] = 0;
	int ind = 0;
	while (_sv) {
		pw[ind++] = _sv % max_st;
		_sv /= max_st;
	}


}
Monom::Monom(const Monom& tmp)
{
	k = tmp.k;
	sv = tmp.sv;
	next = this;
}

Monom::~Monom()
{
	next = NULL;
}
double Monom::calc_k(std::string s)
{
	double k = 1;
	if (s[0] == '-') {
		k = -1;
		s.erase(0, 1);
	}
	else if (s[0] == '+')
	{
		k = 1;
		s.erase(0, 1);
	}
	else if (s[0] == 'x')
	{
		k = 1;
	}

	std::string st = "";
	while (s.length() && s[0] != 'x') {
		st += s[0];
		s.erase(0, 1);
	}

	if (st.length()) {
		k *= std::atof(st.c_str());
	}
	return k;
}
int Monom::calc_sv(std::string s, int max_st, int n)
{


	int* pw = new int[n];
	for (int i = 0; i < n; i++) pw[i] = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		std::string vari = 'x' + std::to_string(i);

		int ind = s.find(vari);
		int st = ind;
		if (ind < 0 || ind >= s.size()) continue;

		if (ind + vari.size() >= s.size())
		{
			pw[i] = 1;
		}
		else {
			if (s[ind + vari.size()] == '^')
			{
				std::string kk;
				ind += vari.size() + 1;
				while (ind < s.size())
				{
					if (s[ind] >= 'a' && s[ind] <= 'z') break;
					kk += s[ind++];
				}
				pw[i] = atoi(kk.c_str());
				if (pw[i] >= max_st) {
					return -1;
				}
			}
			else {
				pw[i] = 1;
			}
		}
		s.erase(st, ind - st);

	}
	int res(0);
	int gg = 1;
	for (int i = 0; i < n; i++) {
		res += gg * pw[i];
		gg *= max_st;
	}
	res = std::max(-1, res);
	return res;

}
Monom Monom::mult(Monom tmp, int max_st, int n)
{

	if (sv == -1 || tmp.sv == -1) {
		Monom res(-1, -1);
		return res;
	}
	int* pw1 = new int[n];
	int* pw2 = new int[n];
	get_pw(sv, max_st, n, pw1);
	get_pw(tmp.sv, max_st, n, pw2);
	long long ans_sv = 0;
	for (int i = 0; i < n; i++) {
		pw1[i] += pw2[i];
		if (pw1[i] >= max_st) {
			ans_sv = -1;
			break;
		}
	}
	if (ans_sv == -1) {
		Monom res(-1, -1);
		return res;
	}
	ans_sv = calc_sv(pw1, max_st, n);
	Monom res(k * tmp.k, ans_sv);
	return res;
}
std::string Monom::getmonom(int max_st, int n)
{


	if (sv == -1)
	{
		return "+0";
	}
	std::string ans;
	int* pw = new int[n];
	get_pw(sv, max_st, n, pw);
	if (k > 0) ans += '+';
	if (k != 1) ans += std::to_string(k);
	for (int i = n - 1; i >= 0; i--) {
		std::string vari = 'x' + std::to_string(i);
		if (pw[i] == 0) continue;
		ans += vari;
		if (pw[i] == 1) continue;
		ans += '^' + std::to_string(pw[i]);
	}
	if (ans.back() == '+') ans += '1';
	if (ans.size() == 0) ans += '0';
	return ans;
}
int Monom::calc_sv(int* pw, int max_step, int n) {
	int res(0);
	int gg = 1;
	for (int i = 0; i < n; i++) {
		res += gg * pw[i];
		gg *= max_step;
	}
	return res;
}
void Monom::set_k(double tmp)
{
	k = tmp;
}

void Monom::set_sv(int tmp)
{
	sv = k;
}

void Monom::set_next(Monom * tmp)
{
	next = tmp;
}

double Monom::getk()const
{
	return k;
}

int Monom::get_sv()const
{
	return sv;
}

Monom* Monom::get_next()const
{
	return next;
}

Monom Monom::operator*(const double tmp)
{
	k *= tmp;
	return *this;
}