#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<iomanip>
using namespace std;

// Patient Class
class Patient
{
	int pr;
	char name[20];
	Patient* next;
	Patient(char n[], int p)
	{
		pr=p;
		strcpy(name,n);
		next=NULL;
	}
	// Display Patient info
	void showPatient()
	{
		cout<<setw(20)<<name<<setw(20);
		if(pr==1)
			cout<<"General Chech-Up\n";
		else if(pr==2)
			cout<<"Half Serious\n";
		else
			cout<<"Serious\n";
	}
	friend class DB;
};

// DataBase Class (Patient record)
class DB
{
		Patient* head;
	public:
		DB():head(NULL){}
		
		// Insert patient according to priority
		void insert(char n[], int pat)
		{
			Patient* p=new Patient(n, pat);
			if(!head)
				head=p;
			else if(p->pr > head->pr)
			{
				p->next=head;
				head=p;
			}
			else
			{
				Patient* q;
				for(q=head ; q->next!=NULL && q->next->pr >= p->pr ; q=q->next);
				if(!q->next)
					q->next=p;
				else
				{
					p->next=q->next;
					q->next=p;
				}
			}
		}
		
		// Provide service to first patient inside DB
		void svc()
		{
			if(!head)
				cout<<"Currently no Patients in DB\n";
			else
			{
				cout<<"\nService is Provided to\n";
				cout<<setw(20)<<"Name"<<setw(20)<<"Priority\n";
				head->showPatient();
				head=head->next;
			}
		}
		
		// Display Database
		void showDB()
		{
			if(!head)
				cout<<"\nCurrently no patients in DB\n";
			else
			{
				cout<<"\n\n\t\t--> Patient DataBase <--\n\n";
				cout<<setw(20)<<"Name"<<setw(20)<<"Priority\n";
				for(Patient* q=head ; q ; q=q->next)
					q->showPatient();
			}
		}
};

int main()
{
	//clrscr();
	int ch, pr;
	char name[20];
	DB db;
	do{
		cout<<"\n --> MENU <--\n";
		cout<<"\n1) Add new patient\n2) Provide Service\n3) Display Patient List\n4) Quit\n";
		cout<<"\nEnter your choice --> ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter name of Patient :: ";
				cin>>name;
				cout<<"\nEnter '3' for serious\nEnter '2' for Half-serious\nEnter '1' for General Check-Up\n";
				cout<<"\nEnter priority --> ";
				cin>>pr;
				db.insert(name, pr);
				break;
			case 2:
				db.svc();
				break;
			case 3:
				db.showDB();
				break;
			case 4:
				exit(1);
			default:
				cout<<"\nInvalid Choice ....";
		}
	}while(1);
}
/*
Output ::


 --> MENU <--

1) Add new patient
2) Provide Service
3) Display Patient List
4) Quit

Enter your choice --> 3

Currently no patients in DB

 --> MENU <--

1) Add new patient
2) Provide Service
3) Display Patient List
4) Quit

Enter your choice --> 1

Enter name of Patient :: PPP

Enter '3' for serious
Enter '2' for Half-serious
Enter '1' for General Check-Up

Enter priority --> 2

 --> MENU <--

1) Add new patient
2) Provide Service
3) Display Patient List
4) Quit

Enter your choice --> 1

Enter name of Patient :: JJJ

Enter '3' for serious
Enter '2' for Half-serious
Enter '1' for General Check-Up

Enter priority --> 1

 --> MENU <--

1) Add new patient
2) Provide Service
3) Display Patient List
4) Quit

Enter your choice --> 1

Enter name of Patient :: HHH

Enter '3' for serious
Enter '2' for Half-serious
Enter '1' for General Check-Up

Enter priority --> 3

 --> MENU <--

1) Add new patient
2) Provide Service
3) Display Patient List
4) Quit

Enter your choice --> 1

Enter name of Patient :: RRR

Enter '3' for serious
Enter '2' for Half-serious
Enter '1' for General Check-Up

Enter priority --> 3

 --> MENU <--

1) Add new patient
2) Provide Service
3) Display Patient List
4) Quit

Enter your choice --> 1

Enter name of Patient :: YYY

Enter '3' for serious
Enter '2' for Half-serious
Enter '1' for General Check-Up

Enter priority --> 2

 --> MENU <--

1) Add new patient
2) Provide Service
3) Display Patient List
4) Quit

Enter your choice --> 3


		--> Patient DataBase <--

                Name           Priority
                 HHH            Serious
                 RRR            Serious
                 PPP       Half Serious
                 YYY       Half Serious
                 JJJ   General Chech-Up

 --> MENU <--

1) Add new patient
2) Provide Service
3) Display Patient List
4) Quit

Enter your choice --> 2

Service is Provided to
                Name           Priority
                 HHH            Serious

 --> MENU <--

1) Add new patient
2) Provide Service
3) Display Patient List
4) Quit

Enter your choice --> 2

Service is Provided to
                Name           Priority
                 RRR            Serious

 --> MENU <--

1) Add new patient
2) Provide Service
3) Display Patient List
4) Quit

Enter your choice --> 3


		--> Patient DataBase <--

                Name           Priority
                 PPP       Half Serious
                 YYY       Half Serious
                 JJJ   General Chech-Up

 --> MENU <--

1) Add new patient
2) Provide Service
3) Display Patient List
4) Quit

Enter your choice --> 4



*/