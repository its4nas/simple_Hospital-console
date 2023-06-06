#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
using namespace std;


struct testType{
	string test_type;
	string labName;
	int startValue;
	int endValue;
	int unit;
};

struct location{
	string city;
	string street;
};

struct birthday{
	int day;
	int month;
	int year;
};

struct patient {
	int ID;
	string first_name;
	string last_name;
	string gender;
	string phoneNum;
	location address;
	int age;
};

struct medicine{
	int ID;
	string name;
	int price;
};

struct clinic{
	int ID;
	string name;
	int working_days;
};

struct doctor{
	int ID;
	string first_name;
	string last_name;
	birthday BD;
	int clinicID;
};

ifstream fin;
ofstream fout;

void login();
void first_window();


void patients_window();

void patientDocument_window();
// ------------------patient operations------------------
bool checkPatientID(int ID , vector<patient> patientVec);
bool checkPatientFN(string first_name, vector <patient> patientVec);
bool checkPatientLN(string last_name, vector <patient> patientVec);
void loadPatient(vector <patient> &patientVec);
void printAllPatients(vector <patient> patientVec);
void addPatient(vector <patient> &patientVec);
void alterFile(vector <patient> &patientVec);
void deletePatient(vector <patient> &patientVec);
void editPatient(vector <patient> &patientVec);
void searchPatientID(vector <patient> patientVec);
void searchPatientFN(vector <patient> patientVec);
void searchPatientLN(vector <patient> patientVec);
// ------------------------------------------------------
void treatments_window();
void recipe_window();
void testResult_window();


void laboratory_window ();
void printCats();
void printTest();


void medicines_window();


void clinics_window();


void doctorsFiles_window();


bool checkDoctorID(int ID, vector<doctor> doctorVec);

void loadDoctor(vector<doctor> &doctorVec);


bool checkCatName(string labCat, vector <string> catVec);

void loadCat(vector<string> &catVec);


bool checkTestType(string test_type, vector <testType> testTypeVec);

void loadTestType(vector<testType> &testTypeVec);


bool checkMedID(int ID, vector <medicine> medVec);

void loadMedicine(vector <medicine> &medVec);


vector <patient> patientVec;
vector <string> catVec;
vector <doctor> doctorVec;
vector <testType> testTypeVec;
vector <medicine> medVec;


main()
{
	login();
}

void login()
{
	start:	system("cls");
	fin.open("login.txt");
	string a,b;
	fin>>a;
	cout<<"Enter username: ";
	cin>>b;
	
	string x,y;
	fin>>x;
	cout<<"Enter password: ";
	cin>>y;
	fin.close();
	fin.clear();  // to start from the beginning of file
	
	if(a==b && x==y)
	{
		loadPatient(patientVec);
		loadDoctor(doctorVec);
		loadCat(catVec);
		loadTestType(testTypeVec);
		loadMedicine(medVec);
		first_window();
	}
	else
	{
		goto start;
	}
}

void first_window()
{
	start:	system("cls");
	cout<<"1-Patients\n2-Laboratory\n3-Medicines\n4-Clinics\n5-Doctors file\n6-Exit\n";
	int a;
	cin>>a;
	switch(a)
	{
		case 1: patients_window(); break;
		case 2: laboratory_window(); break;
		case 3: medicines_window(); break;
		case 4: clinics_window(); break;
		case 5: doctorsFiles_window(); break;
		case 6: exit(1); break;
		default: goto start; break;
	}
}

void patients_window()
{
	start: system("cls");
	cout<<"1-Patient document\n2-Treatments\n3-Recipe\n4-Test Result\n5-Back\n";
	int a;
	cin>>a;
	switch(a)
	{
		case 1: patientDocument_window(); break;
		case 2: treatments_window(); break;
		case 3: recipe_window(); break;
		case 4: testResult_window(); break;
		case 5: first_window(); break;
		default: goto start; break;
	}
}

void patientDocument_window()
{
	start: system("cls");
	cout<<"1-Patients information\n2-Add new patient\n3-Delete Patient *\n4-Edit patient info *\n5-Search by id\n6-Srarch by first name\n7-Search by last name\n8-Back\n";
	int a;
	cin>>a;
	switch(a)
	{
		case 1: printAllPatients(patientVec); break;
		case 2: addPatient(patientVec); break;
		case 3: deletePatient(patientVec); break;
		case 4: editPatient(patientVec); break;
		case 5: searchPatientID(patientVec); break;
		case 6: searchPatientFN(patientVec); break;
		case 7: searchPatientLN(patientVec); break;
		case 8: patients_window(); break;
		default: goto start; break;
	}
}

