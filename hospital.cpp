#include<iostream>
using namespace std;
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<stdio.h>
#include<windows.h>


class hospital
{
	char pt_name[50]; //for Patients 
	char pt_addr[50];
	unsigned long long pt_pno;
	char pt_diag[50];
	int pt_room;
	int pt_doa_dd;
	int pt_doa_mm;
	int pt_doa_yy;
	
	int pt_total;
	
	int dt_id;
	char dt_name[50]; //for Doctors
	unsigned long long dt_pno;
	char dt_vt[25];
	char dt_spec[50];
	
	int pg_id;        //Pathology lab
	char pg_type[50];
	int pg_dor_dd;
	int pg_dor_mm;
	int pg_price;
	char pg_r[10];
	

	int ps_password;
	int ps_name;
	
	
	public:
		
			void pt_add();	//name,add....room no
			void pt_display();//display all patient variables
			void pt_edit();//edit patient parameters
			void pt_delete();//remove patients
			
			void pt_billing();//initiate billing 
			
			void dt_add();	//name,add....
			void dt_display();//display all doctor variables
			void dt_edit();//edit doctor parameters
			void dt_delete();//remove doctors
			
			void pg_add();	//name,sample type
			void pg_display();//display all pathology variables
			void pg_edit();//edit sample parameters
			void pg_delete();//remove sample
		
			
			void ps_add();	//name,price
			void ps_edit();//edit medicine parameters
			
			void login();
			
			void mainmenu();
		
};

void hospital::mainmenu()
{
 	int choice;
	system("cls");
	
	cout<<"\n\t\t\t\t";
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 142);
 	cout<<"Welcome to PRRH Hospital";
 	cout<<"\n\t\t\t\t";
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 143);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~                        ";
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 178);
 	cout<<"\n\n\t\t\t  Please select your prefered Option                    ";
 	cout<<"\n\n\t\t\t\t1.Patient details.                              ";
 	cout<<"\n\n\t\t\t\t2.Doctor details.                               ";
 	cout<<"\n\n\t\t\t\t3.Pathology Department.                         ";
 	
 	cin>>choice;
 	switch(choice)
 	{
 		case 1:int choice1;
 				system("cls");
		 	   cout<<"\n\t1.Enter details";
 			   cout<<"\n\n\t2.Display details";
 			   cout<<"\n\n\t3.Edit details";
 			   cout<<"\n\n\t4.Delete details";
 			   SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 188);
 			   cout<<"\n\n\t5.Generate invoice";
 			   cin>>choice1;
 			   switch(choice1)
 			   {
						case 1:pt_add();
							   break;
						case 2:pt_display();
							   break;
					    case 3:pt_edit();
						       break;
					    case 4:pt_delete();
						       break;
						case 5:pt_billing();
						       break;
				}
				break;
		case 2:	int choice2;
				system("cls");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 185);
		   	    cout<<"\n\t1.Enter details";
 		   		cout<<"\n\n\t2.Display details";
 		   		cout<<"\n\n\t3.Edit details";
 		   		cout<<"\n\n\t4.Delete details";
 		   		
 		   		cin>>choice2;
 		   		switch(choice2)
 		   		{
					case 1:dt_add();
						   break;
					case 2:dt_display();
						   break;
				    case 3:dt_edit();
					       break;
				    case 4:dt_delete();
					       break;
						
				}
				break;
		case 3:	int choice3;
				system("cls");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 180);
		   	    cout<<"\n\t1.Enter details";
 		   		cout<<"\n\n\t2.Display details";
 		   		cout<<"\n\n\t3.Edit details";
 		   		cout<<"\n\n\t4.Delete details";
 		   		cin>>choice3;
 		   		switch(choice3)
 		   		{
					case 1:pg_add();
						   break;
					case 2:pg_display();
						   break;
				    case 3:pg_edit();
					       break;
				    case 4:pg_delete();
					       break;
					
				}
				break;
		
	}
}
void hospital::login()
{	int password;
	int p=0;
	cout<<"Username:Receptionist";
	cout<<"Enter password:";
	cin>>password;
	  
    ifstream infile;
    infile.open("pas.dat",ios::app);
    
    while(infile.read((char *)this,sizeof(hospital)))
    {
    	
    	if(password==ps_password)
    	{
    		p=1;    	
		}
		
	}
infile.close();
if(p==1) mainmenu();	
int mm;
if(p!=1) cout<<"Patient not registered";
cout<<"Press 0 to go add user";
cin>>mm;
if(mm==0) ps_add();	
}

