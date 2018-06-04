//
// Created by אריה גרוס on 04 יוני 2018.
//

#ifndef CPPHOMEWORKTEST_TESTCASE_H
#define CPPHOMEWORKTEST_TESTCASE_H
#include <typeinfo>
#include <string>
#include <iostream>

using namespace std;
template <typename T>class TestCase{
    string errorType;
    int count;
    ostream err;
    TestCase(string arg, ostream er){
        errorType = arg;
        err << er;
    }


    TestCase& checkEqual(T& a,T& b){
        if(!a==b){
            count++;
            err << errorType + " Failure in test #"+to_string(count)+": "+quote(a)+" should equal "+quote(b)+"!\n";
        }
        return *this;

    }
    TestCase& check_different(T& a,T& b){
        if(a==b){
            count++;
            err << errorType + " Failure in test #"+to_string(count)+": "+quote(a)+" should be different from "+quote(b)+"!\n";
        }
        return *this;

    }
    TestCase& check_output(T& a, string check){
        ostream stream(a);
        string str = a.str();
        if(str.compare(check) != 0){
            count++;
            err << errorType + " Failure in test #"+to_string(count)+": the output from "+quote(a)+" should be equal "+check+"!\n";
        }
        return *this;
    }
    TestCase& check_function(void fun(), T& input, T& check){

        if(fun(input) == check){
            count++;
            err << "Test " + (string)typeid(T).name() + " operators: Failure in test #" + to_string(count) + ": Function should return " + to_string(check) + " but returned  " + to_string(fun(input)) + "!\n";
        }
        return *this;
    }
    void  print(){
        cout<< err;
    }


};
#endif //CPPHOMEWORKTEST_TESTCASE_H
