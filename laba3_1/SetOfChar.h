//
//  SetOfChar.h
//  3.1-29
//
//  Created by Анастасия on 13/10/2019.
//  Copyright © 2019 Анастасия. All rights reserved.
//
#pragma once
#ifndef _SET_H_
#define _SET_H_
#include <iostream>

unsigned GetNum(const char* msg);

class Set
{
private:
    static const int max_power = 100;
    int power;
    char set[max_power];
public:
    int getMP() { return max_power; };
    char get_value(int i) const { return set[i]; };
    int get_power()const {return power;};
    //task 1
    Set() : power(0) {};
    //task 2
    Set(int p);
    //task 3
    Set(const char* s);
    //task 6
    Set& add(const char e);
    //task 9
    bool In(char e) const;
    //task 8
    Set differ(const Set& p1, const Set& p2);
    //task 7
    Set cross(const Set& p1, const Set& p2);
    //task 5
    Set summ(const Set& p1, const Set& p2);
    //task 4
    friend std::istream& input(std::istream& p, Set& s);
    friend std::ostream& show(std::ostream& p, const Set& s);
};

#endif // !_SET_H_
