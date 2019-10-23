#include<iostream>
#include<fstream>
#include<string>
#include<iomanip> 
using namespace std;
class Student{
    protected:
    char name[20];
    string subject[8] = {"Probability and Statistics","Discrete Mathematics","Economics","Object Oriented Programming","Object Oriented Programming Lab","Data Structures and Algorithms","Data Structures and Algorithms lab","Principle of Digital Communication"};
    float sgpa,cgpa,marks[8];
    int rollno,credits[8],grade[8];
    public:
    void getInfo(){
        cout<<"Enter name : ";
        cin>>name;
        cout<<"Enter Roll No. : ";
        cin>>rollno;
    }
    void initCredit(){
	//lol
    	credits[0] =3;
    	credits[1] =3;
    	credits[2] =3;
    	credits[3] =3;
    	credits[4] =1;
    	credits[5] =4;
    	credits[6] =1;
    	credits[7] =4;

     }
    void initMarks(){
    	cout<<"Enter Marks as defined:"<<endl;
    	cout<<"Probability and Statistics: "<<endl;
    	marks[0]=getMarks();
    	cout<<"Discrete Mathematics: "<<endl;
    	marks[1]=getMarks();
    	cout<<"Economics: "<<endl;
    	marks[2]=getMarks();
    	cout<<"Object Oriented Programming: "<<endl;
    	marks[3]=getMarks();
    	cout<<"Data Structures and Analysis: "<<endl;
    	marks[5]=getMarks();
    	cout<<"Principle Of Digital Communication: "<<endl;
    	marks[7]=getMarks();
    	cout<<"Data Structures and Analysis Lab:"<<endl;
    	marks[6]=getLab();
    	cout<<"Object Oriented Programming Lab:"<<endl;
    	marks[4]=getLab();
    }
    float getLab(){
    	float midterm,labfile,viva,endterm;
    	try{
	    	cout<<"Enter Midsem Marks: ";
	    	cin>>midterm;
	    	if(midterm>20 || midterm <0 )
	    		throw midterm;
	    	cout<<"Enter Lab File Marks: ";
	    	cin>>labfile;
	    	cout<<"Enter Viva Marks: ";
	    	cin>>viva;
		cout<<"Enter Lab Exam Marks: ";    
		cin>>endterm;
	}
	catch (float x){  
	        cout << "Caught ";   
	        }
	return midterm+labfile+endterm+viva;
    }
    float getMarks(){
    	float midsem,internal,endsem,tot;
    	try{
    		jump:
	    	cout<<"Enter Midsem Marks: ";
	    	cin>>midsem;
	    	if(midsem>20 || midsem <0 )
		    		throw midsem;
	    	cout<<"Enter Internal Marks: ";
	    	cin>>internal;
	      	if(internal>30 || internal<0 )
		    		throw internal;
	    	cout<<"Enter EndSem Marks: ";
	    	cin>>endsem;
	    	if(endsem>50 || endsem<0 )
		    		throw endsem;
	    	tot = midsem + internal + endsem;
	    	}
	catch (float x)  {
	        cout << "Incorrect Range of marks Entered! "<<endl;
	        //This catch block breaks input operation..goto doesnt work , need to find solution.
	        }
    	return tot;
    	
    }
    void calcSgpa(){
        //TODO I really don't know how to calculate sgpa. HALP!
        float obcr=0;    
        int totcr=0;
	for(int i = 0;i<8;i++)
		totcr+=credits[i];
	for(int i =0;i<8;i++){
		if(marks[i]==100)
			grade[i]=10;
		else
			grade[i]=(marks[i]/10)+1;
		obcr+=grade[i]*credits[i];
		}
	/*cout<<"\n"<<obcr<<"\n";
	cout<<"\n"<<totcr<<"\n"; */
	sgpa=obcr/totcr;
    }
    void calcCgpa(){
        cgpa = (cgpa*2 + sgpa)/3.0;
    }
    void show(){
        cout<<"Name: "<<name<<endl;
        cout<<"Roll No."<<rollno<<endl;
        for(int i = 0;i<8;i++){
        	cout<<"Marks: "<<marks[i]<<endl;
	        cout<<"Grade: "<<grade[i]<<endl;
	        cout<<"\n";
	        }
	cout<<"SGPA = "<<fixed<<setprecision(2)<<sgpa<<endl;
    }
    friend void addToFile(const Student &);
    friend void readFromFile();
};
void addToFile(const Student &s){
    ofstream outFile("Student.json",ios::app | ios::binary);
    outFile.write((char *)& s, sizeof(s));
    outFile.close();
}
void readFromFile(){
    Student s;
    ifstream inFile("Student.json",ios::in | ios::binary);
    while (inFile.read((char *)&s,sizeof(s)))
    {
        s.show();
        cout<<endl<<"-----------------------------------"<<endl;
    }
    remove("Student.json");
    inFile.close();
}
int main(){
    int ch=1;
    remove("Student.json");
    while (ch==1)
    {
        Student s;
        s.initCredit();
        s.getInfo();
        s.initMarks();
        s.calcSgpa();
        s.show();
        addToFile(s);
        cout<<"Want to enter more data? 1/0"<<endl;
        cin>>ch;
    } 
    cout<<"---------------------------"<<endl;
    readFromFile();
    return 0;
}
