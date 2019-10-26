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
	int choice;
	cout<<setfill('+')<<setw(70)<<""<<"\n";
	cout<<setfill(' ')<<setw(53)<<"Welcome to Examination Grading System"<<"\n";
	cout<<setfill('+')<<setw(70)<<""<<"\n";
	
	do{
		cout<<right<<setfill(' ')<<setw(42)<<"Select Your Option:"<<"\n";
		cout<<left<<setfill(' ')<<setw(30)<<"1. Calculate SGPA";
		cout<<endl;
		cout<<left<<setfill(' ')<<setw(30)<<"2. Calculate CGPA";
		cout<<endl;
		cout<<left<<setfill(' ')<<setw(30)<<"3. Read Records From File";
		cout<<endl;
		cout<<left<<setfill(' ')<<setw(30)<<"4. Exit";
		cout<<"\n"<<endl;
		cout<<left<<setfill(' ')<<setw(30)<<"Your Choice: ";
		cin>>choice;
		switch(choice){
			case 1:{
				char ch1='Y', ch2;
				while (ch1=='Y' || ch1=='y'){
					cout<<"Entering Marks!"<<endl;
					cout<<"Write to File? (Y/N)"<<endl;
					cin>>ch2;
					if(ch2=='Y' || ch2=='y'){
						cout<<"Writing to file!"<<endl;
					}
					cout<<"Want to enter more data?(Y/N)"<<endl;
					cin>>ch1;
				}
				break;
				}
			case 2:
				cout<<"Calculating cgpa"<<endl;
				break;
			case 3:
				cout<<"reading from file"<<endl;
				break;		
		}
	}
	while(choice!=4);
	
}
