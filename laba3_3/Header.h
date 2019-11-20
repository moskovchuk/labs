//
//  Header.h
//  3_3
//
//  Created by Анастасия on 17/11/2019.
//  Copyright © 2019 Анастасия. All rights reserved.
//

#ifndef Header_h
#define Header_h
#pragma once
#include <iostream>

unsigned GetNum(const char* msg);

class Set
{
private:
    static const int QUOTA = 100;
    //int SZ;
    int power;
    char* set;
    /*static const int max_power = 100;
     int power;
     char set[max_power];*/
public:
    int getMP() { return power; };
    char get_value(int i) const { return set[i]; };
    int get_power() const {return power;};
    //task 1
    Set() :power(0), set(new char[0]) {}
    //task 2
    Set(int p) :power(p < 255? p: 255), set(new char[power]) {
        {
            //power = p;
            int a = char(' ');
            int num(0);
            for (int i = 0; i < p; ++i)
            {
                if (!(*this == char(a + i))) {
                    set[num] = char(a + i);
                    ++num;
                }
            }
            std::cout << num;
        }
    }
    ~Set(){
        delete[] set;
    }
    //task 3
    Set(const char* s);
    //task 6
    friend Set& operator +=(Set& p1, const char e);
    Set& operator =(Set&);
    //Set& operator =(Set&&);
    
    //task 9
    bool operator ==(char e) const;
    //task 8//7//5
    Set operator () (const Set& p1, const Set& p2, int u);
    //task 7
    //Set cross(const Set& p1, const Set& p2);
    //task 5
    //Set summ(const Set& p1, const Set& p2);
    //task 4
    friend std::istream& operator >>(std::istream& p, Set& s);
    friend std::ostream& operator <<(std::ostream& p, const Set& s);
};

#endif /* Header_h */
