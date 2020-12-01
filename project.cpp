#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<map>
#include<bits/stdc++.h>
#include<windows.h>

COORD c={0,0};
void gotoxy(int x,int y)
{
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}


#define v 19

using namespace std;

vector<int>path;
vector<string>stations_list;

void print_path(int parent[],int destination);
void dijkstra(float edges[v][v],int source,int destination);
void create_user();
int user_check(char[15],char[15]);
void admin_login();
void show_user();
void del_user();
void create_train();
void show_train();
void train_search(long int);
void store_data();
long int pnr_gen(int,int,int);
void print_ticket();
void booking();

using namespace std;

int i=3;
long int pnr;
string source_location,destination_location;
int source,destination;
float edges[v][v]={{0,0,862,0,0,1854,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,291,0,0,0,0,0,0,0,0,0,0,0,0,1911},
                        {862,0,0,0,0,0,0,0,0,0,0,1686,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,1002,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,376,0,0,0,0,0,0,0,0,0,0,0},
                        {1854,291,0,0,0,0,0,1899,0,0,0,0,0,0,1954,0,0,0,1107},
                        {0,0,0,0,0,0,0,0,0,0,0,620,0,0,0,0,1395,0,0},
                        {0,0,0,1002,376,1899,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,2477,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,2516,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,2477,0,0,0,0,0,0,1280,0,0,0},
                        {0,0,1686,0,0,0,620,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,2516,0,0,0,0,0,0,0,1780,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1607},
                        {0,0,0,0,0,1954,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,1280,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,1395,0,0,0,0,0,0,0,0,0,0,976,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,1780,0,0,0,976,0,2969},
                        {0,1911,0,0,0,1107,0,0,0,0,1411,0,0,1607,0,0,0,2969,0}};


class train
{
    public:
    long int t_no,h,m;
    char tname[15],b_station[15],dest[15];


    void getdata()
    {
        gotoxy(45,1);
        cout<<"Enter train no. ";
        cin>>t_no;
        cin.ignore();
        gotoxy(45,3);
        cout<<"Enter Train Name ";
        cin>>tname;
        cin.ignore();
        gotoxy(45,5);
        cout<<"Enter Boarding Station ";
        cin>>b_station;
        cin.ignore();
        gotoxy(45,7);
        cout<<"Enter Destination ";
        cin>>dest;
        cin.ignore();
        gotoxy(45,9);
        cout<<"Enter Travel Time ";
        cin>>h>>m;
        cin.ignore();
    }

    void showdata()
    {
        gotoxy(5,i);
        cout<<t_no;
        gotoxy(20,i);
        cout<<tname;
        gotoxy(40,i);
        cout<<b_station;
        gotoxy(60,i);
        cout<<dest;
        gotoxy(80,i);
        cout<<h<<":"<<m;
        i++;
    }


}t;

class passenger
{
    public:
    char pno[10],pname[15][15],gen[15];
    int d,m,y,d1,m1,y1,seats,age[20];
    void getdata()
    {
        gotoxy(45,1);
        cout<<"Enter date of boarding ";
        cin>>d>>m>>y;
        gotoxy(45,3);
        cout<<"Enter date of De-boarding ";
        cin>>d1>>m1>>y1;
        gotoxy(45,5);
        cout<<"Enter your phone no. ";
        cin>>pno;
        gotoxy(45,7);
        cout<<"Enter the no. of seats required ";
        cin>>seats;
        for(int i=0; i<seats; i++)
        {
            gotoxy(45,9);
            cout<<"Passenger name: ";
            cin>>pname[i];
            gotoxy(45,11);
            cout<<"Passenger age: ";
            cin>>age[i];
            gotoxy(45,13);
            cout<<"Gender:(M/F) ";
            cin>>gen[i];
        }
        store_data();

    }


}p;



void store_data()
{
    fstream fin;
    fin.open("passenger.txt",ios::in | ios::out);
    fin.write((char*)&p,sizeof(p));
    fin.close();
}

