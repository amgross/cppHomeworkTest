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
    string* output;
    int count;
    TestCase():output(new string("")), count(0){

    };

    TestCase& checkEqual(T& a,T& b){
        if(!a==b){
            count++;
            output+= "\nTest "+(string)typeid(T).name()+" operators: Failure in test #"+to_string(count)+": "+quote(a)+" should equal "+quote(b)+"!";
        }
        return *this;

    }
    TestCase& check_different(T& a,T& b){
        if(a==b){
            count++;
            output+= "\nTest "+(string)typeid(T).name()+" operators: Failure in test #"+to_string(count)+": "+quote(a)+" should be different from "+quote(b)+"!";
        }
        return *this;

    }
    TestCase& check_output(T& a, string check){
        std::ostream stream(a);
        if(stream!=check){
            count++;
            output+= "\nTest "+(string)typeid(T).name()+" operators: Failure in test #"+to_string(count)+": the output from "+quote(a)+" should be equal "+check+"!";
        }
        return *this;
    }
    void  print(){
        cout<<output;
    }
//    .check_function(getNum, MyStruct(5), 5)     // Here there is a bug.
//    .check_function([](const MyStruct& s){return s.myNum();}, MyStruct(5), 5)


};
#endif //CPPHOMEWORKTEST_TESTCASE_H
