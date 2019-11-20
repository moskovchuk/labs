#include "Header.h"
#include <iostream>


using namespace std;

const char* MENU[]{ "1. Create an empty set of char.", "2. Create a set of char (power is known)", "3. Create a set of char (string of symbols is known)", "4. Show set of char", "5. Union of two sets", "6. Adding a new element to the set", "7. Intersection of two sets", "8. Subtraction of two sets", "9. Element search in set", "0. Exit" };
const unsigned menuSZ = sizeof(MENU) / sizeof(MENU[0]);

int main()
{
	unsigned menu = 1, power0;
	Set s;
	Set t;
	Set SUMM, CROSS, DIFFER;
	const char* errmsg = "";
	bool work = true;
	std::cout << "Maximum set size: " << s.getMP() << std::endl;
	do
	{
		if (menu)
			for (size_t i = 0; i != menuSZ; ++i)
				std::cout << MENU[i] << std::endl;
		menu = GetNum("Make your choise: ");
		switch (menu)
		{
		case 0:
			work = false;
			break;
		case 1:
			s = Set();
			std::cout << "You created an empty set of char: power = 0" << std::endl;
			break;
		case 2:
			power0 = GetNum("Power:");
			try {
				s = Set(power0);
				std::cout << s;
			}
			catch (std::exception& ex)
			{
				std::cout << ex.what() << std::endl;
			}
			break;
		case 3:
			std::cout << "String of char (max power is " << s.getMP() << "):" << std::endl;
			try {
				std::cin >> s;
				std::cout << s;
			}
			catch (std::exception& ex)
			{
				std::cout << ex.what() << std::endl;
			}
			break;
		case 4:
			std::cout << s;
			break;
		case 5:
			std::cout << "To unite enter a new set. ";
			std::cout << "String of char (max power is " << s.getMP() << "):" << std::endl;
			std::cin >> t;
			SUMM = SUMM(s, t, 3);
			std::cout << "Union of two sets created." << std::endl;
			std::cout << SUMM;
			break;
		case 6:
			char symbol;
			std::cout << "To add a new element enter a char: ";
			cin.get(symbol);//чтобы считать enter после ввода 
			cin.get(symbol);
			s += symbol;
			break;
		case 7:
			std::cout << "To intersect enter a new set. ";
			std::cout << "String of char (max power is " << s.getMP() << "):" << std::endl;
			std::cin >> t;
			CROSS = CROSS(s, t, 0);
			std::cout << "Intersection of two sets created." << std::endl;
			std::cout << CROSS;
			break;
		case 8:
			std::cout << "To subtract enter a new set. ";
			std::cout << "String of char (max power is " << s.getMP() << "):" << std::endl;
			std::cin >> t;
			DIFFER = DIFFER(s, t, 1);
			std::cout << "Subtraction of two sets created." << std::endl;
			std::cout << DIFFER;
			break;
		case 9:
			char d;
			cout << "Enter element" << endl;
			cin.get(d);//чтобы считать enter после ввода 
			cin.get(d);
			if (s == (d) == true)
				cout << "Element found. " << endl;
			else
				cout << "Element not found. " << endl;
			break;
		default:
			std::cout << "Enter error, try again" << std::endl;
			break;
		}
		if (menu) {
			std::cout << "Enter 0 to continue, 1 to show the menu once again" << std::endl;
			do {
				std::cout << ">>";
				std::cin >> menu;
				if (std::cin.eof())
					work = false;
				else {
					if (!(std::cin.good())) {
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cout << "Enter error, try again" << std::endl;
					}
				}
			} while ((work) && !(std::cin.good()));
		}
	} while (work);
}

