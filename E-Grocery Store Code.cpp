#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
using namespace std;

struct shopping
{
	//variables
	 int pcode;
	 float price;
	 float disc;
	 string pname;
	 string bname;
	 
	 //functions
	 void menu();
	 void administrator();
	 void buyer();
	 void add();
	 void edit();
	 void bill();
	 void rem();
	 void list();
	 void receipt();
	 	 
};

void shopping::menu()
{
	m:
		
	system("CLS");
	
	char choice;
	string email;
	string password;
	
	cout<<"\n\t\t\t ____________________________\n";
	cout<<"\t\t\t                            \n";
	cout<<"\t\t\t      E-GROCERY STORE        \n";
	cout<<"\t\t\t                            \n";
	cout<<"\t\t\t ____________________________\n";
	cout<<"\t\t\t                            \n";

	cout<<"\t\t\t |   1) Administrator       |\n";
	cout<<"\t\t\t |                          |\n";
	cout<<"\t\t\t |   2) Buyer               |\n";
	cout<<"\t\t\t |                          |\n";
	cout<<"\t\t\t |   3) Exit                |\n";
	cout<<"\t\t\t |                          |\n";
	cout<<"\t\t\t ____________________________\n";
	cout<<"\nPlease select: ";
    cin>>choice;
    
    system("CLS");
    
    switch(choice)
    {
    	case '1':
    	{	n:
    		cout<<"\t\t\t Please login \n";
    		cout<<"\t\t\t Enter email : ";
    		cin>>email;
    		cout<<"\t\t\t Password : ";
    		cin>>password;
    		
    		
    		if(email=="admin@gmail.com" && password=="admin123")
    		{
    			administrator();
			}
			else
			{
				cout<<"Invalid username/password";
				char opt;
				o:
				cout<<"\n\nPress 1 to login again  ";
				cout<<"\nPress 2 to Go back to main menu ";
				cout<<"\n\nEnter your choice : ";
				cin>>opt;
				switch(opt)
				{
					case '1':
						{
							goto n;	
						}
					case '2':
						{
							goto m;
						}
					default:
						cout<<"Enter valid input ! ";
						goto o;
				}
			}
			break;
		}
		
		case '2':
		{
		  	buyer();
		  	
		  	break;
		}
			
		case '3':	
		{
		    exit(0);
		    break;
		}
			
		default:
			{
			cout<<"Please select from the given options(1-3)";
			}
		    	
	}
	goto m;
}

void shopping::administrator()
{
	m:
	char choice;
	
	cout<<"\n\n\n\t\t\tADMINISTRATOR MENU";
    cout<<"                              \n";
    
    cout<<"\n\nYou want to? ";
    cout<<"\n\t\t\t|____1) View the products____|";
	cout<<"\n\t\t\t|                            |";
	cout<<"\n\t\t\t|____2) Add the Product______|";
	cout<<"\n\t\t\t|                            |";
	cout<<"\n\t\t\t|____3) Modify the Product___|";
	cout<<"\n\t\t\t|                            |";
	cout<<"\n\t\t\t|____4) Delete the Product___|";
    cout<<"\n\t\t\t|                            |";
	cout<<"\n\t\t\t|________5) View Bills_______|";
    cout<<"\n\t\t\t|                            |";
	cout<<"\n\t\t\t|____6) Back to main menu____|";
	
    cout<<"\n\nPlease enter your choice: ";
    cin>>choice;
    
    system("CLS");
    
    switch(choice)
    {
    	case '1':
    	{
    		list();
    		break;
		}
		
    	case '2':
    	{
    		add();
    		break;
		}
		
		case '3':
		{
			edit();
			break;
		}	
		
		case '4':
		{
			rem();
			break;
		}	
		
		case '5':
		{
			bill();
			break;	
		}
		case '6':
		{
			menu();
			break;	
		}
		
		default:
			cout<<"Invalid choice";
			cout<<"\nPlease Enter Your Choice Again!";
			sleep(3);
			
	}
    goto m;
}

