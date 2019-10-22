#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Student{
    string name,subject[9] = {"Probability and Statistics","Discrete Mathematics","Economics","Object Oriented Programming","Object Oriented Programming Lab","Data Structures and Algorithms","Data Structures and Algorithms lab","Principle of Digital Communication"};
    float marks[8],sgpa,cgpa,credits[8];
    public:
    void getInfo(){
        for(int i=0;i<8;i++){
            cout<<"Enter marks for subject "<<subject[i]<<endl;
            cin>>marks[i];
        }
    }
    void calcSgpa(){
        //TODO I really don't know how to calculate sgpa. HALP!
    }
    void calcSgpa(){
        cgpa = (cgpa*2 + sgpa)/3.0;
    }
    string retName(){
        return name;
    }
};