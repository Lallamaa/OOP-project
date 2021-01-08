/**********************************
 Program: Shop_Owner
 Course: Object Oriented Programming 
 Year: 2019/20 Trimester 1
 Name: TOO YEE SHUEN 
 ID: (1191201569)
 Lecture Section: TC02
 Tutorial Section: TT06
 Email: 1191201569@student.mmu.edu.my
 Phone: 011-56350930
 **************************************/

//****************************************************
//		INCLUDE HEADER FILES
//****************************************************
#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<stdlib.h>
using namespace std;


//****************************************************
//		CLASS NAME: SHOPITEM
//****************************************************
class ShopItem{
	protected:
		string line, getdata;
		string id, name, company, qty, prod_type;
		int type;

	public:
		void loginPage();
		int displayMenu(){
			cout << "\n\t\t=======================================" << endl;
			cout << "\t\t=	    ADMIN MAIN MENU 	      =" << endl;
			cout << "\t\t=======================================" << endl << endl;
			cout << "\t\t1. VIEW PRODUCTS "<< endl;
			cout << "\t\t2. INSERT NEW PRODUCTS " << endl;
			cout << "\t\t3. MODIFY PRODUCT " << endl;
			cout << "\t\t4. DELETE PRODUCT" << endl;
			cout << "\t\t5. SALES DATA ANALYSIS " << endl;
			cout << "\t\t6. LOGOUT " << endl << endl;
		}
		virtual void view_data(){ }
		virtual void insert_data(){	}
		virtual void update_data(){	}
		virtual void del_data(){ }
		void sales_data_analysis();

};

//****************************************************
//		SUBCLASS NAME: BOOK
//****************************************************
class Book:public ShopItem{
	private:
		string author;
	public:
		void view_data();
		void insert_data();
		void update_data();
		void del_data();
};
//****************************************************
//		SUBCLASS NAME: MAGAZINE
//****************************************************
class Magazine:public ShopItem{
	private:
		string pubYear;
	public:
		void view_data();
		void insert_data();
		void update_data();
		void del_data();
			
};
//****************************************************
//		SUBCLASS NAME: MOVIE
//****************************************************
class Movie:public ShopItem{
	private:
		string mactor;
	public:
		void view_data();
		void insert_data();
		void update_data();
		void del_data();
};
void logout();
//****************************************************
//			MAIN FUNCTION
//****************************************************
int main()
{
	int option, type;
	char confirm, rpt;
	
	// class declaration
	ShopItem S;
	Book B;
	Magazine G;
	Movie M;
	
	// call login page
	S.loginPage();
	do{
		system("CLS");		//clearing the screen
		S.displayMenu();
		cout << "\t\tPlease enter your option: ";
		cin >> option;
		
		system("CLS");
		switch(option){
			case 1:	cout << "\n\t\t=======================================" << endl;	//display the header of the function
					cout << "\t\t=	      PRODUCT DISPLAY	      =" << endl;
					cout << "\t\t=======================================" << endl << endl;
					cout << "\t\t[1] Book" << endl;
					cout << "\t\t[2] Magazine" << endl;
					cout << "\t\t[3] Movie" << endl << endl;
					cout << "\t\tSelect type of Product: ";
					cin >> type;	//get the input of type
					if(type == 1){
						Book B;				//declare class with object
						B.view_data();}		//call the virtual functions to display data
					else if(type == 2){
						Magazine G;
						G.view_data();}
					else if(type == 3){
						Movie M;
						M.view_data();}
					break;
					
			case 2:	cout << "\n\t\t=======================================" << endl; 	//display the header of the function
					cout << "\t\t=	       INSERT PRODUCT 	      =" << endl;
					cout << "\t\t=======================================" << endl << endl;
					cout << "\t\t[1] Book" << endl;
					cout << "\t\t[2] Magazine" << endl;
					cout << "\t\t[3] Movie" << endl << endl;
					cout << "\t\tPlease select type of Product: ";
					cin >> type;	//get the input of type
					if(type == 1){
						Book B;
						B.insert_data();}	//call the virtual function to insert new data
					else if(type == 2){
						Magazine G;
						G.insert_data();}
					else if(type == 3){
						Movie M;
						M.insert_data();}
					break;
			
			case 3: cout << "\n\t\t=======================================" << endl;	//display the header of the function
					cout << "\t\t=	       UPDATE PRODUCT 	      =" << endl;
					cout << "\t\t=======================================" << endl << endl;
					cout << "\t\t[1] Book" << endl;
					cout << "\t\t[2] Magazine" << endl;
					cout << "\t\t[3] Movie" << endl << endl;
					cout << "\t\tPlease select type of product to update: ";
					cin >> type; 	//get the input of type
					if(type == 1){
						Book B;
						B.update_data();}	//call the virtual function to update data according to the Obj
					else if(type == 2){
						Magazine G;
						G.update_data();}
					else if(type == 3){
						Movie M;
						M.update_data();}
					break;
					
			case 4: cout << "\n\t\t=======================================" << endl;
					cout << "\t\t=	       DELETE PRODUCT 	      =" << endl;
					cout << "\t\t=======================================" << endl << endl;
					cout << "\t\t[1] Book" << endl;
					cout << "\t\t[2] Magazine" << endl;
					cout << "\t\t[3] Movie" << endl << endl;
					cout << "\t\tPlease select type of product to delete: ";
					cin >> type; 	//get the input of type
					S.del_data(); 	
					if(type == 1){
						Book B;
						B.del_data();}	//call the virtual function	to delete data based on the type input from user			
					else if(type == 2){
						Magazine G;
						G.del_data(); }
					else if(type == 3){
						Movie M;
						M.del_data();}
					break;
					
			case 5: S.sales_data_analysis(); 
					break;
			
			case 6: logout();	// Exit the program
					break;
						
			default:cout << "\nYou have entered an invalid number. \nPlease re-enter your option: ";
					cin >> option; break;
			}
			
			cout << "\n\n\t\tWould you like to go back to Main menu?	[Y/N]: ";
			cin >> rpt;
		}while(rpt == 'Y');
}
//*******************************************************
//			LOGOUT FUNCTION
//*******************************************************

