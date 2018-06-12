//
// Created by אריה גרוס on 04 יוני 2018.
//
#ifndef CPPHOMEWORKTEST_TESTCASE_H
#define CPPHOMEWORKTEST_TESTCASE_H
#include <sstream>
#include <string>
#include <iostream>

using namespace std;
class TestCase{
    string errorType;
    string output;
    int Fcount,//how many tests faiyeled
            Pcount;//how many testes passed
    ostream *err;//output
public:
    /*
     * basic constructor
     */
    TestCase(string arg, ostream& er);


    template <typename T> TestCase& check_equal(const T& a,const T& b){
        if(!(a==b)){
            ostringstream streamA, streamB;
            streamA<<a;
            streamB<<a;
            Fcount++;
            output += errorType +
                    ": Failure in test #"+
                    to_string(Pcount+Fcount)+
                    ": "+
                    streamA.str()+
                    " should equal "+
                    streamB.str()+
                    "!\n";
        }
        else Pcount++;
        return *this;

    }
    template <typename T> TestCase& check_different(const T& a,const T& b){
        if((a==b)){
            Fcount++;
            ostringstream streamA, streamB;
            streamA<<a;
            streamB<<a;
            Fcount++;
            output += errorType +
                      ": Failure in test #"+
                      to_string(Pcount+Fcount)+
                      ": "+
                      streamA.str()+
                      " should not equal "+
                      streamB.str()+
                      "!\n";        }
        else Pcount++;
        return *this;

    }
    template <typename T> TestCase& check_output(const T& a, string check){
        ostringstream streamA;
        streamA<<a;

        if(streamA.str().compare(check) != 0){
            Fcount++;
            output += errorType +
                      ": Failure in test #"+
                      to_string(Pcount+Fcount)+
                      ": "+
                      streamA.str()+
                      " string value should be "+
                      check+
                    " but is "+
                    streamA.str()+
                      "\n";
        }
        else Pcount++;
        return *this;
    }
    template <typename T,typename F,typename C> TestCase& check_function(const F& fun, const T& input,const C& check){

        if(fun(input) != check){
            Fcount++;
            ostringstream streamC, streamF;
            streamC<<check;
            streamF<<fun(input);
            output += errorType +
                      ": Failure in test #"+
                      to_string(Pcount+Fcount)+
                      ": Function should return "+
                      streamC.str()+
                      " but returned "+
                      streamF.str()+
                      "!\n";
        }
        else Pcount++;
        return *this;
    }
    void  print();


};
#endif //CPPHOMEWORKTEST_TESTCASE_H
