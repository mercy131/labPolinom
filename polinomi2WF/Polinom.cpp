#include "pch.h"
#include "Polinom.h"


Polinom::Polinom(std::string _s, int _cnt, int _max_step) {
	count = _cnt;
	max_st = _max_step;
	if (_s.size() == 0) return;
	int sz_w = 0;
	std::string * w = processing_string(_s, sz_w);

	for (int i = 0; i < sz_w; i++) {
		Monom tmp(w[i], max_st, count);
		CL.Add(tmp);
	}
}
Polinom::Polinom(const Polinom& tmp) {
	count = tmp.count;
	max_st = tmp.max_st;
	CL = tmp.CL;
}
Polinom& Polinom::operator=(const Polinom& tmp) {
	if (this == &tmp) return *this;
	count = tmp.count;
	CL = tmp.CL;
	max_st = tmp.max_st;
	return *this;
}
void Polinom::add(const Monom & tmp) {
	CL.Add(tmp);
}
void Polinom::erase(const Monom & tmp) {
	CL.minus(tmp);
}
Polinom Polinom::operator+(const Polinom & tmp) {
	Polinom res(*this);
	res.CL = res.CL + tmp.CL;
	return res;
}
Polinom Polinom::operator-(const Polinom & tmp) {
	Polinom res(*this);
	res.CL = res.CL - tmp.CL;
	return res;
}

Polinom Polinom::operator*(double kk) {
	Polinom res(*this);
	res.CL = res.CL * kk;
	return res;
}

Polinom Polinom::operator*(const Polinom & tmp) {
	Polinom res(*this);
	res.CL = res.CL.mult(tmp.CL, max_st, count);
	return res;
}

std::string Polinom::to_string() {
	std::string ans = CL.getList(max_st, count);
	return ans;
}
Polinom::~Polinom()
{
}
std::string* Polinom::processing_string(std::string s, int& k) {
	std::string zn = "+-";
	k = 0;
	std::string* w = new std::string[(s.size() + 1) / 2];
	get_words_diff_razdel(s, zn, w, k);
	for (int i = 0; i < k; i++) {
		while (1) {
			int pos = (int)w[i].find(" ");
			if (pos == -1) break;
			w[i].erase(pos, 1);
		}
	}
	return w;
}
void Polinom::get_words_diff_razdel(std::string st, std::string zn, std::string * w, int& k)
{
	for (int i = 0; i < st.size(); i++) {
		if (zn.find(st[i]) == -1) {
			w[k].push_back(st[i]);
		}
		else {
			if (w[k].size() > 0) {
				k++;
			}
			w[k] += st[i];
		}
	}
	if (w[k].size()) k++;
}