#include <iostream>
#include <cstring>
#include<ctime>
#include <time.h> 
#include <algorithm>
#include <fstream>

using namespace std;

class Plates
{
	double SubTotal = 10;
	int c1=0; //flag
	double GST;
	time_t my_time = time(NULL);
	ofstream bill;
	double Total = 0;
	char name[100];
	int qty = 0;
	string user_choice;
	int place=0;
	string item_code[8] = 
	{"HERN12","HERN04","HERN10","HESQ10","HERN08","HESQ8","HERN6","HESQ6"};
	string descriptio[8] = {"12\" ROUND ARECA PLATE","04\" ROUND ARECA PLATE","10\" ROUND ARECA PLATE","10\" SQUARE ARECA PLATE","08\" ROUND ARECA PLATE","08\" SQUARE ARECA PLATE","06\" ROUND ARECA PLATE","06\" SQUARE ARECA PLATE"};
	int price[8] = {10 ,5,8,10,7,8,6,7};

	public:
		void intro()
		{
		
			cout<<"\nPlease enter your name ";
			cin>>name;
				
			qty = fun(name);
			if(qty==1)
				{
					cout<<"Please enter alphabets only..";
					intro();
				}
				strupr(name);
 				bill.open("HINDECO.doc");
				bill<<"HIND ECO	\n";
				bill<<"Invoice\n";
				bill<<"\n\nYour Bill was saved sucessfully on : "<<("%s", ctime(&my_time));
				bill<<"\n------------\n\n";
				bill<<"Customer name : \t"<<name;
				bill<<"\nParticulars \t\t Qty \t price \t Rate\n\n";
			
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
				cout<<"\nThe Description for the following Item Code is "<<descriptio[place]<<endl;
				cout<<"The price for the current Item is "<<price[place]<<endl;
				string s;
				cout<<"Please enter the Quantity of "<<descriptio[place]<<" : ";
				cin>>qty;
			
			//to come back to qty if alphabet is entered... WIP
				// declaring character array 
//					int n = fun(s);
//					
			
//				    if(n!=1) 
//				    {
//				    	cout<<"Invalid Qty.. Please try again..";
//				    	accept();
//					}
//				   else
//				   {
//				   	cout<<"You have selected "<<s<<" number of "<<descriptio[place];
//				   }
//				

				SubTotal = qty * price[place];
				cout<<"Your Total will be Rs : "<<SubTotal<<" (exclusive of GST)";
				Total += SubTotal;
				choice();
				}
			else
			{
				cout<<"Item not found in the list..\a\nPlease select from the following : "<<endl;
	
	
				for(int p = 0; p < 8; p++)
				{
					cout<<item_code[p]<<endl;
				}
				accept();
			} 
		}
		
		int fun(string s)
		{
				for(int i=0;i<s.size();i++)
				{
			        if(!isdigit(s[i])) {
			        
					c1=1;break;}
			    }
				    if(c1==1) 
				    {
				    int n = s.length(); 
  
    // declaring character array 
    char char_array[n + 1]; 
  
    // copying the contents of the 
    // string to char array 
    strcpy(char_array, s.c_str()); 	
				    	qty = atoi(char_array);
				   		return 2;
				   	}
				    else{
					return 1;
					}
			
		}
		void choice()
		{
				cout<<"\nWould you like to have something else??\n"<<endl;
				cin>>user_choice;
	
			if(user_choice == "yes")
			{
				bill<<descriptio[place]<<"\t    "<<qty<<"\t"<<price[place]<<"\t"<<(qty*price[place])<<"\n\n";
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
				cout<<"Choose between yes and no only..\a";
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
				cout<<"Item name : "<<descriptio[place]<<endl;
				cout<<"Quantity : "<<qty<<endl;
				SubTotal1();
	//			cout<<"Total Amount : "<<Total<<endl;
				cout<<"\nThank you!"<<endl;
				cout<<" Visit Again ";
				cout<<"Your Bill was saved sucessfully on ";
				 
  				printf("%s", ctime(&my_time)); 
							
				
				
				bill<<descriptio[place]<<"\t    "<<qty<<"\t"<<price[place]<<"\t"<<(qty*price[place])<<"\n\n";
			//	bill<<item_code;
 				
			//	bill<<item_code;
				bill<<"\n\n"<<"\nTax is Rs."<<(Total * 0.05)<<"\n";
				bill<<"\nTotal is : "<<(Total);
				 
				bill<<"\nThank you \nVisit again!!";    			
				bill.close();
				}			
		
};

int main()
{
	Plates p;
		cout<<"Welcome To Hind Eco \n";
	p.intro();
	p.accept();
}