void logout(){
	cout << "\n\tYou're logging out now...";
	cin.get();
	exit(0);
}

//*******************************************************
//		FUNCTIONS TO LOGIN AND CHANGE PROFILE DETAILS
//*******************************************************

void ShopItem::loginPage(){
	//variables declaration
	int choice, chgn, confirm;
	string uname, passwrd, logUname, logPasswrd, newName, newPasswrd;
	
	fstream file;
	// display landing page
	cout << "\n\tPlease login to your account." << endl << endl;
	cout << "\t1. Login"<< endl;
	cout << "\t2. Edit Profle" << endl;
	cout << "\t3. Exit Program" << endl << endl;
	cout << "\tEnter your choice: ";
	cin >> choice;
	
	if(choice == 1){	//if user chooses choice 1, will lead to the login page
		file.open("login.txt", ios::in | ios::app);
		cout << "\n\t\t=======================================" << endl;
		cout << "\t\t=	       LOGIN PAGE 	      =" << endl;
		cout << "\t\t=======================================" << endl << endl;
		cin.ignore();
		cout << "\t\tUsername: ";
		getline(cin, logUname);
		cout << "\n\t\tPassword: ";
		getline(cin, logPasswrd);
		// input the data from login.txt and store the data in uname & passwrd
		while(getline(file, uname, ',') && getline(file, passwrd)){
			if(uname == logUname && passwrd == logPasswrd){		//if the entered Username and Password match the string in the file
				cout << "\n\t\tLogin Successful......" << endl << endl;		//User able to login
				cin.get();
				break;
			}
		}
		if(!(uname == logUname && passwrd == logPasswrd)){	//if the entered Username and Password do not match the string in the file
			cout << "\n\t\tInvalid info!"<< endl;	// User not able to login
			exit(0);
		}
		file.close();
	
	}
	else if(choice == 2){	//if user chooses choice 1, will lead to the Profile details changes page
		file.open("login.txt", ios::in);
		system("CLS");
		cout << "\n\t=======================================" << endl;
		cout << "\t=	       PROFILE 	      =" << endl;
		cout << "\t=======================================" << endl << endl;
		cout << "\n\t[1] Change Username \n\t[2] Change Password" << endl;
		cout << "\n\n\tPlease choose (Username / Password) to edit: ";
		cin >> chgn;
		if(chgn == 1){		//if user input chgn as 1
			// input the data from login.txt and store the data in uname & passwrd
			while(getline(file, uname, ',') && getline(file, passwrd)){	
				cin.ignore();
				cout << "\n\t\tCurrent Username: " << uname << endl;
				cout << "\n\t\tNew Username: " ;	
				getline(cin, newName);		//get the latest Username
				file.close();	
				file.open("login.txt", ios::out);
				file << newName << "," << passwrd;		//store the latest Username
				cout << "\n\tYour Username is successfully updated! " << endl;
				cin.get();
				file.close();	
			}
		}
		else if(chgn == 2){		//if user input chgn as 2
			// input the data from login.txt and store the data in uname & passwrd
			while(getline(file, uname, ',') && getline(file, passwrd,'\n')){
				cin.ignore();
				cout << "\n\t\tCurrent Password: " << passwrd << endl;;
				cout << "\n\t\tNew Password: " ;
				getline(cin, newPasswrd);		//get the latest Password
				file.close();
				file.open("login.txt", ios::out);
				file << uname << "," << newPasswrd;		//store the latest Password 
				cout << "\n\tYour Password is successfully updated! " << endl;
				cin.get();
				file.close();
			}
		}
		system("CLS");
		loginPage();
	}
	else if(choice == 3){
		logout();
	}
	else{
		cout << "\tInvalid number! Please re-enter your choice: ";
		cin >> choice;
	}
}