void booking()
{
    system("cls");
    long int a,z;
    char sel,ch;
    gotoxy(45,1);
    cout<<"Enter train no. ";
    cin>>a;
    train_search(a);
    gotoxy(45,6);
    cout<<"Continue to booking?.....(y/n)"<<endl;
    cin>>sel;
    system("cls");
    if(sel=='Y' || sel=='y')
    {
        p.getdata();

    }
    system("pause");
    system("cls");
    gotoxy(45,0);
    cout<<"Ticket Booked Successfully";
    int lower=66666666;
    int upper=99999999;
    int count=1;
    z=pnr_gen(lower=66666666,upper=99999999,count=1);
    pnr=z;
    gotoxy(45,1);
    cout<<"Your PNR no. is - "<<z;
    gotoxy(45,5);
    cout<<"Do you want to print your ticket(Y/N) ";
    cin>>ch;
    if(ch=='Y' || ch=='y')
    {
        system("cls");
        print_ticket();
    }



}


long int pnr_gen(int lower=66666666, int upper=99999999, int count=1)
{
    int i,num; srand(time(0));
    for(i=0; i<count; i++)
    {
        num = (rand() % (upper-lower + 1)) + lower;
    }
    return num;
}

void print_ticket()
{
    char ch;
    fstream fin;
    fstream rin;
    fin.open("passenger.txt",ios::in);
    fin.read((char*)&p,sizeof(p));
    rin.open("booking details",ios::in);
    rin.read((char*)&t,sizeof(t));
    cout<<"\n\t\t\t------------------------------------------------------------------------------------\n";
    cout<<"\n\t\t\t\t\t\t\tIRCTC RAILWAYS\n";
    cout<<"\n\t\t\t------------------------------------------------------------------------------------\n";
    cout<<"\n\t\t\tE-ticket\t\t";
    cout<<"\t\t\t\t\t\tPNR NO:"<<pnr;
    cout<<"\n\n\t\t\t\t\t\tPHONE NO. :\t"<<p.pno;
    cout<<"\n\n\t\t\t\t\t\tTRAIN NO.  :\t"<<t.t_no;
    cout<<"\n\n\t\t\t\t\t\tTRAIN NAME  :\t"<<t.tname;
    cout<<"\n\n\t\t\t\t\t\tBOARDING STATION :\t"<<t.b_station;
    cout<<"\n\n\t\t\t\t\t\tDESTINATION :\t"<<t.dest;
    cout<<"\n\n\t\t\t\t\t\tJOURNEY DATE  :\t"<<p.d<<p.m<<p.y;
    cout<<"\n\n\t\t\t\t\t\tARRIVAL DATE :\t"<<p.d1<<p.m1<<p.y1;
    cout<<"\n\t\t\t------------------------------------------------------------------------------------\n";
    cout<<"\n\n\t\t\tPASSENGERS\t"<<"\tAGE\t"<<"\t\tGENDER\n";
    for(int i=0;i<p.seats; i++)
	{
	    cout<<"\n\t\t\t"<<p.pname[i]<<"\t\t\t"<<p.age[i]<<"\t\t\t"<<p.gen[i];
	}
	cout<<"\n\t\t\t------------------------------------------------------------------------------------\n";
    fin.close();

    cout<<"Do you want to get more details(Y/N) ";
    cin>>ch;
    if(ch=='Y' || ch=='y')
    {
        cin.ignore();
        cout<<"\n\tEnter your Boarding Station: ";
        getline(cin,source_location);
        auto source_itr=find(stations_list.begin(),stations_list.end(),source_location);
        if(source_itr!=stations_list.end())
        {
            source=source_itr-stations_list.begin();
        }
        cout<<"\n\tEnter your Destination: ";
        getline(cin,destination_location);
        auto destination_itr=find(stations_list.begin(),stations_list.end(),destination_location);
        if(destination_itr!=stations_list.end())
        {
            destination=destination_itr-stations_list.begin();
        }
        dijkstra(edges,source,destination);

    }






}


void train_search(long int a)
    {

        system("cls");
        char found='n';
        fstream fin;
        fstream rin;
        fin.open("train.txt",ios::in);
        rin.open("booking details",ios::out);
        while(!fin.eof())
        {
            fin.read((char*)&t,sizeof(t));
            if(t.t_no==a)
            {
                rin.write((char*)&t,sizeof(t));
                gotoxy(5,2);
                cout<<"Train no.";
                gotoxy(20,2);
                cout<<"Train name";
                gotoxy(40,2);
                cout<<"Boarding station";
                gotoxy(60,2);
                cout<<"Destination";
                gotoxy(80,2);
                cout<<"Travel Time";
                t.showdata();
                found='y';
            }
        }
        if(found=='n')
        {
            system("cls");
            gotoxy(45,10);
            cout<<"Train cannot be found"<<endl;
            gotoxy(45,11);
            system("pause");
        }
        fin.close();


    }

