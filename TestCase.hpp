//
// Created by אריה גרוס on 04 יוני 2018.
//

#ifndef CPPHOMEWORKTEST_TESTCASE_H
#define CPPHOMEWORKTEST_TESTCASE_H
#include <typeinfo>
#include <string>
#include <iostream>

using namespace std;
class TestCase{
    string errorType;
    string output;
    int Fcount, Pcount;
    ostream *err;
public:
    TestCase(string arg, ostream& er):errorType (arg),Fcount(0),Pcount(0){//},err(er){
        err = &er;
        output="";
    }


    template <typename T> TestCase& check_equal(const T& a,const T& b){
        //because the == operator in erel test is'nt const!!!
        T temp = a;
        if(!(temp==b)){
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
        T temp = a;
        if(!(temp!=b)){
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
            //err << "Test " + (string)typeid(T).name() + " operators: Failure in test #" + to_string(count) + ": Function should return " + to_string(check) + " but returned  " + to_string(fun(input)) + "!\n";
        }
        else Pcount++;
        return *this;
    }
    void  print(){
        output+=errorType+
            ": "+
                to_string(Fcount)+
                " failed, "+
                to_string(Pcount)+
                " passed, "+
                to_string(Fcount+Pcount)+
                " total.\n---\n";
        cout<< output;
    }


};
#endif //CPPHOMEWORKTEST_TESTCASE_H