//****************************************************
//		FUNCTION TO DISPLAY DATA
//****************************************************
struct print
{
	string id, name, sub, company, qty;
	
} arr[100];

void Book::view_data(){
	fstream fout;
	fout.open("book_list.txt", ios::in | ios::out);
	cout << "\n\t\t+---------------------------------------------------------------------+"<< endl;
	cout << "\t\t|		   		BOOK              		      |" << endl;
	cout << "\t\t|---------------------------------------------------------------------|" << endl;
	cout << "\t\t| Book ID  | Book Title	   | Author        | Company       | Stock    |" << endl;
	cout << "\t\t|----------+---------------+---------------+---------------+----------|" << endl;
	// To check whether the file is open
	while(fout.is_open()){
/*		int totalItems=0;int current = 0;
		int size = 10;
		while(getline(fout, line)){
			totalItems++;
		}
		for(int k=current; k<totalItems; k++){
			for(int i=current; i<totalItems; i++){
				getline(cin, arr[i].id, ',');
				getline(cin, arr[i].name, ',');
				getline(cin, arr[i].sub, ',');
				getline(cin, arr[i].company, ',');
				getline(cin, arr[i].qty, ',');
			}
			for(int j=current; j<size; j++){
				cout << "\t\t|" << setw(10) << left << arr[j].id;
				cout << "|" << setw(15) << arr[j].name;
				cout << "|" << setw(15) << arr[j].sub;
				cout << "|" << setw(15) << arr[j].company;
				cout << "|"<< setw(10)<< arr[j].qty;
				cout << "|"<< endl;	
				cout << "\t\t|----------+---------------+---------------+---------------+----------|" << endl;
				j = current;
			}
		current += 10;
		cout << "Press any key to display next page :)";
		cin.get();
		}
	}
*/					
		// input the data from login.txt and store the data in id, name, author, company and qty
		while(getline(fout, id, ',') && getline(fout, name, ',') && getline(fout, author, ',') && getline(fout, company, ',') && getline(fout, qty, '\n')){
			cout << "\t\t|" << setw(10) << left << id;		//output all the data
			cout << "|" << setw(15) << name;
			cout << "|" << setw(15) << author;
			cout << "|" << setw(15) << company;
			cout << "|"<< setw(10)<< qty;
			cout << "|"<< endl;	
			cout << "\t\t|----------+---------------+---------------+---------------+----------|" << endl;
		}	

	fout.close();
	}
}
void Magazine::view_data(){
	fstream fout;
	fout.open("magazine_list.txt", ios::in | ios::out);
	cout << "\n\t\t+----------------------------------------------------------------------------------+"<< endl;
	cout << "\t\t|		   		       MAGAZINE              		      	   |" << endl;
	cout << "\t\t|----------------------------------------------------------------------------------|" << endl;
	cout << "\t\t| Magazine ID | Magazine Title	   |Year of Publication | Company       | Stock    |" << endl;
	cout << "\t\t|-------------+--------------------+--------------------+---------------+----------|" << endl;
	if(fout.is_open()){
/*		while(fout.is_open()){
		int totalItems =0;int current = 0;
		int size = 10;
		while(getline(fout, line)){
			totalItems++;
		}
		
		while(current < totalItems){
			for(int i=current; i<size; i++){
				getline(fout, arr[i].id, ',');
				getline(fout, arr[i].name, ',');
				getline(fout, arr[i].sub, ',');
				getline(fout, arr[i].company, ',');
				getline(fout, arr[i].qty, ',');
			}
			for(int j=current; j<size; j++){
				cout << "\t\t|" << setw(12) << left << id;
				cout << "|" << setw(20) << name;
				cout << "|" << setw(20) << pubYear;
				cout << "|" << setw(15) << company;
				cout << "|"<< setw(10)<< qty;
				cout << "|"<< endl;	
				cout << "\t\t|-------------+--------------------+--------------------+---------------+----------|" << endl;
			}
			current += 10;
		}
	}
}
*/		// input the data from login.txt and store the data in id, name,pubYear, company and qty
		while(getline(fout, id, ',') && getline(fout, name, ',') && getline(fout, pubYear, ',') && getline(fout, company, ',') && getline(fout, qty)){
			cout << "\t\t| " << setw(12) << left << id;		//output all the data
			cout << "|" << setw(20) << name;		
			cout << "|" << setw(20) << pubYear;
			cout << "|" << setw(15) << company;
			cout << "|"<< setw(10)<< qty;
			cout << "|"<< endl;	
			cout << "\t\t|-------------+--------------------+--------------------+---------------+----------|" << endl;
		}
	}
	fout.close();
}
void Movie::view_data(){
	fstream fout;
	fout.open("movie_list.txt", ios::in | ios::out);
	cout << "\n\t\t+-------------------------------------------------------------------------------+"<< endl;
	cout << "\t\t|		   		    MOVIE              		      	        |" << endl;
	cout << "\t\t|-------------------------------------------------------------------------------|" << endl;
	cout << "\t\t| Movie ID | Movie Title        | Main Actor         | Company       | Stock    |" << endl;
	cout << "\t\t|----------+--------------------+--------------------+---------------+----------|" << endl;

	if(fout.is_open()){
/*		while(fout.is_open()){
		int totalItems =0;int current = 0;
	int size = 10;
		while(getline(fout, line)){
			totalItems++;
		}
		
		while(current < totalItems){
			for(int i=current; i<size; i++){
				fout >> arr[i].id, ',';
				fout >> arr[i].name, ',';
				fout >> arr[i].sub, ',';
				fout >> arr[i].company, ',';
				fout >> arr[i].qty, ',';
			}
			for(int j=current; j<size; j++){
				cout << "\t\t|" << setw(10) << left << arr[j].id;
				cout << "|" << setw(15) << arr[j].name;
				cout << "|" << setw(15) << arr[j].sub;
				cout << "|" << setw(15) << arr[j].company;
				cout << "|"<< setw(10)<< arr[j].qty;
				cout << "|"<< endl;	
				cout << "\t\t|----------+---------------+---------------+---------------+----------|" << endl;
			}
			current +=10;
		}
	}
	*/
		// input the data from login.txt and store the data in id, name, mactor, company and qty
		while(getline(fout, id, ',') && getline(fout, name, ',') && getline(fout, mactor, ',') && getline(fout, company, ',') && getline(fout, qty, '\n')){
			cout << "\t\t|" << setw(10) << left << id;		//output all the data
			cout << "|" << setw(20) << name;
			cout << "|" << setw(20) << mactor;
			cout << "|" << setw(15) << company;
			cout << "|"<< setw(10)<< qty;
			cout << "|"<< endl;	
			cout << "\t\t|----------+--------------------+--------------------+---------------+----------|" << endl;
		}
	}
	fout.close();
}