void create_train()
{
    x:
    system("cls");
    char s;

        t.getdata();
        fstream fin;
        fin.open("train.txt",ios::in | ios::out | ios::app | ios::binary);
        fin.write((char*)&t,sizeof(t));
        fin.close();

        cout<<"Another details(y/n)?...."<<endl;
        cin>>s;

        if(s=='y'|| s=='Y')
        {
            goto x;
        }

}

void show_train()
{
    system("cls");
    fstream fin;
    fin.open("train.txt",ios::in | ios::out);
    fin.seekg(0);
    gotoxy(5,2);
    cout<<"Train no.";
    gotoxy(20,2);
    cout<<"Train name";
    gotoxy(40,2);
    cout<<"Boarding station";
    gotoxy(60,2);
    cout<<"Destination";
    gotoxy(80,2);
    cout<<"Travel Time"<<endl;
    while(!fin.eof())
    {
        fin.read((char*)&t,sizeof(t));
        t.showdata();
    }
    fin.close();
    system("pause");
}



void admin_login(char u2[10],char p2[10])
{
    system("cls");
    int j=0;
    char A[10],B[10];
    ifstream tin;
    ifstream rin;

	tin.open("admin.txt",ios::out);
	rin.open("adminpass.txt",ios::out);
	while(!tin.eof())
	{

        tin.getline(A,10);
		rin.getline(B,10);
		for(int i=0;u2[i]!='\0';i++)
		{
			if(u2[i]==A[i]&&p2[i]==B[i])
			{
			    gotoxy(45,6);
			    cout<<"Login success\n";
			    gotoxy(45,7);
			    system("pause");
			    break;
			}
			else
			{
			    gotoxy(45,6);
				cout<<"username and password not match....\n\tACCESS DENIED!!!!!";
				gotoxy(45,7);
				system("pause");
				break;
			}
																						//cout<<"\t i:"<<i<<"\tj:"<<j<<end|;
		}
	}

	if(j==0)
	{
	int c=0;
	A:system("cls");
        gotoxy(45,1);
	    cout<<"ADMIN MODE";
	    gotoxy(45,4);
        cout<<"1-->USERS MANAGEMENT:-";
        gotoxy(45,6);
        cout<<"2-->TRAINS MANAGEMENT:-";
        gotoxy(45,8);
        cout<<"Choose 1/2?";
        cin>>c;



		  if(c==1)
    	  {
		  	c=0;
 			B:
 			    system("cls");
 			    gotoxy(45,1);
 			    cout<<"USER MANAGEMENT SYSTEM";
 			    gotoxy(45,4);
				cout<<"1. CREATE NEW USERS";
				gotoxy(45,6);
    			cout<<"2. SHOW USERS";
    			gotoxy(45,8);
    			cout<<"3. DELETE USERS";
    			gotoxy(45,10);
    			cout<<"4. PREVIOUS MENU";
    			cin>>c;
    			switch(c)
    			{
				  	case 1:create_user();
				  	goto B;
           			break;
        			case 2:show_user();
        			goto B;
           			break;
        			case 3:system("cls");
        			    del_user();
        			goto B;
           			break;
        			case 4:goto A;
           			break;
       				default: cout<<"invalid selection!!!"; goto B;
    			}

    	  }
    	  else if(c==2)
    	  {
    	  	c=0;
            C:
                system("cls");
                gotoxy(45,1);
                cout<<"Train Management";
                gotoxy(45,4);
      			cout<<"1. ADD NEW TRAIN";
      			gotoxy(45,6);
         		cout<<"2. SHOW TRAINS";
         		gotoxy(45,8);
         		cout<<"3. PREVIOUS MENU";
                cin>>c;
                switch(c)
                {
                	case 1:create_train();
                	goto C;
                    break;
                    case 2:show_train();
                    goto C;
                    break;
                    case 3:goto A;
                    break;
                    default:cout<<"invalid selection!!!";goto C;
				}

    	   }
           else
		   {
		   		cout<<"invalid selection";
               goto A;
           }
}
}

