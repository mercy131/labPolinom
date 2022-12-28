#include "pch.h"
#include "ListCircle.h"


#include<iostream>

/*POLINME*/
/*comment*/
ListCircle::ListCircle()
{
	head = new Monom(0, -1);
	head->set_next(head);
}
ListCircle & ListCircle:: operator= (const ListCircle & tmp)
{
	if (this == &tmp) return *this;
	Monom * cur = head;
	while (cur->get_next() != head) {
		cur = cur->get_next();
	}
	cur->set_next(nullptr);
	delete head;
	head = new Monom(*(tmp.head));
	cur = tmp.head->get_next();
	Monom* last = head;
	while (cur != tmp.head) {
		Monom* now = new Monom(*cur);
		last->set_next(now);
		last = last->get_next();
		cur = cur->get_next();
	}
	last->set_next(head);
	return *this;
}
ListCircle::ListCircle(const ListCircle & tmp)
{
	if (tmp.head->get_next() == tmp.head) {
		if (tmp.head->getk() != 0) {

			throw  1;
		}
		head = new Monom(0, -1);
		head->set_next(head);
		return;
	}
	head = new Monom(*(tmp.head));
	Monom* last = head;
	Monom* cur = tmp.head->get_next();
	while (cur != tmp.head) {
		Monom* now = new Monom(*(cur));
		last->set_next(now);
		last = last->get_next();
		cur = cur->get_next();
	}
	last->set_next(head);

}
void ListCircle::Add(const Monom & tmp)
{
	if (tmp.get_sv() == -1 || tmp.getk() == 0) return;
	if (head->get_next() == head) {
		Monom* kek = new Monom(tmp);
		kek->set_next(head);
		head->set_next(kek);
		return;
	}
	Monom* last = head->get_next();
	while (last != head) {
		if (last->get_sv() == tmp.get_sv()) {
			double gg = last->getk();
			gg += tmp.getk();
			last->set_k(gg);
			if (gg == 0) {
				erase(tmp);
			}
			return;
		}
		last = last->get_next();
	}
	last = head;
	while (last->get_next() != head) {
		if (last->get_next()->get_sv() < tmp.get_sv()) {
			Monom* kek = new Monom(tmp);
			kek->set_next(last->get_next());
			last->set_next(kek);
			return;
		}
		last = last->get_next();
	}

	Monom* kek = new Monom(tmp);
	kek->set_next(head);
	last->set_next(kek);

}
std::string ListCircle::getList(int max_st, int n)
{
	std::string ans;
	Monom* last = head->get_next();
	while (last != head) {
		ans += last->getmonom(max_st, n);
		last = last->get_next();
	}
	if (ans.size() == 0) ans += "+0";
	return ans;
}
ListCircle::~ListCircle()
{
	Monom* cur = head;
	while (cur->get_next() != head) {
		cur = cur->get_next();
	}
	cur->set_next(nullptr);
	delete head;
}
void ListCircle::erase(const Monom & tmp)
{
	Monom* last = head->get_next();
	while (last != head) {
		if (last->get_sv() == tmp.get_sv()) {
			Monom* kek = head;
			while (kek->get_next() != last) {
				kek = kek->get_next();
			}
			kek->set_next(last->get_next());
			last->set_next(nullptr);
			delete last;
			break;
		}
		last = last->get_next();
	}
}
ListCircle ListCircle::mult(const ListCircle & _1, int max_step, int n) {
	ListCircle res;
	Monom* last_1 = head->get_next();
	while (last_1 != head) {
		Monom* last_2 = _1.head->get_next();
		while (last_2 != _1.head) {
			Monom ans = last_1->mult(*last_2, max_step, n);
			res.Add(ans);
			last_2 = last_2->get_next();
		}
		last_1 = last_1->get_next();
	}
	return res;
}
ListCircle ListCircle:: operator+ (const ListCircle & tmp)
{
	ListCircle res;
	Monom* last = head->get_next();
	while (last != head) {
		res.Add(*last);
		last = last->get_next();
	}
	last = tmp.head->get_next();
	while (last != tmp.head) {
		res.Add(*last);
		last = last->get_next();
	}
	return res;
}
void ListCircle::minus(const Monom & tmp)
{
	Monom kek = tmp;
	kek.set_k(-kek.getk());
	Add(kek);
}
ListCircle ListCircle:: operator- (const ListCircle & tmp)
{

	ListCircle res;
	Monom* last = head->get_next();
	while (last != head) {
		res.Add(*last);
		last = last->get_next();
	}
	last = tmp.head->get_next();
	while (last != tmp.head) {
		res.minus(*last);
		last = last->get_next();
	}
	return res;

}
ListCircle ListCircle::operator* (double k)
{
	ListCircle res(*this);
	Monom* last = res.head->get_next();
	while (last != res.head) {
		last->set_k(last->getk() * k);
		last = last->get_next();
	}
	while (1)
	{
		last = res.head->get_next();
		int ok = 1;
		while (last != res.head) {
			if (last->getk() == 0) {
				res.erase(*last);
				ok = 0;
				break;
			}
			last = last->get_next();
		}
		if (ok) break;
	}
	return res;
}