//****************************************************
//			FUNCTION TO INSERT NEW DATA
//****************************************************
void Book::insert_data(){
	//declare all variables needed
	int add, total, id;
	string line;

	fstream file, fin;
	file.open("book_list.txt", ios::out|ios::app);		
	fin.open("total_book.txt", ios::out|ios::in|ios::app);
	// while reading the file until the last line
	while(!fin.eof()){
		fin >> total;		//get the number of the last id from the total_book textfile
	}
	fin.close();
	cout << "\n\n\t\tHow many items do you want to insert?	";
	cin >> add;	
	
	//execute a for loop to get auto generate id for each items
	for(int i=0; i<add; i++){
		static int id=(total+1);	//id will equal to the last ID + 1
		cout<<endl;
		cout<<"\n\t\tShop Item ID - "<< id << endl << endl;
		cout << "\t\tBook Title: ";
		cin.ignore();
		//get data details from user
		getline(cin, name);
		cout << "\t\tAuthor: ";
		getline(cin, author);
		cout << "\t\tCompany Name: ";
		getline(cin, company);
		cout << "\t\tStock Quantity: ";
		getline(cin, qty);				
		//store the new data 
		file << "BK" << setw(2) << setfill('0') << id;
		file << "," << name;
		file << "," << author;
		file << ","  << company;
		file << "," << qty << endl;
		total = id;		//to make sure the total always remain as the last number of id
		id++;
	}
	fin.open("total_book.txt", ios::out);
	fin << total;		//store the last ID number
	fin.close();
	file.close();
}
void Magazine::insert_data(){
	//variable declarations
	int add, total, id;
	string line;
	
	fstream file, fin;
	file.open("magazine_list.txt", ios::out|ios::app);	
	fin.open("total_mag.txt", ios::out|ios::in|ios::app);
	// while reading the file until the last line
	while(!fin.eof()){
		fin >> total;	//get the number of the last id from the total_book textfile
	}
	fin.close();
	cout << "\n\n\t\tHow many items do you want to insert?	";
	cin >> add;
	
	//execute a for loop to get auto generate id for each items
	for(int i=0; i<add; i++){
		static int id=(total+1);		//id will equal to the last ID + 1
		cout<<endl;
		//get data details from user
		cout << "\t\tMagazine Title: ";
		cin.ignore();			
		getline(cin, name);
		cout << "\t\tYear of Publication (yy-mm): ";
		getline(cin, pubYear);
		cout << "\t\tCompany Name: ";
		getline(cin, company);
		cout << "\t\tStock Quantity: ";
		getline(cin, qty);
		//store the new data 
		file << "MG" << setw(2) << setfill('0') << id;
		file << "," << name;
		file << "," << pubYear;
		file << ","  << company;
		file << "," << qty << endl;
		total = id;			//to make sure the total always remain as the last number of id
		id++;
	}
	fin.open("total_mag.txt", ios::out);
	fin << total;	//store the last ID number
	fin.close();
	file.close();
	
}
void Movie::insert_data(){
	int add, total, count;
	string line;
	fstream file, fin;
	file.open("movie_list.txt", ios::out|ios::app);
	fin.open("total_mov.txt", ios::out);
	fin.close();
	fin.open("total_mov.txt", ios::out|ios::in|ios::app);	
	// while reading the file until the last line	
	while(!fin.eof()){
		fin >> total;	//get the number of the last id from the total_book textfile
	}
	fin.close();
	cout << "\n\n\t\tHow many items do you want to insert?	";
	cin >> add;
	prod_type = "Movie";
	//execute a for loop to get auto generate id for each items
	for(int i=0; i<add; i++){		
		static int id=(total+1);	//id will equal to the last ID + 1
		cout<<endl;
		//get data details from user
		cout << "\t\tMovie Title: ";
		cin.ignore();
		getline(cin, name);
		cout << "\t\tMain Actor: ";
		getline(cin, mactor);
		cout << "\t\tCompany Name: ";
		getline(cin, company);
		cout << "\t\tStock Quantity: ";
		getline(cin, qty);
		//store the new data 
		file << "MV" << setw(2) << setfill('0') << id;
		file << "," << name;
		file << "," << mactor;
		file << ","  << company;
		file << "," << qty << endl;
		total = id;			//to make sure the total always remain as the last number of id
		id++;	
	}
	fin.open("total_mov.txt", ios::out);
	fin << total;	//store the last ID number
	fin.close();
	file.close();
}
//****************************************************
//			FUNCTION TO UPDATE DATA
//****************************************************
void Book::update_data(){
	fstream file, temp;
	file.open("book_list.txt", ios::in);
	temp.open("temp.txt", ios::out);
	
	string search, id, name, author, company, qty;
	cout << "\n\n\t\tEnter Item ID: "; 
	cin >> search;
	// input the data from book_list text file and store the data in id, name, author, company and qty	
	while(getline(file, id, ',') && getline(file, name, ',') && getline(file, author, ',') && getline(file, company, ',') && getline(file, qty)){
		if(file.is_open()){
			if(id == search){	//if id match to the search string, user are able to update the data
				cout << "\n\t\t==============Record=============" << endl;
				cout << "\t\tItem ID: " << id << endl;
				//display current details of item
				cout << "\n\t\t-Current Details- "<< endl;
				cout << "\t\tBook Title: "<<name<<endl;
				cout << "\t\tBook author: "<<author<<endl;
				cout << "\t\tCompany Name: "<<company<<endl;
				cout << "\t\tStock: "<<qty<<endl<<endl;
				//get update details from user input
				cin.ignore();
				cout << "\n\t\tUpdate Book title: ";
				getline(cin, name);
				cout << "\t\tUpdate Book author: ";
				getline(cin, author);
				cout << "\t\tUpdate Company Name: ";
				getline(cin, company);
				cout << "\t\tUpdate Stock: ";
				getline(cin, qty);
				//store updated details into temp file
				temp << id << "," << name << "," << author << "," << company << "," << qty  << endl;
				cout << "\n\n\t\tProduct Updated Successfully!" ;
				cin.get();
			}
			else if(id != search){
				//print the remaining data from book list file
				temp << id << "," << name << "," << author << "," << company << "," << qty << endl ;
			}
		}
		else{
			cout << "\n\n\t\tUnable to open file. Press any key to continue...";
		}
	}
	file.close();
	temp.close();
	//to replace temp file with list file
	remove("book_list.txt");
	rename("temp.txt", "book_list.txt");
}