void hospital::ps_add()
{	

	
		system("cls");
		int password=0;
		int c=0;
		
		cout<<"Enter Password:";
		cin>>ps_password;
		ofstream outfile;
    	outfile.open("pas.dat",ios::app);
    	outfile.write((char *)this,sizeof(hospital));
    	outfile.close();
		cout<<"User Registered";
		
		
int mm;
cout<<"Press 0 to go back to login";
cin>>mm;
if(mm==0) login();    
}


void hospital::pt_add()
{	

	
		system("cls");
		
		int roomno=0;
		int c=0;
		
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 185);
		cout<<"\n\tEnter Room No.: ";
		cin>>roomno;
		cin.ignore();
		ifstream fin("patient.dat",ios::app);
		while(!fin.eof())
		{	fin.read((char*)this,sizeof(hospital));
			if(pt_room==roomno)
			{	cout<<"\n\n\tRoom already booked";
				c=0;
				break;
			}
			else
			{
				c=1;
			}
		}
		fin.close();
		
		if(c==1)
		{		
				cout<<"\n\n\tPlease Confirm your Room no. ";
				cin>>pt_room;
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 185);
				fflush(stdin);
				cout<<"\n\n\tEnter Patient Name: ";
				cin.getline(pt_name,sizeof(pt_name));
				fflush(stdin);
				cout<<"\n\n\tEnter Patient Address: ";
				cin.getline(pt_addr,sizeof(pt_addr));
				fflush(stdin);
				cout<<"\n\n\tEnter Diagnosis: ";
				cin.getline(pt_diag,sizeof(pt_diag));
				fflush(stdin);
				cout<<"\n\n\tEnter phone Number";
				cin>>pt_pno;
				cin.ignore();
				cout<<"\n\n\tEnter Date of Arrival(DD/MM/YYYY) ";
				cin>>pt_doa_dd;
				cin>>pt_doa_mm;
				cin>>pt_doa_yy;
				
				ofstream outfile;
    			outfile.open("patient.dat",ios::app);
    			outfile.write((char *)this,sizeof(hospital));
    			outfile.close();
    			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 178);
				cout<<"\n\n\tPatient Registered";
		}
int mm;
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 190);
cout<<"\n\n\t Press 0 to go back to the Main Menu ";
cin>>mm;
if(mm==0) mainmenu();    
}

void hospital::pt_display()
{	int roomno;
	int p=0;
	system("cls");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 185);
	cout<<"Enter room no:";
	cin>>roomno;
	  
    ifstream infile;
    infile.open("patient.dat",ios::app);
    
    while(infile.read((char *)this,sizeof(hospital)))
    {
    	
    	if(roomno==pt_room)
    	{	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 178);
    		cout<<"\n\n\tPatient Name:  "<<pt_name<<endl;
			cout<<"\n\n\tPatient Address:  "<<pt_addr<<endl;
			cout<<"\n\n\tPhone Number:  "<<pt_pno<<endl;
			cout<<"\n\n\tRoom No.:  "<<pt_room<<endl;
			cout<<"\n\n\tDiagnosis:  "<<pt_diag<<endl;
			cout<<"\n\n\tDate of Arrival:  "<<pt_doa_dd<<"/"<<pt_doa_mm<<"/"<<pt_doa_yy<<endl;
			p=1;
		}
		
	}
infile.close();	
int mm;
if(p!=1) cout<<"Patient not registered";
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 190);
cout<<"\n\n\t Press 0 to go back to the Main Menu ";
cin>>mm;
if(mm==0) mainmenu();	
}

