//
//  Metro.cpp
//  Metro
//
//  Created by Анастасия on 11/12/2019.
//  Copyright © 2019 Анастасия. All rights reserved.
//

#include "Metro.h"

namespace Prog4 {
    
    
    int ConstLineIt::operator !=(const ConstLineIt &it) const {
        return cur != it.cur;
    }
    
    int ConstLineIt::operator ==(const ConstLineIt &it) const {
        return cur != it.cur;
    }
    
    Item& ConstLineIt::operator*()
    {
        return *cur;
    }
    
    Item* ConstLineIt::operator->()
    {
        return &(*cur);
    }
    
    ConstLineIt & ConstLineIt::operator++()
    {
        ++cur;
        return *this;
    }
    
    ConstLineIt ConstLineIt::operator++(int)
    {
        ConstLineIt res(*this);
        ++cur;
        return res;
    }
    
    Line::Line(const Line &a)
    {
        std::list<Item>::const_iterator p;
        for (p = a.table.begin(); p != a.table.end(); ++p)
            table.push_back(*p);
    }
    
    Line & Line::operator =(const Line &a)
    {
        std::list<Item>::const_iterator p;
        if (this != &a) {
            table.clear();
            for (p = a.table.begin(); p != a.table.end(); ++p)
                table.push_back(*p);
        }
        return *this;
    }
    
    Line::ConstIterator Line::begin()
    {
        return ConstIterator(table.begin());
    }
    
    
    Line::ConstIterator Line::end()
    {
        return ConstIterator(table.end());
    }
    
    std::list<Item>::iterator Line::find(const std::string &s)
    {
        std::string _exception = "don't find the station";
        std::list<Item>::iterator p;
        for (p = table.begin(); p != table.end(); ++p) {
            if (p->ptr->nameofstation() == s)
                return p;
        }
        throw std::invalid_argument(_exception);
    }
    
    
    
    Line* Line::newstation(Item& p)
    {
        Item tmp = p;
        int n, k;
        if (table.empty())
            table.push_back(tmp);
        else
        {
            n = table.size();
            if (n > 0)
            {
                do {
                    std::cout << "Push before or after; If before enter 0, esle enter 1" << std::endl;
                    std::cin >> k;
                } while ((k != 0) && (k != 1));
                
                std::string str;
                std::cout << "Enter station name --> ";
                std::cin >> str;
                
                if (k == 0) {
                    typename std::list<Item>::iterator first = table.begin();
                    if (first == static_cast<std::list<Item>::iterator>(this->find(str)))
                    {
                        tmp.toprev = 0;
                        std::list<Item>::iterator next = (this->find(str));
                        next->toprev = tmp.tonext;
                        table.insert(this->find(str), tmp);
                    }
                    else {
                        std::list<Item>::iterator prev = --(this->find(str));
                        prev->tonext = tmp.toprev;
                        std::list<Item>::iterator next = this->find(str);
                        next->toprev = tmp.tonext;
                        table.insert(this->find(str), tmp);
                    }
                    
                }
                else {
                    typename std::list<Item>::iterator last = --table.end();
                    if (last == static_cast<std::list<Item>::iterator>(this->find(str))) {
                        tmp.tonext = 0;
                        table.push_back(tmp);
                        last->tonext = tmp.toprev;
                    }
                    else {
                        std::list<Item>::iterator prev = this->find(str);
                        prev->tonext = tmp.toprev;
                        std::list<Item>::iterator next = ++(this->find(str));
                        next->toprev = tmp.tonext;
                        table.insert(++static_cast<std::list<Item>::const_iterator>(this->find(str)), tmp);
                    }
                }
            }
            else
            {
                std::cout << "Before what you want to insert(Enter name of station) " << std::endl;
                std::string str;
                std::cin >> str;
                table.insert(this->find(str), tmp);
            }
        }
        return this;
    }
    
    
    
    //////////////////////////////
    
    
    
    Transition & Transition::setlinename(std::string s[3], int number)
    {
        this->n = number;
        for (int i = 0; i < n; i++)
            this->linename[i] = s[i];
        return *this;
    }
    
