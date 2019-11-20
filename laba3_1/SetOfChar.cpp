//
//  SetOfChar.cpp
//  3.1-29
//
//  Created by Анастасия on 13/10/2019.
//  Copyright © 2019 Анастасия. All rights reserved.
//
#include "SetOfChar.h"
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
    int j=0;
    int flag = 1;
    int k, i;
    for (i = 0; i < power; i++){
        for (k = 0; k < j+1; k++){
            flag = 1;
            if ((set[k] == (str[i]))){
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            set[j++] = str[i];
    }
    power = j;
    //for (int i = 0; i < power; i++)
        //set[i] = str[i];
}

//task 4
std::istream& input(std::istream& p, Set& s) //ввод с помощью строки + не должно быть одинаковых
{
    char str[s.max_power];
    std::cin.getline(str, s.max_power);//чтобы считать enter после ввода
    std::cin.getline(str, s.max_power);
    s.power = strlen(str);
    int j = 0;
    for (int i = 0; i < s.power; i++)
        if (!s.In(str[i])){
            s.set[j] = str[i];
            j++;
        }
    s.power = j;
    return p;
}

std::ostream& show(std::ostream& p, const Set& s)
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
Set Set::summ(const Set& p1, const Set& p2)
{
    Set tmp;
    for (int i = 0; i < p1.power; i++)
        tmp = add(p1.set[i]);
    for (int i = 0; i < p2.power; i++)
        tmp = add(p2.set[i]);
    tmp.power = p1.power + p2.power;
    return tmp;
}

//task 6
Set& Set::add(const char e)
{
    if (power + 1 > max_power || In(e)) return *this;
    set[power] = e;
    power++;
    return *this;
}

//task 7
Set Set::cross(const Set& p1, const Set& p2)
{
    Set tmp;
    tmp.power = 0;
    for (int i = 0; i < p1.power; i++)
        if (p2.In(p1.set[i])) {
            tmp = add(p1.set[i]);
            tmp.power++;
        }
    return tmp;
}

//task 8
Set Set::differ(const Set& p1, const Set& p2)
{
    Set tmp;
    tmp.power = 0;
    for (int i = 0; i < p1.power; i++)
        if (!p2.In(p1.set[i])) {
            tmp = add(p1.set[i]);
            tmp.power++;
        }
    return tmp;
}

//task 9
bool Set::In(char e) const
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
