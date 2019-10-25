#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

void show(){
	string name;
	int rollno;
	cout<<"Enter name : ";
        cin>>name;
        cout<<"Enter Roll No. : ";
        cin>>rollno;
	cout<<setfill('+')<<setw(50)<<""<<"\n";
	cout<<setfill(' ')<<setw(46)<<"KALINGA INSTITUTE OF INDUSTRIAL TECHNOLOGY"<<"\n";
	cout<<setfill('-')<<setw(50)<<""<<"\n";
	cout<<left<<setfill(' ')<<setw(9)<<"Name ";cout<<":";
	cout<<left<<setfill(' ')<<setw(50)<<name<<endl;
	cout<<left<<setfill(' ')<<setw(10)<<"Roll No. :";
	cout<<left<<setfill(' ')<<setw(50)<<rollno<<endl;
	cout<<setfill('-')<<setw(50)<<""<<"\n";
	cout<<right<<setfill(' ')<<setw(36)<<"Semester Grade Report"<<"\n";
	cout<<left<<setfill(' ')<<setw(30)<<"Subject Name:";
	cout<<left<<setfill(' ')<<setw(10)<<"Marks:";
	cout<<left<<setfill(' ')<<setw(10)<<"Grade :"<<endl;
	
}

int main(){
	show();
}
