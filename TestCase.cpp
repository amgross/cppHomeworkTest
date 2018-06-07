//
// Created by אריה גרוס on 07 יוני 2018.
//
#include "TestCase.hpp"

TestCase::TestCase (string arg, ostream &er) :errorType (arg),Fcount(0),Pcount(0){
    err = &er;
    output="";
}
void TestCase::print () {
    output+=errorType+
            ": "+
            to_string(Fcount)+
            " failed, "+
            to_string(Pcount)+
            " passed, "+
            to_string(Fcount+Pcount)+
            " total.\n---\n";
    *err<< output;
}