void treatments_window()
{
	start: system("cls");
	cout<<"Enter patient ID: ";
	int pID;
	cin>>pID;    //then check if it exists
	if(!checkPatientID(pID, patientVec))
	{
		cout<<"Patient doesn't exist. \nPress X to enter patient ID again.";
		char a;
		a=getch();
		if(a=='x' || a=='X')
		{
			goto start;
		}
		else
		patients_window();
	}
	
	cout<<"Enter doctor ID: ";
	int dID;
	cin>>dID;    // then check if it exists
	if(!checkDoctorID(dID, doctorVec))
	{
		cout<<"Doctor doesn't exist. \nPress X to enter information again.";
		char a;
		a=getch();
		if(a=='x' || a=='X')
		{
			goto start;
		}
		else
		patients_window();
	}
	
	cout<<"Enter lab category: ";
	string labCat;
	cin.ignore();
	getline(cin,labCat); //then check if it exists
	if(!checkCatName(labCat, catVec))
	{
		cout<<"Catagory doesn't exist. \nPress X to enter information again.";
		char a;
		a=getch();
		if(a=='x' || a=='X')
		{
			goto start;
		}
		else
		patients_window();
	}
	
	
	cout<<"Enter the test type: ";
	string test_type;
	getline(cin, test_type); //then check if it exists
	if(!checkTestType(test_type, testTypeVec))
	{
		cout<<"Test Type doesn't exist doesn't exist. \nPress X to enter information again.";
		char a;
		a=getch();
		if(a=='x' || a=='X')
		{
			goto start;
		}
		else
		patients_window();
	}
	
	cout<<"Enter the date of the treatment: ";
	string DATE;
	getline(cin, DATE);
	
	cout<<"Enter the diagnose information: ";
	string diaInfo;
	getline (cin, diaInfo);
	
	
	fout.open("treatments.txt", ios::app);
	fout<<"Patient ID: "<<pID<<"\nDoctor ID: "<<dID<<"\nLab catagory: "<<labCat<<"\nTest Type: "<<test_type<<"\nDate: "<<DATE<<"\nDagnose information: "<<diaInfo<<"\n\n";
	fout.close();
	//Then add all the pID & dID & labCat & testType & DATE & diaInfo to a file called treatments
	patients_window();
	
}




void laboratory_window()
{
	start: system("cls");
	cout<<"1-Category\n2-Test type\n3-Back\n";
	int a;
	cin>>a;
	switch(a)
	{
		case 1: printCats(); break;
		case 2: printTest(); break;
		case 3: first_window(); break;
		default: goto start; break;
	}
}


// -----------------------------patient operations----------------------------------
bool checkPatientID(int ID , vector<patient> patientVec)
{
	for(int i=0; i< patientVec.size(); i++)
	{
		if(patientVec[i].ID==ID)
		return true;
	}
	return false;
}


bool checkPatientFN(string first_name, vector<patient> patientVec)
{
	for(int i=0; i<patientVec.size(); i++)
	{
		if(patientVec[i].first_name==first_name)
		return true;
	}
	return false;
}


bool checkPatientLN(string last_name, vector<patient> patientVec)
{
	for(int i=0; i<patientVec.size(); i++)
	{
		if(patientVec[i].last_name==last_name)
		return true;
	}
	return false;
}


void printAllPatients(vector <patient> patientVec)
{
	system("cls");
	for(int i = 0; i < patientVec.size(); i++)
	{
		cout<<patientVec[i].ID<<" "<<patientVec[i].first_name<<" "<<patientVec[i].last_name<<" "
			<<patientVec[i].gender<<" "<<patientVec[i].phoneNum<<" "<<patientVec[i].address.city<<" "
			<<patientVec[i].address.street<<" "<<patientVec[i].age<<"\n\n";
	}
	char a;
	cout<<"Press any button to go back";
	if(a=getch())
	{
		patientDocument_window();
	}
}