void create_user()
{
    char c='y',u[15],p[15];
    ofstream uout;
    ofstream pout;
    uout.open("user.txt",ios::app);
    pout.open("pass.txt",ios::app);
    while(c=='y'||c=='y')
    {
        D:
        system("cls");
        gotoxy(45,1);
        cout<<"ENTER NEW USERNAME: ";
        cin>>u;
        gotoxy(45,3);
        cout<<"ENTER PASSWORD: ";
        cin>>p;
        if(user_check(u,p) != 0)
        {
            uout<<u<<endl;
            pout<<p<<endl;
            gotoxy(45,5);
            cout<<"New User Created ";
            gotoxy(45,9);
            cout<<"Enter Next User(y/n)...";
            cin>>c;
            gotoxy(45,10);
            system("pause");
        }
        else
        {
            system("cls");
            gotoxy(45,10);
            cout<<"Username already exist!!!";
            gotoxy(45,11);
            system("pause");
            goto D;
        }
    }

}

int user_check(char u3[15] , char p3[15])
{
    int i,j = 0,r = 0;
	char u1[15],p1[15];


		ifstream uin;
		ifstream pin;
		uin.open("user.txt",ios::out);
		pin.open("pass.txt",ios::out);
		while(!uin.eof())
		{
			j = 0;
			uin.getline(u1,15);
			pin.getline(p1,15);
			if(strcmp(u1,u3)==0 && strcmp(p1,p3)==0)
				{
					j++;
					break;
				}
		}
        if(j==0)
        {
            r++;
            return r;
        }
        else
        {
            return r;
        }
}

void show_user()
{
    system("cls");
    char u1[15],p1[15];
	int i=0;
	ifstream uin;
	ifstream pin;
	uin.open("user.txt",ios::out);
	pin.open("pass.txt",ios::out);
	cout<<"username\tpassword\n";
	while(!uin.eof())
	{
		i++;
		uin.getline(u1,9);
		pin.getline(p1,9);
		cout<<i<<u1<<"\t\t"<<p1<<endl;
	}
	system("pause");
}

void del_user()
{
    system("cls");
    int i=0,j=0;
	char u1[15],p1[15];
	cout<<"to delete..... choose from list\n";
	show_user();
	cin>>i;
	ifstream uin;
	ifstream pin;
	uin.open("user.txt",ios::out);
	pin.open("pass.txt",ios::out);

	ofstream tempu;
	ofstream tempp;
	tempu.open("tuser.txt",ios::app);
	tempp.open("tpass.txt",ios::app);
	while(!uin.eof())
	{
		j++;
		uin.getline(u1,15);
		pin.getline(p1,15);
		if(uin.eof())
		{
			break;
		}
		if(i != j)
		{
			tempu<<u1<<endl;
			tempp<<p1<<endl;
		}
	}
	tempu.close();
	tempp.close();
	uin.close();
	pin.close();
	remove("user.txt");
	rename("tuser.txt","user.txt");
	remove("pass.txt");
	rename("tpass.txt","pass.txt");
	cout<<"USER DELETED!!!\n";
	system("pause");
}

int user_login()
{
	int j=0;
	char u2[15],p2[15];
	gotoxy(45,10);
	cout<<"enter uername: ";
	cin>>u2;
	gotoxy(45,12);
	cout<<"enter password: ";
	cin>>p2;
	j = user_check(u2,p2);
	if(j==0)
	{
	    system("cls");
	    gotoxy(45,1);
		cout<<"login successful";
		gotoxy(45,2);
		system("pause");
		return 0;
	}
	else
	{
		cout<<"invalid username and password"<<endl;
		system("pause");
		return 1;
	}
}

void user_mode()
{
    passenger p;
    int j = user_login();
    system("cls");
    if(j==0)
    {
        int ch;
        m:
        system("cls");
        gotoxy(45,1);
        cout<<"USER MODE";
        gotoxy(45,4);
        cout<<"1. Show all trains ";
        gotoxy(45,6);
        cout<<"2. Train Booking ";
        gotoxy(45,8);
        cout<<"3. Train Search ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                show_train();
                goto m;
                break;
            case 2:
                booking();
                goto m;
                break;
            case 3:
                long int tno;
                system("cls");
                gotoxy(45,10);
                cout<<"Train Search";
                gotoxy(45,12);
                cout<<"Enter Train no. ";
                cin>>tno;
                train_search(tno);
                gotoxy(45,10);
                system("pause");
                goto m;
                break;
        }


    }

}