void Magazine::update_data(){
	fstream file, temp;
	file.open("magazine.txt", ios::in);
	temp.open("temp.txt", ios::out);
	
	string search, id, name, author, company, qty;
	cout << "\n\n\t\tEnter Item ID: "; 
	cin >> search;
	// input the data from magazine_list text file and store the data in id, name, pubYear, company and qty
	while(getline(file, id, ',') && getline(file, name, ',') && getline(file, pubYear, ',') && getline(file, company, ',') && getline(file, qty)){
		if(file.is_open()){
			if(id == search){	//if id match to the search string, user are able to update the data
				cout << "\t\t==============Record=============" << endl;
				cout << "\t\tItem ID: " << id << endl;
				//display current details of item
				cout << "\n\t\t-Current Details- "<< endl;
				cout << "\t\tMagazine Title: "<<name<<endl;
				cout << "\t\tYear of Publication (yy-mm): "<<pubYear<<endl;
				cout << "\t\tCompany Name: "<<company<<endl;
				cout << "\t\tStock: "<<qty<<endl<<endl;
				//get update details from user input
				cin.ignore();
				cout << "\n\t\tUpdate Magazine Title: ";
				getline(cin, name);
				cout << "\t\tUpdate Year of Publication (yy-mm): ";
				getline(cin, pubYear);
				cout << "\t\tUpdate Company Name: ";
				getline(cin, company);
				cout << "\t\tUpdate Stock: ";
				getline(cin, qty);
				//store updated details into temp file
				temp << id << "," << name << "," << pubYear << "," << company << "," << qty  << endl;
				cout << "\n\n\t\tProduct Updated Successfully!" ;
				cin.get();
			}
			else if(id != search){
				//print the remaining data from magazine list file
				temp << id << "," << name << "," << pubYear << "," << company << "," << qty << endl ;
			}
		}
		else{
			cout << "\n\n\t\tUnable to open file. Press any key to continue...";
			displayMenu();
		}
	}
	file.close();
	temp.close();
	//to replace temp file with list file
	remove("magzaine_list.txt");
	rename("temp.txt", "magazine_list.txt");
	
}