void loadPatient(vector<patient> &patientVec)
{
	fin.clear();
	fin.open("patient_info.txt");
	if(!fin)
	{
		cerr<<"File doesn't exist."<<endl;
		exit(EXIT_FAILURE);
	}
	
	int ID;
	string first_name;
	string last_name;
	string gender;
	string phoneNum;
	location address;
	int age;
	
	for(int i=0; !fin.eof(); i++)
	{
		fin>>ID>>first_name>>last_name>>gender>>phoneNum>>address.city>>address.street>>age;
		patient p;
		p.ID=ID;
		p.first_name=first_name;
		p.last_name=last_name;
		p.gender=gender;
		p.phoneNum=phoneNum;
		p.address.city=address.city;
		p.address.street=address.street;
		p.age=age;
		
		patientVec.push_back(p);
	}
	fin.close();
}


void addPatient(vector <patient> &patientVec)
{
	start: system("cls");
	patient p;
	cout<<"Enter patient ID: ";
	cin>>p.ID;
	if(checkPatientID(p.ID, patientVec))
	{
		cout<<"This ID already exists.\nPress X to enter ID again.";
		char a=getch();
		if(a=='x')
		goto start;
		else
		patientDocument_window();
	}
	cout<<"\nEnter patient first name: ";
	cin>>p.first_name;
	cout<<"\nEnter patient last name: ";
	cin>>p.last_name;
	cout<<"\nEnter patient gender: ";
	cin>>p.gender;
	cout<<"\nEnter patient phone number: ";
	cin>>p.phoneNum;
	cout<<"\nEnter patient city: ";
	cin>>p.address.city;
	cout<<"\nEnter patient street: ";
	cin>>p.address.street;
	cout<<"\nEnter patient age: ";
	cin>>p.age;
	
	fout.open("patient_info.txt", ios::app);
	
	fout<<p.ID<<" "<<p.first_name<<" "<<p.last_name<<" "<<p.gender<<" "<<p.phoneNum<<" "
		<<p.address.city<<" "<<p.address.street<<" "<<p.age<<endl;
		
	fout.close();	
	
	cout<<"\n\nPatient has been added.\nPress any key to go back.";
	char a;
	if(a=getch())
	{
		patientDocument_window();
	}
}



void deletePatient(vector <patient> &patientVec)
{
	system("cls");
	cout<<"What's the ID of the patient you want to delete? ";
	int ID;
	cin>>ID;
	if(checkPatientID(ID, patientVec))
	{
		for(int i=0; i < patientVec.size(); i++)
		{
			if(patientVec[i].ID==ID)
			{
				patientVec.erase(patientVec.begin()+i);
				cout<<"deleted";
				break;
			}
		}
		alterFile(patientVec);
		loadPatient(patientVec);
	}
}


void editPatient(vector <patient> &patientVec)
{
	start: system("cls");
	cout<<"What's the ID of the patient you want to edit? ";
	int ID;
	cin>>ID;
	if (checkPatientID(ID, patientVec))
	{
		patient s;
		cout<<"Enter your new ID: ";
		cin>>s.ID;
		cout<<"Enter your new first name: ";
		cin>>s.first_name;
		cout<<"Enter your new last name: ";
		cin>>s.last_name;
		cout<<"Enter your new gender: ";
		cin>>s.gender;
		cout<<"Enter your new phone number: ";
		cin>>s.phoneNum;
		cout<<"Enter your new city: ";
		cin>>s.address.city;
		cout<<"Enter your new street: ";
		cin>>s.address.street;
		cout<<"Enter your new age: ";
		cin>>s.age;
		
		for(int i=0; i< patientVec.size(); i++)
		{
			if (patientVec[i].ID==ID)
			{
				patientVec.erase(patientVec.begin()+i);
				patientVec.push_back(s);
				break;
			}
		}
		alterFile(patientVec);
	}
	else
	{
		cout<<"ID not found.\nPress X to enter ID again.\n";
		char a= getch();
		
		if(a=='x')
		{
			goto start;
		}
	}
	patientDocument_window();
}



void searchPatientID(vector <patient> patientVec)
{
	system("cls");
	start: cout<<"What's the ID? ";
	int ID;
	cin>>ID;
	if(checkPatientID(ID, patientVec))
	{
		for (int i=0; i<patientVec.size(); i++)
		{
			if(ID==patientVec[i].ID)
			{
				cout << "Id : "<<patientVec[i].ID<<endl
                   << "First name : "<<patientVec[i].first_name<<endl
				   << "Last name : "<<patientVec[i].last_name<<endl
                   << "Gender : "<<patientVec[i].gender<<endl
                   << "Phone : "<<patientVec[i].phoneNum<<endl
                   << "City : "<<patientVec[i].address.city<<endl
                   << "Street : "<<patientVec[i].address.street<<endl
                   << "Age : "<<patientVec[i].age<<endl;
                   break;
			}
		}
	}
	else
	{
		cout<<"ID not found.\nPress X to enter ID again.\n";
		char a= getch();
		
		if(a=='x')
		{
			goto start;
		}
	}
	char a;
	cout<<"Press any key to go back.";
	if(a=getch())
	patientDocument_window();
}