void hospital::pt_edit()
{
	int roomno;
	int p=0;
	system("cls");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 185);
	cout<<"\n\n\tEnter room no:";
	cin>>roomno;
	ifstream infile;
    infile.open("patient.dat",ios::app);
    long pos;
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 178);
    while(infile.read((char *)this,sizeof(hospital)))
    {
		pos=infile.tellg();	
    	
    	if(roomno==pt_room)
    	{
    		fflush(stdin);
			cout<<"\n\n\tEnter Patient Name:";
			cin.getline(pt_name,sizeof(pt_name));
			fflush(stdin);
			cout<<"\n\n\tEnter Patient Address:";
			cin.getline(pt_addr,sizeof(pt_addr));
			fflush(stdin);
			cout<<"\n\n\tEnter Diagnosis";
			cin.getline(pt_diag,sizeof(pt_diag));
			fflush(stdin);
			cout<<"\n\n\tEnter phone Number";
			cin>>pt_pno;
			fflush(stdin);			cin.ignore();
			cout<<"Enter Date of Arrival(DD/MM/YY)";
			cin>>pt_doa_dd;
			cin>>pt_doa_mm;
			cin>>pt_doa_yy;
			
			infile.seekg(pos);
			ofstream outfile;
    		outfile.open("patient.dat",ios::app);
    		outfile.write((char *)this,sizeof(hospital));
    		outfile.close();
    		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 180);
			cout<<"Records Modified.";
			p=1;
			break;
			
	    }
	}
	if(p!=1)
	{	cout<<"Details not found";
	}
infile.close();
int mm;
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 179);
cout<<"Press 0 to go back to the main menu";
cin>>mm;
if(mm==0) mainmenu();	
}
void hospital::pt_delete()
{
  	char found='f';
	int p=0;
	char ch;
	system("cls");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 185);
	int roomno;
	cout<<"Enter room no:";
	cin>>roomno;
	
	
	ifstream fin("patient.dat",ios::in);
	ofstream fout("temp.dat",ios::out);
	while(fin.read((char*)this,sizeof(hospital)))
	{
		
		if(roomno==pt_room)
		{	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 178);
			cout<<"\n\n\tPatient Name: "<<pt_name<<endl;
			cout<<"\n\n\tPatient Address: "<<pt_addr<<endl;
			cout<<"\n\n\tPhone Number: "<<pt_pno<<endl;
			cout<<"\n\n\tRoom No.: "<<pt_room<<endl;
			cout<<"\n\n\tDiagnosis: "<<pt_diag<<endl;
			cout<<"\n\n\tDate of Arrival: "<<pt_doa_dd<<pt_doa_mm<<pt_doa_yy<<endl;
			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 185);
			cout<<"\n\n Do you want to delete this record(y/n): ";
			cin>>ch;
			found='t';
		
			if(ch=='n')
				fout.write((char*)this,sizeof(hospital));
			
		}	
		else	
		{
			fout.write((char*)this,sizeof(hospital));	
		}
	}
if(found=='f')
	cout<<"Record not found";		
fin.close();
fout.close();
remove("patient.dat");

rename("temp.dat","patient.dat");

SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 184);
cout<<"\n\n\tRecord deleted successfully";
int mm;
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 183);
cout<<"\n\n\tPress 0 to go back to the main menu";
cin>>mm;
if(mm==0) mainmenu();	
}

void hospital::dt_add()
{	

	{
		system("cls");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 185);
		cout<<"\n\n\tEnter Doctor's License number"<<endl;
		cin>>dt_id;
		fflush(stdin);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 178);
		cout<<"\n\n\tEnter Doctor Name:"<<endl;
		cin.getline(dt_name,sizeof(dt_name));
		cout<<"\n\n\tEnter Emergency Contact no:"<<endl;
		cin>>dt_pno;
		fflush(stdin);
		cout<<"\n\n\tEnter Visiting hours"<<endl;
		cin.getline(dt_vt,sizeof(dt_vt));
		fflush(stdin);
		cout<<"\n\n\tEnter Specialization"<<endl;
		cin.getline(dt_spec,sizeof(dt_spec));
			
		ofstream outfile;
    	outfile.open("doctor.dat",ios::app);
    	outfile.write((char *)this,sizeof(hospital));
    	outfile.close();
    	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 184);
		cout<<"\n\n\tDoctor Registered";
		
		
}
	