void Movie::update_data(){
	fstream file, temp;
	file.open("movie_list.txt", ios::in);
	temp.open("temp.txt", ios::out|ios::app);
	
	string search, id, name, author, company, qty;
	cout << "\n\n\t\tEnter Item ID: "; 
	cin >> search;
	// input the data from movie_list text file and store the data in id, name, mactor, company and qty	
	while(getline(file, id, ',') && getline(file, name, ',') && getline(file, mactor, ',') && getline(file, company, ',') && getline(file, qty)){
		if(file.is_open()){
			if(id == search){	//if id match to the search string, user are able to update the data
				cout << "\n\t\t==============Record==============" << endl;
				cout << "\tItem ID: " << id << endl;
				//display current details of item
				cout << "\n\t\t-Current Details- "<< endl;
				cout << "\t\tBook Title: "<<name<<endl;
				cout << "\t\tBook author: "<<mactor<<endl;
				cout << "\t\tCompany Name: "<<company<<endl;
				cout << "\t\tStock: "<<qty<<endl<<endl;
				//get update details from user input
				cin.ignore();
				cout << "\t\tUpdate Movie Title: ";
				getline(cin, name);
				cout << "\t\tUpdate Main Actor: ";
				getline(cin, mactor);
				cout << "\t\tUpdate Company Name: ";
				getline(cin, company);
				cout << "\t\tUpdate Stock: ";
				cin >> qty;
				file.close();
				//store updated details into temp file
				temp << id << "," << name << "," << mactor << "," << company << "," << qty  << endl;
				cout << "\n\n\t\tProduct Updated Successfully!" ;
				cin.get();
			}
			else if(id != search){		
				//print the remaining data from movie list file
				temp << id << "," << name << "," << mactor << "," << company << "," << qty << endl ;
			}
		}
		else{
			cout << "\n\n\t\tUnable to open file. Press any key to continue...";
			displayMenu();
		}
	}
	file.close();
	temp.close();
	//to replace temp file with list file
	remove("movie_list.txt");
	rename("temp.txt", "movie_list.txt");
	
}

