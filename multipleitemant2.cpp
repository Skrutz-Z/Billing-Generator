#include <iostream>
#include <cstring>
#include<ctime>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <string.h>
#include <locale> 
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

class Plates
{
	double SubTotal = 0;
	long GST;
	long Total = 0;
	char name[100];
	int qty;
	string user_choice;
	int place=0;
	string item_code[8] = 
	{"HERN12","HERN04","HERN10","HESQ10","HERN08","HESQ8","HERN6","HESQ6"};
	string descriptio[8] = {"12\" ROUND ARECA PLATE","04\" ROUND ARECA PLATE","10\" ROUND ARECA PLATE","10\" SQUARE ARECA PLATE","08\" ROUND ARECA PLATE","08\" SQUARE ARECA PLATE","06\" ROUND ARECA PLATE","06\" SQUARE ARECA PLATE"};
	int price[8] = {10 ,5,8,10,7,8,6,7};

	public:
		void intro()
		{
			cout<<"Welcome To Hind Eco \n";
			cout<<"Please enter your name ";
				cin>>name;
				cout<<"Your Name is "<<strupr(name)<<endl;
		}
		void accept()
		{
			std::locale loc;
			 string c="Nothing";
			cout<<"Please enter Item Code ";
			cin>>user_choice;std::string str = user_choice;
			transform(user_choice.begin(), user_choice.end(), user_choice.begin(), ::toupper); 			 	

			char uc[6];
			strcpy(uc,user_choice.c_str());
		
			for(int pos = 0; pos < 8; pos++)
			{
				if(user_choice==item_code[pos])
				{
				
					c = "Found";
					place = pos;
				}
			
			}
			
			if(c=="Found")
				{
					
					cout<<"Item Found!"<<endl;
					cout<<"position is "<<place<<endl;
					cout<<"The Description for the following Item Code is "<<descriptio[place]<<endl;
				cout<<"The price for the current Item is "<<price[place]<<endl;
				cout<<"Please enter the Quantity of "<<descriptio[place]<<" : ";cin>>qty;
				SubTotal = qty * price[place];
				cout<<"Your Total will be Rs : "<<SubTotal<<" (exclusive of GST)";
				Total += SubTotal;
				choice();
				}else{cout<<"Item not found in the list..\a\nPlease select from the following : "<<endl;
	
	
		for(int p = 0; p < 8; p++)
			{
				cout<<item_code[p]<<endl;
			}


				
				accept();
				} }
			void choice()
			{
				cout<<"\nWould you like to have something else??\n"<<endl;
				cin>>user_choice;
	
			if(user_choice == "yes")
				{
					
					cout<<"Total so far without GST is " <<Total<<endl;
					accept();
				}
		else
			{
						

			
			if(user_choice== "no")
			{
				display();
				
			}
			else
			{
				cout<<"Choose between yes and no only..";
			choice();
			}
			}
		}
				void SubTotal1()
				{
					cout<<"Your Subtotal is "<<Total<<endl;
						GST = Total * 0.05;
					cout<<"GST applied will be : "<<GST<<endl;
					cout<<"Your Total Amount Is : ";
					Total = Total + GST;
					cout<<Total;
				}
				void display()
				{
				cout<<"\nData saved Successfully!!\n";
				cout<<"BILL\n";
				cout<<"Customer name : "<<name<<endl;
				cout<<"Item name : "<<item_code[place]<<endl;
				cout<<"Quantity : "<<qty<<endl;
				cout<<"Total Amount : "<<Total<<endl;
				cout<<"Thank you!"<<endl;
				cout<<" Visit Again ";
				cout<<"Your Bill was saved sucessfully on ";
				time_t my_time = time(NULL); 
  				  printf("%s", ctime(&my_time)); 
							
				ofstream bill;
				bill.open ("HINDECO1.doc");
 				bill<<"\nParticulars \t Qty \t price \n\n";
				bill<<item_code<<"\t    "<<qty<<"\t"<<price[place]<<"\n\n";
				bill<<item_code;;
 				bill.close();
				bill.open("HINDECO.doc");
				bill<<"HIND ECO	\n";
				bill<<"Invoice\n";
				bill<<"------------\n\n";
				bill<<"Customer name : \t"<<name;
				bill<<item_code;
				bill<<"\nTax is "<<(Total * 0.05)<<"\n";
				bill<<"\n\n\n"<<"Total is : "<<Total;
				bill<<"\nYour Bill was saved sucessfully on : "<<printf("%s", ctime(&my_time));
				bill<<"\nThank you \nVisit again!!";    			
			
				}			
		
};

int main()
{
	
   
	Plates p;
	p.intro();
	p.accept();
	p.SubTotal1();
	p.display();
}
