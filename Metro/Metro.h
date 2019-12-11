//
//  Metro.h
//  Metro
//
//  Created by Анастасия on 11/12/2019.
//  Copyright © 2019 Анастасия. All rights reserved.
//

#ifndef Metro_h
#define Metro_h
#include <iostream>
#include <string>
#include <list>
//#include "list (1).h"

namespace Prog4 {
    class Station;
    class UStation;
    class Transition;
    class Node;
    
    struct Item {
        int tonext;
        int toprev;
        Station* ptr;
    };
    
    std::ostream & operator <<(std::ostream &, const Item &);
    
    class ConstLineIt
    {
    private:
        std::list<Item>::iterator cur;
    public:
        ConstLineIt() {};
        ConstLineIt(std::list<Item>::iterator it) :cur(it) {}
        int operator !=(const ConstLineIt &) const;
        int operator ==(const ConstLineIt &) const;
        Item & operator *();
        Item * operator ->();
        ConstLineIt & operator ++ ();
        ConstLineIt operator ++ (int);
        operator typename std::list<Item>::const_iterator(){
            return cur;
        }
    };

    class Line {
    private:
        std::list<Item> table;
        std::string line;
    public:
        Line() {};
        Line(std::string &s): line(s), table() {};
        Line(const Line &);
        ~Line() {};
        
        Line & operator = (const Line &);
        
        friend std::ostream & operator <<(std::ostream &, const Line &);
        
        friend class ConstLineIt;
        using ConstIterator = ConstLineIt;
        ConstIterator begin();
        ConstIterator end();
        std::list<Item>::iterator find(const std::string &);
        
        
        bool empty() { return table.empty(); };
        std::string nameofline() { return line; }
        Line* newstation(Item& p);
    };
    
    
    
    class Station
    {
    private:
        int n = 0;
        std::string name;
        friend std::ostream & operator <<(std::ostream &, const Station &);
    protected:
        virtual std::ostream & print(std::ostream &)const;
    public:
        Station() {};
        Station(const std::string & s) : name(s) {}
        ~Station() {};
        std::string nameofstation()const { return name; }
        std::string changename(std::string& s) { name = s; return name; };
        
        virtual Station* copy() const = 0;
        virtual std::string typeofstation()const { return "Station"; };
        
        virtual UStation * changetype() = 0;
        virtual Transition* changetype(std::string[3], int)  = 0;
        virtual Node* changetype(std::string[3], std::string[3], int)  = 0;
    };
    
    class UStation : public Station
    {
    private:
        int n = 0;
        friend std::ostream & operator <<(std::ostream &, const UStation &);
    protected:
        std::ostream & print(std::ostream &)const;
    public:
        UStation() {};
        UStation(const std::string & s) : Station(s) {}
        
        UStation * changetype() { return this; };
        Transition* changetype(std::string [3], int) ;
        Node* changetype(std::string[3], std::string[3], int) ;
        
        

        std::string typeofstation()const { return "Ustation"; };
        UStation* copy() const { return new UStation(*this); };
    };
    
    class Transition : public Station
    {
    private:
        int n = 0;
        std::string linename[3];
        friend std::ostream & operator <<(std::ostream &, const Transition &);
    protected:
        std::ostream & print(std::ostream &)const;
    public:
        Transition() {};
        Transition(const std::string & s) : Station(s) {}
        
        Transition& newtrans(std::string&);
        
        
        UStation * changetype();
        Transition* changetype(std::string[3], int) { return this; };
        Node* changetype(std::string s1[3], std::string s2[3], int n) ;
        
        Transition& setlinename(std::string s[3], int);
        
        
        
        std::string typeofstation()const { return "Transition"; };
        Transition* copy() const { return new Transition(*this); };
    };
    
    class Node : public Station
    {
    private:
        int n = 0;
        std::string linename[3];
        std::string stationname[3];
        friend std::ostream & operator <<(std::ostream &, const Node &);
    protected:
        std::ostream & print(std::ostream &)const;
    public:
        Node() {};
        Node(const std::string & s) : Station(s) {}
        
        Node& newnode(std::string&, std::string&);
        
        Node& setlinename(std::string s[3], std::string str[3], int);
        
        UStation * changetype() ;
        Transition* changetype(std::string[3], int) ;
        Node* changetype(std::string s1[3], std::string s2[3], int n) { return this; };
        
        
        
        std::string typeofstation()const { return "Node"; };
        Node* copy() const { return new Node(*this); };
    };
}

#endif /* Metro_h */