//****************************************************
//			FUNCTION TO DELETE DATA
//****************************************************
void Book::del_data(){
	string search;
	fstream infile, outfile;
	infile.open("book_list.txt", ios::in | ios::app);
	outfile.open("temp.txt", ios::out);
	cout << "\n\t\tEnter Item ID you want to delete: ";
	cin >> search;
	// input the data from book_list text file and store the data in id, name, author, company and qty	
	while(getline(infile, id, ',') && getline(infile, name, ',') && getline(infile, author, ',') && getline(infile, company, ',') && getline(infile, qty)){
		if(id != search){		//print all the unmatched data into temp file
			outfile << id;
			outfile << "|" << name;
			outfile << "|" << author;
			outfile << "|" << company;
			outfile << "|"<<  qty << endl;
		}
	}
	cout << "\n\t\tItem Deleted!" << endl;
	infile.close();
	outfile.close();
	//to replace temp file with list file
	remove("book_list.txt");		//the file contain unwanted data is deleted
	rename("temp.txt", "book_list.txt");
}
void Magazine::del_data(){
	
	string search;
	
	fstream infile, outfile;
	infile.open("magazine_list.txt", ios::in | ios::app);
	outfile.open("temp.txt", ios::out);
	cout << "\n\t\tEnter Item ID you want to delete: ";
	cin >> search;
	// input the data from magazine_list text file and store the data in id, name, pubYear, company and qty	
	while(getline(infile, id, ',') && getline(infile, name, ',') && getline(infile, pubYear, ',') && getline(infile, company, ',') && getline(infile, qty)){
		if(id != search){		//print all the unmatched data into temp file
			outfile << id;
			outfile << "|" << name;
			outfile << "|" << pubYear;
			outfile << "|" << company;
			outfile << "|"<< qty << endl;
		}
	}
	cout << "\n\t\tItem Deleted!" << endl;	
	infile.close();
	outfile.close();
	//to replace temp file with list file
	remove("magazine_list.txt");		//the file contain unwanted data is deleted
	rename("temp.txt", "magazine_list.txt");
}
void Movie::del_data(){
		string search;
	
	fstream infile, outfile;
	infile.open("movie_list.txt", ios::in | ios::app);
	outfile.open("temp.txt", ios::out);
	cout << "\n\t\tEnter Item ID you want to delete: ";
	cin >> search;
	// input the data from movie_list text file and store the data in id, name, mactor, company and qty	
	while(getline(infile, id, ',') && getline(infile, name, ',') && getline(infile, mactor, ',') && getline(infile, company, ',') && getline(infile, qty)){
		if(id != search){		//print all the unmatched data into temp file
			outfile << id;
			outfile << "|" << name;
			outfile << "|" << mactor;
			outfile << "|" << company;
			outfile << "|"<< qty << endl;
		}
	}
	cout << "\n\t\tItem Deleted!" << endl;
	infile.close();
	outfile.close();
	//to replace temp file with list file
	remove("movie_list.txt");		//the file contain unwanted data is deleted
	rename("temp.txt", "movie_list.txt");
}

