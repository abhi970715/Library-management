#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
class Cardinfo{     //class1
	protected:
  string name;    
  string address;
  string FName;
  string mobile;
  public:
  	cardinfo(){          //default constructor
	  }
  void setname(string name ){
  	this->name=name;
  }
  void setaddress(string address ){
  	this->address=address;
  }
  void setFName(string FName ){
  	this->FName=FName;
  }
  void setmobile(string mobile ){
  	this->mobile=mobile;
  }
  string getName(){
  	return this->name;
  }
  string getFName(){
  	return this->FName;
  }
  string getAddress(){
  	return this->address;
  }
  string getMobile(){
  	return this->mobile;
  }
};
 class Book{
 protected:                      //class 2
 	string title;
 	string author;
 	 int position;               
 	public:
 		Book(){                                //overloading
		 }
 		Book(string title,string author){      //Parameterized Constructor
 			this->title=title;
 			this->author=author;
 		//	this->position=position;
		 }
		 void setposition(int position){
		 	this->position=position;
		 }
		 int getposition(){
		 	return this->position;
		 }
		 int available(string Search_Title);  
		 virtual void indecposition(int x){             //friend function
		 	position=position+x;
		 }   
 };
    int Book:: available(string Search_Title){
		 	if(Search_Title==title  && position>0){
		 		return 1;
			 }
		 	return 0;
		 }
	
// int Book::position=50;
class Borrow:public Book{                      //class 3 with single level inheritance
	int date;
	int month;
	int year;
	public:
		Borrow(int date,int month,int year, string title,string author): Book(title,  author){
			this->date=date;
			this->month=month;
			this->year=year;	
		}
		int getdate(){
			return this->date;
		}
		int getmonth(){
			return this->month;
		}
		int getyear(){
			return this->year;
		}
	
	~Borrow(){}	//destructor
};
class Return:public Book{                         //class 4 Multilevel inheritance

	protected:
		int Rdate;
		int Rmonth;
		int Ryear;
		public:
			Return(int Rdate,int Rmonth,int Ryear,string title,string author):Book(title,author){
				this->Rdate=Rdate;
				this->Rmonth=Rmonth;
				this->Ryear=Ryear;
			}
			int getFine(int bdate,int bmonth,int byear){
				int year,month,date,fine;
				year=Ryear-byear;
				month=Rmonth-bmonth;
				date=Rdate-bdate;
				if(date>10){
					fine =year*15+month*10+date*5;
					return fine;
				}
				else{
					return 0;
				}
				
			}
};
template<typename T>      //template
void rating(){
	T x;
	cout<<"\n Enter ratings for the library";
	cin>>x;
}
int main(){
	
	Book volume1("C++","Herbert Schildt");
	volume1.setposition(5);
	Book volume2("Harry Potter","JK Rowling");
	volume2.setposition(7);
	Book volume3("The Name of The Wind","Patrick Rothfuss");
	volume3.setposition(3);
	Book volume4("Let Us C","Yashwant Kanetkar");
	volume4.setposition(10);
	Book volume5("Mathematics-1","RD Sharma");
	volume5.setposition(12);
	bool havecard; 
	cout<<"Welcomwe to Gyankendra Library.";
	cout<<"Do you have a card.";
	cin>>havecard;
	if(havecard==0){
		Cardinfo member;
		string name,f_name,address, mobile;
		cout<<"Fill-in the details-";
		cout<<"Name-";
		cin>>name;
		cout<<"Father Name-";
		cin>>f_name;
		cout<<"Address-";
		getline(cin,address,'.');
		cout<<"Mobile Number-";
		cin>>mobile;
		member.setname(name);
		member.setFName(f_name);
		member.setaddress(address);
		member.setmobile(mobile);
	}
	else{
		int date,month,year;
			cout<<"Enter todays date= ";
			cin>>date>>month>>year;
		cout<<"What Service do you like to perform-\n1.Borrow \n 2. Return";
		int select;
		cin>>select;
		switch(select){
			case 1:{
		
			string bookName,bookauthor;
			
			int i=0;
			char decision[5];
			do{ 
			i++;
			if(i==4){
				cout<<"Sorry! maximum of three books can be isssued at once";
				break;
			}
			cout<<"Enter book name and its author name =";
			cin>>bookName;
			//getline(cin,bookName,".");
			cin>>bookauthor;
			//getline(cin,bookauthor,".");
			Borrow book1(date,month,year,bookName,bookauthor); 
			indecposition(-1);
			if(book1.available(bookName)==1){
			   cout<<bookName <<"is Issued on"<<date<<"/"<<month<<"/"<<year;	
			}
			else{
				cout<<"Sorry "<<bookName<<"is not available";
			}
			cout<<"Do you want another book-";
			cin>>decision;
		}
		while(decision=='yes' );
		break;
	}
		case 2:{
		    char decision[5];
			string volumename,volumeauthor;
		here:	cout<<"Book to be returned=";
			cin>>volumename;
			cin>>volumeauthor;
			int bdate,bmonth,byear;
			cout<<"\nEnter the borrow date=";
			cin>>bdate>>bmonth>>byear;
			Return book2(date,month,year,volumename,volumeauthor);
			indecposition(1);
			int fine=book2.getFine(bdate,bmonth,byear);
	
			if(fine!=0){
				cout<<"Thanks for returning .You have not returned book opn time \n Pay Rs"<<fine;
			}
			else
			cout<<"\n Thanx for returning book on time";
			cout<<"\n Do you have another book to return- ";
			cin>>decision;
			if(decision=='yes')
			goto here;
			else 
			break;
		}
			default:{
				cout<<"Reading is allowed within premises";
			  rating<int>();
				
				break;
			}
		} 
	}
	
	return 0;
}