void shopping::buyer()
{ 
    m:
	char choice;

	cout<<"\n\n\t\t\t BUYER MENU \n"; 
	cout<<"                           \n";
	cout<<"\t\t\t|___1) View the shop_____|\n";
	cout<<"\t\t\t|                        |\n";
	cout<<"\t\t\t|___2) Buy the product___|\n";
	cout<<"\t\t\t|                        |\n";
	cout<<"\t\t\t|___3) Go to back________|\n";
	
	cout<<"Please enter your choice:";
	cin>>choice;
	
	system("CLS");

	switch(choice)
	{
		case '1':
		{
			list();
			break;
		}
		
		case '2':
		{
			receipt();
			exit(0);
		}
		
		case '3':
		{
			menu();	
			break;
		}
		
		default:
			cout<<"Invalid choice";
	}
	goto m;  
}

void shopping::add()
{
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Original record: \n";
    list();
    cout << "\n\n\t\t\t Add new product";
    cout << "\n\n\t Product code of the product: ";
    cin >> pcode;
    cout << "\n\t Name of the product: ";
	cin.ignore();
	getline(cin,pname,'.');
    cout << "\n\t Price of the product: ";
    cin >> price;
    cout << "\n\t Discount on the product: ";
    cin >> disc;

    data.open("abc.txt", ios::in);
    if (!data)
    {
        data.open("abc.txt", ios::app); 
        data << " " << pcode << " " << pname << " " << price << " " << disc << "\n";
        data.close();
    }
    else
    data>> c >> n >> p >> d;
    {
        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
                break;
            }
             data>> c >> n >> p >> d;
        }
        data.close();
    }

    if (token > 0)
    {
        cout << "\n\t\tProduct with code " << pcode << " already exists. Please enter a different code.\n";
    }
    else
    {
        data.open("abc.txt", ios::app);
        data << " " << pcode << " " << pname << " " << price << " " << disc << "\n";
        data.close();
        cout << "\n\t\tRecord inserted!";
        cout << "\n\t\tNew product details:\n";
		cout << "\t\t\t" << pcode << "\t\t" << pname << "\t" << setw(13) << price << "\n";
    }
}

void shopping::edit()
{
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\n\t\t\t Original record: \n";
    list();
	cout<<"\n\t\t\t Modify the record";
	cout<<"\n\t\t\t Product code: ";
	cin>>pkey;
	
	data.open("abc.txt",ios::in);
	if(!data)
	{
		cout<<"\nFile doesnot exist!";
	
	}
	else
	{
		data1.open("temp.txt",ios::app);
		
		data>>pcode>>pname>>price>>disc;
		while(!data.eof())
		{
			if(pkey==pcode)
			{
				cout<<"\n\t\t Product new code: ";
				cin>>c;
				cout<<"\n\t\t Name of the product: ";
				cin.ignore();
				getline(cin,pname,'.');
				cout<<"\n\t\t Price: ";
				cin>>p;
				cout<<"\n\t\t Discount: ";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\n\t\t Record Edited!";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<disc<<"\n";
			}
			data>>pcode>>pname>>price>>disc;
		}
		data.close();
		data1.close(); 
		
		remove("abc.txt");
		rename("temp.txt","abc.txt");
		
		if(token==0)
		{
			cout<<"\n\n Record not found sorry!";
		}
	}
}