int mm;
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 183);
cout<<"Press 0 to go back to the main menu";
cin>>mm;
if(mm==0) mainmenu();    
}

void hospital::dt_display()
{	int docno;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 185);
	cout<<"\n\n\tEnter License Number:";
	cin>>docno;
	  
    ifstream infile;
    infile.open("doctor.dat",ios::app);
    
    while(infile.read((char *)this,sizeof(hospital)))
    { 
    	
    	if(docno==dt_id)
    	{	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 178);
    		cout<<"\n\n\tDoctor Name:  "<<dt_name<<endl;
			cout<<"\n\n\tEmergency Phone Number:  "<<dt_pno<<endl;
			cout<<"\n\n\tVisiting hours "<<dt_vt<<endl;
			cout<<"\n\n\tSpecialization"<<dt_spec<<endl;
			cout<<"\n\n\tLicense No."<<dt_id<<endl;
		}
	}
infile.close();
int mm;
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 184);
cout<<"\n\n\tPress 0 to go back to the main menu";
cin>>mm;
if(mm==0) mainmenu();	
}

void hospital::dt_edit()
{	int p=0;
	int docno;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 183);
	cout<<"\n\n\tEnter License no: ";
	cin>>docno;
	ifstream infile;
    infile.open("doctor.dat",ios::app);
    long pos;
    while(infile.read((char *)this,sizeof(hospital)))
    {
		pos=infile.tellg();	
    	
    	if(docno==dt_id)
    	{	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 185);
    		fflush(stdin);
			cout<<"\n\n\tEnter Doctor Name:"<<endl;
			cin.getline(dt_name,sizeof(dt_name));
			cout<<"\n\n\tEnter Emergency Contact no:"<<endl;
			cin>>dt_pno;
			fflush(stdin);
			cout<<"\n\n\tEnter Visiting hours"<<endl;
			cin.getline(dt_vt,sizeof(dt_vt));
			fflush(stdin);
			cout<<"\n\n\tEnter Specialization"<<endl;
			cin.getline(dt_spec,sizeof(dt_spec));

			
			infile.seekg(pos);
			ofstream outfile;
    		outfile.open("doctor.dat");
    		outfile.write((char *)this,sizeof(hospital));
    		outfile.close();
    		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 183);
			cout<<"Records Modified.";
			p=1;
			break;
	    }
		
	}
if(p!=1)
		{
			cout<<"Details not found";
	    }
infile.close();
int mm;
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 181);
cout<<"Press 0 to go back to the main menu";
cin>>mm;
if(mm==0) mainmenu();	
}
void hospital::dt_delete()
{
	char found='f';
	int p=0;
	char ch;
  	int docno;
  	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 185);
	cout<<"\n\n\tEnter License:";
	cin>>docno;
	
	ifstream fin("doctor.dat",ios::in);
	ofstream fout("temp.dat",ios::out);
	while(fin.read((char*)this,sizeof(hospital)))
	{	
		
		if(docno==dt_id)
		{	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 178);
			cout<<"\n\n\tDoctor Name:  "<<dt_name<<endl;
			cout<<"\n\n\tEmergency Phone Number:  "<<dt_pno<<endl;
			cout<<"\n\n\tVisiting hours "<<dt_vt<<endl;
			cout<<"\n\n\tSpecialization"<<dt_spec<<endl;
			cout<<"\n\n\tLicense No."<<dt_id<<endl;
			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 182);
			cout<<"\n\n\tDo you want to delete this record(y/n): ";
			cin>>ch;
			found='t';
		
			if(ch=='n')
				fout.write((char*)this,sizeof(hospital));
			
		}	
		else	
		{
			fout.write((char*)this,sizeof(hospital));	
		}
	}