void print_solution(float distance[],int n,int parent[],int source,int destination) //function to print distance and
{                                                                                 //call print_path function
    path.clear();
    cout<<"\n\nBoading station     Destination"<<endl;
    cout<<stations_list[source]<<" --> "<<stations_list[destination];
    cout<<"\n\nDistance(Km)"<<endl;
    cout<<distance[destination]<<" Km";
    cout<<"\n\nPath\n";
    cout<<stations_list[source];
    print_path(parent,destination);
    float prev;
    for(auto x:path)
    {
        cout<<" --> "<<stations_list[x];
    }
    cout<<endl;
    system("pause");

}

void print_path(int parent[],int destination) //function to print path between source and destination
{
    if(parent[destination]==-1)
    {
        return;
    }
    print_path(parent,parent[destination]);

    path.push_back(destination);
    //cout<<destination<<" ";

}

int find_min_vertex(float distance[],bool visited[],int n) // function to find min distance vertex
{
    int min_vertex=-1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i] &&(min_vertex==-1 || distance[i]<distance[min_vertex]) )
        {
            min_vertex=i;
        }
    }
    return min_vertex;
}

void dijkstra(float edges[v][v],int source,int destination) //function to implement dijkstra algorithm with some modification
{   path.clear();
    int n=v;
    float distance[n];
    bool visited[n];
    int parent[n]; //parent array to store the shortest path tree

    for(int i=0;i<n;i++)
    {
        parent[source]=-1;
        distance[i]=INT_MAX;
        visited[i]=false;
    }
    distance[source]=0; // distance of source vertex is 0
    for(int i=0;i<n;i++)
    {
        int min_vertex= find_min_vertex(distance,visited,n);
        visited[min_vertex]=true;
        for(int j=0;j<n;j++)
        {
            if(edges[min_vertex][j]!=0 && !visited[j]) // there should be an edge and the vertex should not be visited
            {
                float dist = distance[min_vertex] + edges[min_vertex][j];
                if(dist<distance[j])
                {
                    parent[j]=min_vertex;
                    distance[j]=dist;
                }
            }
        }
    }



    print_solution(distance,n,parent,source,destination);
}



int main()
{
    system("COLOR B0");

 	stations_list.push_back("kanpur");
 	stations_list.push_back("dhanbad");
 	stations_list.push_back("haridwar");
 	stations_list.push_back("howrah");
 	stations_list.push_back("dimapur");
 	stations_list.push_back("patna");
 	stations_list.push_back("jaipur");
 	stations_list.push_back("guwahati");
 	stations_list.push_back("bhubaneswar");
 	stations_list.push_back("thrisur");
 	stations_list.push_back("vijayawada");
 	stations_list.push_back("new delhi");
    stations_list.push_back("madgaon");
 	stations_list.push_back("bengaluru");
 	stations_list.push_back("itarsi");
 	stations_list.push_back("chennai");
 	stations_list.push_back("ahmedabad");
 	stations_list.push_back("mumbai");
 	stations_list.push_back("raipur");

    k:
    int ch;
    char u1[10],p1[10];
    gotoxy(45,1);
	cout<<"Welcome to Indian Railway"<<endl;
	gotoxy(45,4);
	cout<<"1. ADMIN LOGIN "<<endl;
	gotoxy(45,6);
	cout<<"2. USER LOGIN "<<endl;
	gotoxy(45,8);
	cout<<"3. REGISTER "<<endl;
	cin>>ch;
	switch(ch)
	{
	    case 1:gotoxy(45,10);
	        cout<<"Enter admin username ";
	        cin>>u1;
	        gotoxy(45,12);
	        cout<<"Enter password ";
	        cin>>p1;
	        admin_login(u1,p1);
	        goto k;
	        break;
        case 2:
            user_mode();
            goto k;
            break;
        case 3:
            create_user();
            goto k;
            break;
	}
}