void shopping::rem()
{
	fstream data,data1;
	int pkey;
	int token=0;
	
	cout<<"\n\t\t\t Original record: \n";
    list();
	cout<<"\n\n\t Delete product";
	cout<<"\n\n\t Product code:";
	cin>>pkey;
	data.open("abc.txt",ios::in);
	if(!data)
	{
		cout<<"File doesnot exist";
	}
	else
	{
		data1.open("temp.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>disc;
		while(!data.eof())
		{
			if(pcode==pkey)
			{
				cout<<"\n\n\t Product deleted successfully";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<disc<<"\n";
			}
			data>>pcode>>pname>>price>>disc;
		}
		data.close();
		data1.close();
		remove("abc.txt");
		rename("temp.txt","abc.txt");
		
		if(token==0)
		{
		     cout<<"\n\n\t Record not found!"; 	
		}
	}
}

void shopping::list()
{
	fstream data;
	data.open("abc.txt",ios::app | ios::in);
	cout<<"\n\n\t\t\t______________________________________________________\n";
	cout<<"\t\t\tProdNo\t\tName\t\t\t\tPrice";
	cout<<"\n\t\t\t______________________________________________________\n";
    data>>pcode>>pname>>price>>disc;
    while(!data.eof())
    {

		if(pname.length()<=7)
    		cout<<"\t\t\t"<<pcode<<"\t\t"<<pname<<"\t"<<setw(28)<<price<<"\n";
    	else
    		cout<<"\t\t\t"<<pcode<<"\t\t"<<pname<<"\t"<<setw(20)<<price<<"\n";
    	data>>pcode>>pname>>price>>disc;
	}
	cout<<"\n\t\t\t_______________________________________________________\n";
	data.close();
}

void shopping::receipt()
{
    fstream data;
    fstream outFile("Bill.txt",ios::app);

    int arrc[100];
    int arrq[100];
    char choice;
    string Bname;
    int c = 0;
    float total = 0;
    float t=0;

    cout << "\n_____________________________________\n";
    cout << "\n\t PRODUCTS AVAILABLE";
        list();
        cout << "_____________________________________\n";
        cout << "\n  Please place the order  \n";
        cout << "_____________________________________\n";
        cout<<"\tEnter Your First Name : ";
        cin.ignore();
        getline(cin,Bname,'.');

        do
        {
           m:
            cout << "\n\n\tEnter product code: ";
            cin >> arrc[c];
            cout << "\n\tEnter product quantity: ";
            cin >> arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\t Duplicate product code. Please try again";
                    goto m;
                }
            }
            c++;
            cout << "\n\tDo you want to buy another product? y or n?";
            cin >> choice;
        } while (choice == 'y');
        
	    system("CLS");
        
        cout << "\n\n\t\t\t\t__________________RECEIPT_________________\n";
       
        cout << "\nProduct No.\t Product Name\t Product quantity \t  Price\t\tDiscount\tPrice after discount\n";

        for (int i = 0; i < c; i++)
        {
            data.open("abc.txt", ios::in);
            data >> pcode >> pname >> price >> disc;
            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    float amount = price * arrq[i];
                    total = amount-disc*arrq[i];
                   if(pname.length()<6)
				   {	
						cout << "\n  " << pcode << "\t\t  " << pname << "\t\t\t" << arrq[i] << "\t\t  " << price << "\t\t " << arrq[i]*disc << "\t\t  " << total;
						outFile << Bname<< "\t\t"<< pcode << "\t\t  " << pname << "\t\t\t" << arrq[i] << "\t\t  " << price << "\t\t " << arrq[i]*disc << "\t\t  " << total<<endl;
					}
					else{	
						cout << "\n  " << pcode << "\t\t  " << pname << "\t\t" << arrq[i] << "\t\t  " << price << "\t\t " << arrq[i]*disc << "\t\t  " << total;
						outFile << Bname<< "\t\t"<< pcode << "\t\t  " << pname << "\t\t" << arrq[i] << "\t\t  " << price << "\t\t " << arrq[i]*disc << "\t\t  " << total<<endl;
					}
					
                }
                data >> pcode >> pname >> price >> disc;
            }
            t+=total;

            data.close();
        }
        outFile.close();
       // system("notepad/p Bill.txt");
   	    cout << "\n\n\t\t\t\t_____________________________________";
        cout << "\n\t\t\t\t\t Total Amount: " << t;
        cout << "\n\t\t\t\t_____________________________________\n";

}
void shopping::bill()
{
	int count=0;
	float total = 0;
    int Q;
    float tdisc;
	fstream outfile;
	outfile.open("bill.txt",ios::in|ios::out);
	
	cout<<"Bname\t\tProdNo\t\tpname\t\tQuantity\tPrice\t\ttdisc\t\ttotal";
    outfile>>bname>>pcode>>pname>>Q>>price>>tdisc>>total;
	while(!outfile.eof()) 
	{
		cout<<"\n"<<bname<<"\t\t"<<pcode<<"\t\t"<<pname<<"\t\t"<<Q<<"\t\t"<<price<<"\t\t"<<tdisc<<"\t\t "<<total;
		outfile>>bname>>pcode>>pname>>Q>>price>>tdisc>>total;
			
	}
	outfile.close();
}

int main()
{
	system("color 70");
	shopping s;
	s.menu(); 	   
	return 0;
}