    Node & Node::setlinename(std::string s[3], std::string str[3], int number)
    {
        this->n = number;
        for (int i = 0; i < n; i++) {
            this->linename[i] = s[i];
            this->stationname[i] = str[i];
        }
        
        return *this;
    }
    
    
    
    Transition & Transition::newtrans(std::string& str)
    {
        if (n < 2) {
            n = n + 1;
            linename[n] = str;
        }
        
        
        return *this;
    }
    
    Node & Node::newnode(std::string& line, std::string& station)
    {
        if (n < 3) {
            n = n + 1;
            linename[n] = line;
            stationname[n] = station;
        }
        
        
        return *this;
    }
    
    
    /////////////////////////////
    
    Transition * UStation::changetype(std::string s1[3], int n)
    {
        Transition *ptr = new Transition(this->nameofstation());
        ptr->setlinename(s1, n);
        return ptr;
    }
    
    Node * UStation::changetype(std::string s1[3], std::string s2[3], int n)
    {
        Node *ptr = new Node(this->nameofstation());
        ptr->setlinename(s1, s2, n);
        return ptr;
    }
    
    
    
    UStation * Transition::changetype()
    {
        UStation *ptr = new UStation(this->nameofstation());
        return ptr;
    }
    
    Node * Transition::changetype(std::string s1[3], std::string s2[3], int n)
    {
        Node *ptr = new Node(this->nameofstation());
        ptr->setlinename(s1, s2, n);
        return ptr;
    }
    
    
    UStation * Node::changetype()
    {
        UStation *ptr = new UStation(this->nameofstation());
        return ptr;
    }
    
    Transition * Node::changetype(std::string s1[3], int n)
    {
        Transition *ptr = new Transition(this->nameofstation());
        ptr->setlinename(s1, n);
        return ptr;
    }
    
    
    
    
    ///////////////////////////////////
    
    std::ostream & operator <<(std::ostream &os, const Item &p)
    {
        return os << "Station: " << *(p.ptr) << "Distation to prev: " << p.toprev << ";" << " Distation to next: " << p.tonext << std::endl;
    }
    
    std::ostream & operator<<(std::ostream &s, const Line &a)
    {
        s << "===== LINE =====" << std::endl;
        s <<"Color of line: "<< a.line << std::endl << std::endl;
        std::list<Item>::const_iterator pp;
        for (pp = a.table.begin(); pp != a.table.end(); ++pp)
            s << *pp << std::endl;
        return s;
    }
    
    
    std::ostream & Station::print(std::ostream &os) const
    {
        return os << " Name:" << name;
    }
    
    std::ostream & operator << (std::ostream &os,const Station &p)
    {
        return p.print(os);
    }
    
    std::ostream & UStation::print(std::ostream &os) const
    {
        Station::print(os);
        os << " Type: " << (this->typeofstation()) << std::endl;
        return os;
    }
    
    
    std::ostream & operator << (std::ostream &os, const UStation &p)
    {
        return p.print(os);
    }
    
    std::ostream & Transition::print(std::ostream &os) const
    {
        Station::print(os);
        os << " Type: " << (this->typeofstation())<<std::endl;
        std::string tmp;
        os << "linenames: ";
        for (int i = 0; i < n; ++i) {
            tmp = linename[i];
            os << tmp <<"; ";
        }
        return os << std::endl;
    }
    
    std::ostream & operator << (std::ostream &os, const Transition &p)
    {
        return p.print(os);
    }
    
    std::ostream & Node::print(std::ostream &os) const
    {
        Station::print(os);
        os << " Type: " << (this->typeofstation()) << std::endl;
        std::string tmp;
        os << "linenames and its stations: ";
        for (int i = 0; i < n; ++i) {
            tmp = linename[i];
            os << tmp << " - ";
            tmp = stationname[i];
            os << tmp << "; ";
        }
        return os << std::endl;
    }
    
    std::ostream & operator << (std::ostream &os, const Node &p)
    {
        return p.print(os);
    }
    
}