//****************************************************
//			DISPLAY SALES DATA ANALYSIS
//****************************************************
void ShopItem::sales_data_analysis(){
	//variable declarations
	string id, price, unit, name, company, prod_type;
	int quantity, totalPrice, totalSales=0, price1;

	fstream fout, fout2;
	fout.open("customer_sales.txt", ios::out|ios::in);
	
	//display header of Sales Data Analysis
	cout << "\t\t-------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t|					SALES DATA ANALYSIS				        |" << endl;
	cout << "\t\t-------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t|  Sales ID  | Total Price | Total Sales Unit |  Product Name  |  Company Name    |  Item Type  |" << endl;
	cout << "\t\t-------------------------------------------------------------------------------------------------" << endl;
		
	// input the data from customer_sales text file and store the data in id, name, mactor, company and qty	
	while(getline(fout, id, ',')&&getline(fout, price, ',')&&getline(fout, unit, ',')&&getline(fout, name, ',')&&getline(fout, company, ',')&&getline(fout, prod_type, '\n')){
		//convert string into integer
		stringstream digit(unit);
		int quantity=0;
		digit >> quantity;
		//convert string into float
		stringstream decimal(price);
		float price1=0;
		decimal >> price1;
		//calculate the total price of product
		totalPrice = price1 * quantity;

		cout << "\t\t|  " << left << setw(10) << id << "|  " << setw(11) << fixed << setprecision(2) << totalPrice << "|  " << setw(16) << unit << "|  " << setw(14) << name 
		<< "|  " << setw(16) << company << "|  " << setw(11) << prod_type << "|" << endl; 
		cout << "\t\t-------------+-------------+------------------+----------------+------------------+--------------" << endl;
		//calculate the total sales of all product
		totalSales += totalPrice;
		
	}	
		//display total sales
		cout << "\n\t\tTotal Sales: RM " << fixed << setprecision(2) << totalSales;

}


