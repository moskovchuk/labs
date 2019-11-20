//
//  tests.cpp
//  Test-3_2
//
//  Created by Анастасия on 13/11/2019.
//  Copyright © 2019 Анастасия. All rights reserved.
//

#include <iostream>
#include "gtest/gtest.h"
#include "Set.h"

TEST(SetConstuctor, defaultConstructor) {
    Set s;
    ASSERT_EQ(0, s.get_power());
}

TEST(SetConstuctor, powerConstructor){
    Set s;
    int p = 4;
    s = Set(p);
    ASSERT_EQ(4, s.get_power());
    ASSERT_EQ(' ', s.get_value(0));
    ASSERT_EQ('!', s.get_value(1));
    ASSERT_EQ('"', s.get_value(2));
    ASSERT_EQ('#', s.get_value(3));
}

TEST(SetConstuctor, stringConstructor1){
    Set s("ur95 4j");
    ASSERT_EQ(7, s.get_power());
    ASSERT_EQ('u', s.get_value(0));
    ASSERT_EQ('r', s.get_value(1));
    ASSERT_EQ('9', s.get_value(2));
    ASSERT_EQ('5', s.get_value(3));
    ASSERT_EQ(' ', s.get_value(4));
    ASSERT_EQ('4', s.get_value(5));
    ASSERT_EQ('j', s.get_value(6));
}

TEST(SetConstuctor, stringConstructor2){
    Set f("ww");
    ASSERT_EQ(1, f.get_power());
    ASSERT_EQ('w', f.get_value(0));
    Set s("yurb585uv fj");
    ASSERT_EQ(10, s.get_power());
    ASSERT_EQ('y', s.get_value(0));
    ASSERT_EQ('u', s.get_value(1));
    ASSERT_EQ('r', s.get_value(2));
    ASSERT_EQ('b', s.get_value(3));
    ASSERT_EQ('5', s.get_value(4));
    ASSERT_EQ('8', s.get_value(5));
    ASSERT_EQ('v', s.get_value(6));
    ASSERT_EQ(' ', s.get_value(7));
    ASSERT_EQ('f', s.get_value(8));
    ASSERT_EQ('j', s.get_value(9));
}

TEST(SetConstuctor, stringConstructor3){
    Set s('\0');
    ASSERT_EQ(0, s.get_power());
}

TEST(SetMethods, SUMM){
    Set a("qwe");
    Set b("123");
    Set s;
    s = s(a,b,3);
    ASSERT_EQ(6, s.get_power());
    ASSERT_EQ('q', s.get_value(0));
    ASSERT_EQ('w', s.get_value(1));
    ASSERT_EQ('e', s.get_value(2));
    ASSERT_EQ('1', s.get_value(3));
    ASSERT_EQ('2', s.get_value(4));
    ASSERT_EQ('3', s.get_value(5));
}

TEST(SetMethods, DIFFER){
    Set a("qwerty");
    Set b("1e2r3");
    Set s;
    s = s(a,b,1);
    ASSERT_EQ('q', s.get_value(0));
    ASSERT_EQ('w', s.get_value(1));
    ASSERT_EQ('t', s.get_value(2));
    ASSERT_EQ('y', s.get_value(3));
}

TEST(SetMethods, CROSS){
    Set a("qwerty");
    Set c("3yq");
    Set s;
    s = s(a, c, 0);
    ASSERT_EQ('q', s.get_value(0));
    ASSERT_EQ('y', s.get_value(1));
}

TEST(SetMethods, ADD){
    Set s("qwerty");
    s += ' ';
    ASSERT_EQ(7, s.get_power());
    ASSERT_EQ('q', s.get_value(0));
    ASSERT_EQ('w', s.get_value(1));
    ASSERT_EQ('e', s.get_value(2));
    ASSERT_EQ('r', s.get_value(3));
    ASSERT_EQ('t', s.get_value(4));
    ASSERT_EQ('y', s.get_value(5));
    ASSERT_EQ(' ', s.get_value(6));
}

TEST(SetMethods, In){
    Set s("123ty");
    bool k, l;
    k = s==' ';
    l = s=='3';
    ASSERT_EQ(false, k);
    ASSERT_EQ(true, l);
}

TEST(SetMethods, input){
    Set s("eetry");
    std::cin >> s;
    ASSERT_EQ(s.get_power(), 4);
    ASSERT_EQ(s.get_value(0), 'e');
    ASSERT_EQ(s.get_value(1), 't');
    ASSERT_EQ(s.get_value(2), 'r');
    ASSERT_EQ(s.get_value(3), 'y');
}

int main(int argc, char * argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