void searchPatientFN(vector <patient> patientVec)
{
	system("cls");
	start: cout<<"What's the first name? ";
	string first_name;
	cin>>first_name;
	if(checkPatientFN(first_name, patientVec))
	{
		for (int i=0; i<patientVec.size(); i++)
		{
			if(first_name==patientVec[i].first_name)
			{
				cout << "Id : "<<patientVec[i].ID<<endl
                   << "First name : "<<patientVec[i].first_name<<endl
				   << "Last name : "<<patientVec[i].last_name<<endl
                   << "Gender : "<<patientVec[i].gender<<endl
                   << "Phone : "<<patientVec[i].phoneNum<<endl
                   << "City : "<<patientVec[i].address.city<<endl
                   << "Street : "<<patientVec[i].address.street<<endl
                   << "Age : "<<patientVec[i].age<<endl<<endl<<endl;
			}
		}
	}
	else
	{
		cout<<"ID not found.\nPress X to enter ID again.\n";
		char a= getch();
		
		if(a=='x')
		{
			goto start;
		}
	}
	char a;
	cout<<"Press any key to go back.";
	if(a=getch())
	patientDocument_window();
}



void searchPatientLN(vector <patient> patientVec)
{
	system("cls");
	start: cout<<"What's the last name? ";
	string last_name;
	cin>>last_name;
	if(checkPatientLN(last_name, patientVec))
	{
		for (int i=0; i<patientVec.size(); i++)
		{
			if(last_name==patientVec[i].last_name)
			{
				cout << "Id : "<<patientVec[i].ID<<endl
                   << "First name : "<<patientVec[i].first_name<<endl
				   << "Last name : "<<patientVec[i].last_name<<endl
                   << "Gender : "<<patientVec[i].gender<<endl
                   << "Phone : "<<patientVec[i].phoneNum<<endl
                   << "City : "<<patientVec[i].address.city<<endl
                   << "Street : "<<patientVec[i].address.street<<endl
                   << "Age : "<<patientVec[i].age<<endl<<endl<<endl;
			}
		}
	}
	else
	{
		cout<<"ID not found.\nPress X to enter ID again.\n";
		char a= getch();
		
		if(a=='x')
		{
			goto start;
		}
	}
	char a;
	cout<<"Press any key to go back.";
	if(a=getch())
	patientDocument_window();
}



void alterFile(vector <patient> &patientVec)
{
	fout.open("patient_info.txt", ios::out);
	
	for(int i=0; i < patientVec.size(); i++)
	{
	fout<<patientVec[i].ID<<" "<<patientVec[i].first_name<<" "<<patientVec[i].last_name<<" "<<patientVec[i].gender
		<<" "<<patientVec[i].phoneNum<<" "<<patientVec[i].address.city<<" "<<patientVec[i].address.street<<" "
		<<patientVec[i].age<<endl;
	}
	
	fout.close();
}
// ---------------------------------------------------------------------------------



void printCats()
{
	system("cls");
	fin.clear();
	fin.open("cat.txt");
	string a;
	while(!fin.eof())
	{
		fin>>a;
		cout<<a<<endl;
	}
	fin.close();
	char b;
	cout<<"\nPress any key to go back.";
	if(b=getch())
	first_window();
}


void printTest()
{
	system("cls");
	fin.clear();
	fin.open("testType.txt");
	testType a;
	while(!fin.eof())
	{
		fin>>a.test_type>>a.labName>>a.startValue>>a.endValue>>a.unit;
		cout<<a.test_type<<" "<<a.labName<<" "<<a.startValue<<" "<<a.endValue<<" "<<a.unit<<endl;
	}
	fin.close();
	char b;
	cout<<"\nPress any key to go back.";
	if(b=getch())
	first_window();
}


void medicines_window()
{
	system("cls");
	fin.clear();
	fin.open("medicines.txt");
	medicine a;
	while(!fin.eof())
	{
		fin>>a.ID>>a.name>>a.price;
		cout<<a.ID<<" "<<a.name<<" "<<a.price<<endl;
	}
	fin.close();
	char b;
	cout<<"\nPress any key to go back.";
	if(b=getch())
	first_window();
}