if(found=='f')
	
	cout<<"Record not found";		
fin.close();
fout.close();
remove("doctor.dat");
rename("temp.dat","doctor.dat");
cout<<"Record Deleted Successfully";
int mm;
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 181);
cout<<"Press 0 to go back to the main menu";
cin>>mm;
if(mm==0) mainmenu();	
}

void hospital::pg_add()
{	

	system("cls");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 189);
	cout<<"\n\n\tEnter Room no:";
	cin>>pg_id;
	cout<<"\n\n\tEnter sample type:";
	cin>>pg_type;
	cout<<"\n\n\tEnter cost";
	cin>>pg_price;
	cin.ignore();
	cout<<"\n\n\tEnter Date of Receiving(DD/MM)";
	cin>>pg_dor_dd;
	cin>>pg_dor_mm;
		
	ofstream outfile1;
    outfile1.open("pathology.dat",ios::app);
    outfile1.write((char *)this,sizeof(hospital));
    outfile1.close();
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 178);
	cout<<"\n\n\tSample Registered";
	int mm;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 183);
	cout<<"\n\n\tPress 0 to go back to the main menu";
	cin>>mm;
	if(mm==0) mainmenu();    
}

void hospital::pg_display()
{	int patno;
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 178);
	cout<<"\n\n\tEnter room no: ";
	cin>>patno;
	  
    ifstream infile1;
    infile1.open("pathology.dat",ios::app);
    
    while(infile1.read((char *)this,sizeof(hospital)))
    {
    	
    	if(patno==pg_id)
    	{	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 182);
    		cout<<"\n\n\tSample Id: "<<pg_id<<endl;
			cout<<"\n\n\tSample type: "<<pg_type<<endl;
			cout<<"\n\n\tDate of Receiving: "<<pg_dor_dd<<"/"<<pg_dor_mm<<endl;
			cout<<"\n\n\tTotal Cost"<<pg_price<<endl;
			
			
		}
	}
infile1.close();	
int mm;
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 185);
cout<<"\n\n\t\tPress 0 to go back to the main menu";
cin>>mm;
if(mm==0) mainmenu();	
}

void hospital::pg_edit()
{	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 178);
	int patno;
	cout<<"\n\n\tEnter Sample Id:";
	cin>>patno;
	ifstream infile1;
    infile1.open("pathology.dat",ios::app);
    long pos;
    while(infile1.read((char *)this,sizeof(hospital)))
    {
		pos=infile1.tellg();	
    	
    	if(patno==pg_id)
    	{	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 183);
    		cout<<"\n\n\tEnter Patient Name:"<<pg_id;
			cout<<"\n\n\tEnter sample type:";
			cin>>pg_type;
			cout<<"\n\n\tEnter cost";
			cin>>pg_price;
			cin.ignore();
			cout<<"\n\n\tEnter Date of Receiving(DD/MM)";
			cin>>pg_dor_dd;
			cin>>pg_dor_mm;
			
			infile1.seekg(pos);
			ofstream outfile1;
    		outfile1.open("pathology.dat");
    		outfile1.write((char *)this,sizeof(hospital));
    		outfile1.close();
    		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 181);
			cout<<"\n\n\tRecords Modified.";
	    }
		else
		{
			cout<<"Details not found";
	    }
	}
infile1.close();	
int mm;
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 183);
cout<<"Press 0 to go back to the main menu";
cin>>mm;
if(mm==0) mainmenu();	
}
void hospital::pg_delete()
{
  	char found='f';
	int p=0;
	char ch;
	int patno;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 176);
	cout<<"\n\n\tEnter room no:";
	cin>>patno;
	
	
	ifstream fin1("pathology.dat",ios::in);
	ofstream fout1("temp.dat",ios::out);
	while(fin1.read((char*)this,sizeof(hospital)))
	{
		
		if(patno==pg_id)
		{	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 178);
			cout<<"\n\n\tSample Id: "<<pg_id<<endl;
			cout<<"\n\n\tSample type:"<<pg_type<<endl;
			cout<<"\n\n\tDate of Receiving:"<<pg_dor_dd<<pg_dor_mm<<endl;
			cout<<"\n\n\tTotal Cost"<<pg_price<<endl;
			cout<<"\n\n\tResult"<<pg_r<<endl;
			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 184);
			cout<<"\n\n\t Do you want to delete this record(y/n): ";
			cin>>ch;
			
			found='t';
		
			if(ch=='n')
				fout1.write((char*)this,sizeof(hospital));
			
		}	
		else	
		{
			fout1.write((char*)this,sizeof(hospital));	
		}
	}
