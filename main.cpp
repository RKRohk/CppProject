#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Student{
    protected:
    string name,subject[9] = {"Probability and Statistics","Discrete Mathematics","Economics","Object Oriented Programming","Object Oriented Programming Lab","Data Structures and Algorithms","Data Structures and Algorithms lab","Principle of Digital Communication"};
    float marks,sgpa,cgpa,credits[8];
    public:
    void getInfo(){
        cout<<"Enter name"<<endl;
        getline(cin,name);
        cout<<"Enter marks"<<endl; //This has to be converted to loop, I just did this to try it
        cin>>marks; 
    }
    void calcSgpa(){
        //TODO I really don't know how to calculate sgpa. HALP!
    }
    void calcCgpa(){
        cgpa = (cgpa*2 + sgpa)/3.0;
    }
    void show(){
        cout<<"Name: "<<name<<endl;
        cout<<"MARKS:"<<marks<<endl;
    }
};
int main(){
    ofstream ofile;
    ofile.open("StudentsTest.txt",ios::app);    
    int ch=1;
    while (ch)
    {
        Student s;
        s.getInfo();
        s.show();
        ofile.write((char *) & s, sizeof(s));
        cout<<"Want to enter more data? Y/N"<<endl;
        cin>>ch;
    }    
    ifstream ifile("StudentsTest.txt",ios::in);
    Student stud;
    ifile.read((char *)&stud,sizeof(stud));
    stud.show();
    ofile.close();
    ifile.close();
    remove("StudentsTest.txt");
    return 0;
}