void clinics_window()
{
	system("cls");
	fin.clear();
	fin.open("clinics.txt");
	clinic a;
	while(!fin.eof())
	{
		fin>>a.ID>>a.name>>a.working_days;
		cout<<a.ID<<" "<<a.name<<" "<<a.working_days<<endl;
	}
	fin.close();
	char b;
	cout<<"\nPress any key to go back.";
	if(b=getch())
	first_window();
}



void doctorsFiles_window()
{
	system("cls");
	fin.clear();
	fin.open("doctors.txt");
	doctor a;
	while(!fin.eof())
	{
		fin>>a.ID>>a.first_name>>a.last_name>>a.BD.day>>a.BD.month>>a.BD.year>>a.clinicID;
		cout<<"ID: "<<a.ID<<"\nFirst name: "<<a.first_name<<"\nLast name: "<<a.last_name
			<<"\nDay of birth: "<<a.BD.day<<"\nMonth of birth: "<<a.BD.month
			<<"\nYear of birth: "<<a.BD.year<<"\nClinic : "<<a.clinicID<<"\n\n";
	}
	fin.close();
	char b;
	cout<<"\nPress any key to go back.";
	if(b=getch())
	first_window();
}



bool checkDoctorID(int ID, vector <doctor> doctorVec)
{
	for(int i=0; i< doctorVec.size(); i++)
	{
		if(doctorVec[i].ID==ID)
		return true;
	}
	return false;
}



void loadDoctor(vector<doctor> &doctorVec)                                              
{                                                                                           
	fin.clear();                                                                               
	fin.open("doctors.txt");                                                              
	if(!fin)                                                                                   
	{                                                                                          
		cerr<<"File doesn't exist."<<endl;                                                        
		exit(EXIT_FAILURE);                                                                       
	}                                                                                          
	                                                                                           
	int ID;                                                                                    
	string first_name;                                                                         
	string last_name;                                                                                                                                                                                                                           
	birthday BD;                                                                          
	int clinicID;                                                                                   
	                                                                                           
	for(int i=0; !fin.eof(); i++)                                                              
	{                                                                                          
		fin>>ID>>first_name>>last_name>>BD.day>>BD.month>>BD.year>>clinicID;      
		doctor d;                                                                                
		d.ID=ID;                                                                                  
		d.first_name=first_name;                                                                  
		d.last_name=last_name;                                                                    
		d.BD.day=BD.day;                                                          
		d.BD.month=BD.month;                                                      
		d.BD.year=BD.year;                                                        
		d.clinicID=clinicID;                                                         
		                                                                          
		                                                                          
		                                                                          
		                                                                          
		                                                                                          
		doctorVec.push_back(d);                                                                  
	}                                                                                          
	fin.close();                                                                               
}                                                                            



void loadCat(vector<string> &catVec)                                              
{                                                                           
	fin.clear();                                                               
	fin.open("cat.txt");                                                   
	if(!fin)                                                                   
	{                                                                          
		cerr<<"File doesn't exist."<<endl;                                        
		exit(EXIT_FAILURE);                                                       
	}                                                                          
	                                                                           
	string name;                                                   	                                                                           
	for(int i=0; !fin.eof(); i++)                                              
	{                                                                          
		fin>>name;                                                                    
		catVec.push_back(name);                                                   
	}                                                                          
	fin.close();                                                               
}   

bool checkCatName(string labCat, vector <string> catVec)
{
	for(int i=0; i< catVec.size(); i++)
	{
		if(catVec[i]==labCat)
		return true;
	}
	return false;
}


bool checkTestType(string test_type, vector <testType> testTypeVec)
{
	for(int i=0; i< testTypeVec.size(); i++)
	{
		if(testTypeVec[i].test_type==test_type)
		return true;
	}
	return false;
}


