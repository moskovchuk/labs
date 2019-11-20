#include "Set.h"
#include <iostream>
#include <string>


//task 2
Set::Set(int p)
{
	if (p > max_power) {
		power = 0;
	}
	else {
		power = p;
		int a = char(' ');
		for (int i = 0; i < p; ++i)
			set[i] = char(a + i);
	}
}

//task 3
Set::Set(const char* str)
{
	power = strlen(str);
	for (int i = 0; i < power; i++)
		set[i] = str[i];
}

//task 4
std::istream& operator >>(std::istream& p, Set& s) // + 
{
	char str[s.max_power];
	std::cin.getline(str, s.max_power);// enter 
	std::cin.getline(str, s.max_power);
	s.power = strlen(str);
	int j = 0;
	for (int i = 0; i < s.power; i++)
		if (!(s == (str[i])))
			s.set[j++] = str[i];
	s.power = j;
	return p;
}

std::ostream& operator <<(std::ostream& p, const Set& s)
{
	if (s.power) {
		std::cout << "You created a set of char:{ ";
		for (int i = 0; i < s.power; ++i)
			std::cout << "'" << s.set[i] << "' ";
		std::cout << "}" << std::endl;
	}
	else p << "Set is empty" << std::endl;
	return p;
}

//task 5
//Set Set::summ(const Set& p1, const Set& p2)
//{
//
//	for (int i = 0; i < p1.power; i++)
//		this+(p1.set[i]);
//	for (int i = 0; i < p2.power; i++)
//		this+(p2.set[i]);
//	return *this;
//}

//task 6
Set& operator +=(Set& a, const char e)
{
	if (a.power + 1 > a.max_power || a == (e))
		return a;
	a.set[a.power] = e;
	a.power++;
	return a;
}
//
////task 7
//Set Set::cross(const Set& p1, const Set& p2)
//{
//	power = 0;
//	for (int i = 0; i < p1.power; i++)
//		if (p2.In(p1.set[i])) {
//			this->set[power] = p1.set[i];
//			power++;
//			//this=this+(p1.set[i]);
//		}
//	return *this;
//}

//task 8
Set Set:: operator () (const Set& p1, const Set& p2, int u)
{
	power = 0;
	switch (u)
	{
	case 0: {
		for (int i = 0; i < p1.power; i++)

			if (p2 == (p1.set[i])) {
				this->set[power] = p1.set[i];
				power++;
			}
	}
	case 1:
	{
		for (int i = 0; i < p1.power; i++)
			if (!(p2 == (p1.set[i]))) {
				this->set[power] = p1.set[i];
				power++;
			}
	}
	case 3:
	{
		for (int i = 0; i < p1.power; i++)
		{
			{
				this->set[power] = p1.set[i];
				power++;
			}
		}
		for (int i = 0; i < p2.power; i++)
		{
			{
				this->set[power] = p2.set[i];
				power++;
			}
		}
	}
	}
	return *this;
}

//task 9
bool Set:: operator  ==(char e) const
{
	for (int i = 0; i < power; i++)
		if (set[i] == e) return true;
	return false;
}

unsigned GetNum(const char* msg) {
	unsigned n;
	const char* errmsg = "";
	do {
		std::cout << errmsg << std::endl;
		std::cout << msg;
		std::cin >> n;
		if (!(std::cin.good())) {
			errmsg = "Invalid value, try again\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else return n;
	} while (true);
}