if(found=='f')
	cout<<"Record not found";		
fin1.close();
fout1.close();
remove("pathology.dat");

rename("temp.dat","pathology.dat");

SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 178);
cout<<"Record deleted successfully";
int mm;
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 180);
cout<<"Press 0 to go back to the main menu";
cin>>mm;
if(mm==0) mainmenu();	
}


void hospital::pt_billing()
{	int roomno;
	int p;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 177); 
	cout<<"Enter room no:";
	cin>>roomno;
	  
    ifstream infile;
    infile.open("patient.dat",ios::app);
    
    while(infile.read((char *)this,sizeof(hospital)))
    {
    	
    	if(pt_room==roomno)
    	{	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 184);
    		cout<<"\nPatient Name:"<<pt_name<<endl;
			cout<<"Patient Address:"<<pt_addr<<endl;
			cout<<"Phone Number:"<<pt_pno<<endl;
			cout<<"Room No."<<pt_room<<endl;
			cout<<"Diagnosis"<<pt_diag<<endl;
			cout<<"Date of Arrival"<<pt_doa_dd<<"/"<<pt_doa_mm<<"/"<<pt_doa_yy<<endl;
			p=1;
		}
		
		
		
	}
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 180);
	if(p!=1) cout<<"Room Not found";
	int confirm=0;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 176);
	cout<<"Are you sure you want to generate the invoice ? press 1 to confirm";
	cin>>confirm;
	if(confirm==1)
	{
	
		int days_in_months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		int years_difference, days_difference;
		int months_total;
		int reg_year = 365;
		int pt_dod_dd;
		int pt_dod_mm;
		int pt_dod_yy;
	
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 178);
		cout<<"\nEnter Date of Discharge:: "<<endl;
		cout<<endl;

		cout<<"Day: ";
		cin>>pt_dod_dd;
		if(pt_dod_dd > 31 || pt_dod_dd <= 0)
		{
			cout<<"Incorrect day entered"<<endl;
			cin.ignore();
			
		}
		cout<<"Month: ";
		cin>>pt_dod_mm;
		if(pt_dod_mm > 12 || pt_dod_mm <= 0)
		{
			cout<<"Incorrect Month entered"<<endl;
			cin.ignore();
			
		}
		cout<<"Year: ";
		cin>>pt_dod_yy;
		if(pt_dod_yy > 9999 || pt_dod_yy < 0)
		{
			cout<<"Incorrect Year Entered"<<endl;
			cin.ignore();
			
		}


	/////////////////////////////Years/////////////////////////////////

	
	if(pt_doa_yy == pt_dod_yy)
	{
		years_difference = 0;
	}
	else
	{
		if(pt_doa_yy % 4 == 0 && pt_doa_yy % 100 != 0 || pt_doa_yy % 400 == 0)
		{
			if(pt_dod_yy % 4 == 0 && pt_dod_yy % 100 != 0 || pt_dod_yy % 400 == 0)
			{
				if(pt_doa_yy > pt_dod_yy)
				{
					years_difference = (pt_doa_yy - pt_dod_yy) * (reg_year) + 2;
				}
				else
				{
					years_difference = (pt_dod_yy - pt_doa_yy) * (reg_year) + 2;
				}
				if(pt_dod_mm > pt_doa_mm)
				{
					if(days_in_months[pt_doa_mm - 1] > days_in_months[1])
					{
						--years_difference;
					}
				}
			}
			else
			{
				if(pt_doa_yy > pt_dod_yy)
				{
					years_difference = (pt_doa_yy - pt_dod_yy) * (reg_year) + 1;
				}
				else
				{
					years_difference = (pt_dod_yy - pt_doa_yy) * (reg_year) + 1;
				}
				if(pt_doa_mm > pt_dod_mm)
				{
					if(days_in_months[pt_dod_mm - 1] > days_in_months[1])
					{
						--years_difference;
					}
				}
			}
		}
		else
		{
			if(pt_doa_yy > pt_dod_yy)
			{
				years_difference = (pt_doa_yy - pt_dod_yy) * (reg_year);
			}
			else
			{
				years_difference = (pt_dod_yy - pt_doa_yy) * (reg_year);
			}
		}
	}

	/////////////////////////////Months////////////////////////////////////

	
	if(pt_doa_mm == pt_dod_mm)
	{
		months_total = 0;
	}
	else
	{
		if(pt_doa_mm > pt_dod_mm)
		{
			for(int i = (pt_doa_mm - 1); i > (pt_dod_mm - 1); i--)
			{
				static int months_total_temp = 0;
				months_total_temp += days_in_months[i];
				months_total = months_total_temp;
			}
		}
		else
		{
			for(int i = (pt_doa_mm - 1); i < (pt_dod_mm - 1); i++)
			{
				static int months_total_temp = 0;
				months_total_temp += days_in_months[i];
				months_total = months_total_temp;
			}
		}
	}

	////////////////////////////Days//////////////////////////////////

	int days_total;

	if (pt_doa_dd == pt_dod_dd)
	{
		days_difference = 0;
		days_total = (years_difference + months_total) - days_difference;
	}
	else
	{
		if(pt_doa_dd > pt_dod_dd)
		{
			days_difference = pt_doa_dd - pt_dod_dd;
			days_total = (years_difference + months_total) - days_difference;
		}
		else
		{
			days_difference = pt_dod_dd - pt_doa_dd;
			days_total = (years_difference + months_total) + days_difference;
		}
	}

	//////////////////////////In Between Leap Years///////////////////////////////

	if(pt_doa_yy == pt_dod_yy)
	{
	}
	else
	{
		if(pt_doa_yy > pt_dod_yy)
		{
			for(int i = (pt_dod_yy + 1); i < pt_doa_yy; i++)
			{
				if(i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
				{
					cout<<endl;
					cout<<i<<endl;
					++days_total;
				}
			}
		}
		else
		{
			for(int i = (pt_doa_yy + 1); i < pt_dod_yy; i++)
			{
				if(i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
				{
					cout<<endl;
					cout<<i<<endl;
					++days_total;
				}
			}
	        }
	}

	//////////////////////////Output//////////////////////////////////

	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 178);
	cout<<endl;
	cout<<"\nThe total days in between your dates are: "<<days_total<<endl;
	cout<<endl;

	
	
	cout<<"The charges per day are Rs.3000"<<endl;
	cout<<"\n\nTherefore, total room charges are "<<days_total*3000<<endl;
	
	
	cout<<"\n\nThe visiting charges of the Doctor are Rs.350"<<endl;
	cout<<"\n\nTherefore, total charges are"<<days_total*350<<endl;
	
	
    infile.close();
    
    ifstream infile1;
    infile1.open("pathology.dat",ios::app);
    int samp=0;
    while(!infile1.eof())
    {	infile1.read((char *)this,sizeof(hospital));
    	
    	if(roomno==pg_id)
    	{
    		samp++;
    	}
	}
	
	cout<<"\n\nNo. of samples: "<<samp-1<<endl;
	
	infile1.close();
	
    cout<<"\n\nCharges per sample are Rs.150"<<endl;
	cout<<"\nTherefore the charges are: "<<samp*150<<endl;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 176);
	cout<<"\n\nHence the total charges are :"<<(days_total*3000)+(days_total*350)+(samp*150);
	}
}
main()
{	hospital h;
	h.mainmenu();	
	getch();
}