void loadTestType(vector<testType> &testTypeVec)                                              
{                                                                                           
	fin.clear();                                                                               
	fin.open("testType.txt");                                                              
	if(!fin)                                                                                   
	{                                                                                          
		cerr<<"File doesn't exist."<<endl;                                                        
		exit(EXIT_FAILURE);                                                                       
	}                                                                                          
	                                                                                           
	string test_type;                                                                                    
	string labName;                                                                         
	int startValue;                                                                                                                                                                                                                           
	int endValue;                                                                          
	int unit;                                                                                   
	                                                                                           
	for(int i=0; !fin.eof(); i++)                                                              
	{                                                                                          
		fin>>test_type>>labName>>startValue>>endValue>>unit;      
		testType t;
		t.test_type=test_type;                                                                                
		t.labName=labName;                                                                                  
		t.startValue=startValue;                                                                  
		t.endValue=endValue;                                                                    
		t.unit=unit;                                                          
		                                                                          
		                                                                          
		                                                                          
		                                                                          
		                                                                                          
		testTypeVec.push_back(t);                                                                  
	}                                                                                          
	fin.close();                                                                               
}                    

void recipe_window()
{
	start: system("cls");
	cout<<"Enter patient ID: ";
	int pID;
	cin>>pID;    //then check if it exists
	if(!checkPatientID(pID, patientVec))
	{
		cout<<"Patient doesn't exist. \nPress X to enter patient ID again.";
		char a;
		a=getch();
		if(a=='x' || a=='X')
		{
			goto start;
		}
		else
		patients_window();
	}
	
	cout<<"Enter doctor ID: ";
	int dID;
	cin>>dID;    // then check if it exists
	if(!checkDoctorID(dID, doctorVec))
	{
		cout<<"Doctor doesn't exist. \nPress X to enter information again.";
		char a;
		a=getch();
		if(a=='x' || a=='X')
		{
			goto start;
		}
		else
		patients_window();
	}
	
	cout<<"How many medicines you will add: ";
	int N_medic;
	cin>>N_medic;
	
	int medIDs[N_medic];
	for(int i=0; i<N_medic; i++)
	{
		cout<<"Enter the ID of the medicine number "<<i+1<<": ";
		cin>>medIDs[i];
		//checkMedID(medIDs[i],medVec);
	}
	
}         

void testResult_window()
{
	start: system("cls");
	cout<<"Enter patient ID: ";
	int pID;
	cin>>pID;    //then check if it exists
	if(!checkPatientID(pID, patientVec))
	{
		cout<<"Patient doesn't exist. \nPress X to enter patient ID again.";
		char a;
		a=getch();
		if(a=='x' || a=='X')
		{
			goto start;
		}
		else
		patients_window();
	}
	
	cout<<"Enter doctor ID: ";
	int dID;
	cin>>dID;    // then check if it exists
	if(!checkDoctorID(dID, doctorVec))
	{
		cout<<"Doctor doesn't exist. \nPress X to enter information again.";
		char a;
		a=getch();
		if(a=='x' || a=='X')
		{
			goto start;
		}
		else
		patients_window();
	}
	
	cout<<"Enter the test type: ";
	string test_type;
	cin.ignore();
	getline(cin, test_type); //then check if it exists
	if(!checkTestType(test_type, testTypeVec))
	{
		cout<<"Test Type doesn't exist doesn't exist. \nPress X to enter information again.";
		char a;
		a=getch();
		if(a=='x' || a=='X')
		{
			goto start;
		}
		else
		patients_window();
	}
	
	cout<<"Enter the date of test result: ";
	string DATE;
	getline(cin,DATE);
	
	
	cout<<"Enter the result of the test: ";
	string RESULT;
	getline(cin, RESULT);
	
	fout.open("testResult", ios::app);
	fout<<"Patient ID: "<<pID<<"\nDoctor ID: "<<dID<<"\nTest Type: "<<test_type<<"\nDate: "<<DATE<<"\ntest_result: "<<RESULT<<"\n\n";
	fout.close();
	
	patients_window();
}              


void loadMedicine(vector <medicine> &medVec)
{
	fin.clear();                                                                               
	fin.open("medicines.txt");                                                              
	if(!fin)                                                                                   
	{                                                                                          
		cerr<<"File doesn't exist."<<endl;                                                        
		exit(EXIT_FAILURE);                                                                       
	}                                                                                          
	                                                                                           
	int ID;                                                                                    
	string name;                                                                        
	int price;                                                                                   
	                                                                                           
	for(int i=0; !fin.eof(); i++)                                                              
	{                                                                                          
		fin>>ID>>name>>price;      
		medicine m;                                                                                
		m.ID=ID;                                                                                  
		m.name=name;
		m.price=price;    
	
		medVec.push_back(m);
	}
	fin.close();
}     

bool checkMedID(int ID, vector <medicine> medVec)
{
	for(int i=0; i< medVec.size(); i++)
	{
		if(medVec[i].ID==ID)
		return true;
	}
	return false;
}