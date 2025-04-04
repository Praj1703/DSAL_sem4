#include<iostream>
#include<fstream>

using namespace std;

class student_record{
	private:	
		struct student{
		int roll_no;
		char name[20];
	}s;
	
	public:
		void create();
		void display();
		void search();
		void delete_record();

};

void student_record::create(){
	ofstream out;
	int ans;
	out.open("student_record.data", ios::binary | ios::out);
	do{
		cout<<"\n Enter the Roll number of the Student: ";
		cin>>s.roll_no;
		
		cout<<"\n Enter the name of the  respective student: \n\n";
		cin>>s.name;
		
		out.write((char *) &s, sizeof(s));
		cout<<"Do you want to enter another record ? \n If yes then Enter 1 otherwise 0 :"<<endl;
		cin>>ans;
	}while(ans==1);
	
	out.close();
	
}

void student_record::display(){
	ifstream in;
	in.open("student_record.data", ios::binary | ios::in);
	
	while(in.read((char *) &s, sizeof(s)))
	cout<<"\n"<<s.roll_no<<"\t"<<s.name;
	
	in.close();
	cout<<"\n";

}

void student_record::search(){
	ifstream in;
	int key;
	bool found = false;
	
	cout<<"\nEnter Roll Number to Search: ";
	cin>>key;
	
	in.open("student_record.data", ios::binary | ios::in);
	
	while(in.read((char *) &s, sizeof(s))){
		if(s.roll_no == key){
			cout<<"\nStudent Record found of entered Roll no. \n";
			cout<<s.roll_no<<"\t"<<s.name<<"\n";
			found = true;
			break;
		}	
	}
	
	if (!found){
		cout<<"No Record found"<<endl;
	}
	in.close();
}


void student_record::delete_record(){
	int key;
	bool found = false;
	
	cout<<"\nEnter Roll Number to Delete : ";
	cin>>key;
	
	ifstream in;
	in.open("student_record.data", ios::binary | ios::in);
	
	ofstream out;
	out.open("temp.data", ios::binary | ios::out);
	
	while (in.read((char *) &s, sizeof(s))){
		if(s.roll_no != key){
			out.write((char*)&s, sizeof(s));
		}
		else{
			found = true;
		}
	}
	in.close();
	out.close();
	
	remove("student_record.data");
	rename("temp.data", "student_record.data");
	
	if(found){
		cout<<"\nRecord Deleted Successfully\n\n";
		cout<<s.roll_no<<"\t"<<s.name<<"\n";
		
	}
	else{
		cout<<"\nRecord Not Deleted"<<endl;
	}
}

int main(){
	student_record S;
	cout<<"\n";
	int choice;
	    do {
		cout << "\n--- Student Record Management ---\n\n";
		cout << "Select an operation:\n";
		cout << "1. Insert Data\n";
		cout << "2. Display Inserted Data\n";
		cout << "3. Search Data\n";
		cout << "4. Delete Data\n";
		cout << "5. Exit\n";
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice) {
		    case 1: S.create();
		    	break;
		    case 2: S.display(); 	
		    	break;         
		    case 3:  S.search();
		    	break;
		    case 4: S.delete_record();
		    	break;
		    case 5: cout<<"\nExiting....."<<endl;
		    default: cout << "Invalid choice. Try again.\n";
		}
	    } while (choice != 5);
	
	return 0;
}
