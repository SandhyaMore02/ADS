#include<iostream>
using namespace std;

class Flight
{
	public :
		int n;
		string name[10];
		float adtmat[50][50];
		int i,j;

	public :

	void totalcities()
	{
		cout<<"Enter total number of cities : "<<endl;
		cin>>n;
		cout<<"Enter name of cities : "<<endl;
		for(i=0;i<n;i++)
		{
			cout<<"City "<<(i+1)<<" : ";
			cin>>name[i];
			cout<<endl;
		}

		cout<<"Your cities are : "<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<"City "<<(i+1)<<" : ";
			cout<<name[i];
			cout<<endl;
		}
	}

	void option()
	{
		int op;
		cout<<"Enter Fuel Information."<<endl;
		cout<<"Fuel required to travel in litres:"<<endl;
			for(i=0;i<n;i++)
			{
				for(j=i+1;j<n;j++)
				{
					cout<<"From "<<name[i]<<" to "<<name[j]<<" :";
					cin>>adtmat[i][j];
				}
			}
	}

	void show()
	{
		cout<<"Representation of graph using Adjacency matrix:"<<endl;
		for(i=0;i<n;i++)
			cout<<"\t"<<name[i]<<" ";
		cout<<endl;
		for(i=0;i<n;i++)
		{
			cout<<name[i]<<"\t";
			for(j=0;j<n;j++)
			{
				cout<<adtmat[i][j]<<"\t";
			}
			cout<<endl;
		}
	}

	void printlist()
	{
		for (i= 0; i< n; i++)
		{
		    cout << "\n Vertex "<< name[i] << ":";
   
			for(j=(i+1);j<(n+1);j++)
			{
				if(name[j]!=name[n])
				{
   
				    cout << "-> " << name[j];

   
			    }
			    else
			    {
				    cout<<endl;
			    }
	    	}
   
		    cout<<endl;
	  	}

 
  	}
 
	void check()
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(adtmat[i][j]!=0)
				{
					cout<<"Flight is present in between "<<name[i]<<" to "<<name[j]<<endl;
				}
				else
				{
	   				cout<<"Flight is not present in between "<<name[i]<<" to "<<name[j]<<endl;
				}
			}
		}
	}
 
};

int main()
{
	Flight f;
	int ch;
	cout<<endl;
	cout<<"\t-----Welcome to the Flight Management-----"<<endl;
	cout<<endl;
	cout<<"1. Enter cities name\n";
	cout<<"2. Enter Fuel Information\n";
	cout<<"3. Display Directed Graph\n";
	cout<<"4. Check whether Flight is Present OR not\n";
	cout<<"5. Display Adjacency list\n";
	cout<<"6. Exit\n";

	do
	{
		cout<<"Choose option:"<<endl;
		cin>>ch;

		switch(ch)
		{

		case 1:f.totalcities();
  		break;
 
		case 2:f.option();
  		break;
 
		case 3:f.show();
  		break;
 
		case 4:f.check();
  		break;
 
		case 5:f.printlist();
  		break;
 
		default:cout<<"Exiting Flight Management...\nThank You...\n"<<endl;
		break;
		}
	}
	while(ch!=6);
 
	return 0;
}

/*
-----Welcome to the Flight Management-----

1. Enter cities name
2. Enter Fuel Information
3. Display Directed Graph
4. Check whether Flight is Present OR not
5. Display Adjacency list
6. Exit

Choose option:
1

Enter total number of cities : 
3
Enter name of cities : 
City 1 : New York
City 2 : Los Angeles
City 3 : Chicago

Your cities are : 
City 1 : New York
City 2 : Los Angeles
City 3 : Chicago

Choose option:
2

Enter Fuel Information.
Fuel required to travel in litres:
From New York to Los Angeles : 100
From New York to Chicago : 150
From Los Angeles to New York : 100
From Los Angeles to Chicago : 120
From Chicago to New York : 150
From Chicago to Los Angeles : 120

Choose option:
3

Representation of graph using Adjacency matrix:
New York  Los Angeles  Chicago 
Los Angeles  New York 100  Chicago 120 
Chicago  New York 150  Los Angeles 120 

Choose option:
4

Flight is present in between New York to Los Angeles
Flight is present in between New York to Chicago
Flight is present in between Los Angeles to New York
Flight is present in between Los Angeles to Chicago
Flight is present in between Chicago to New York
Flight is present in between Chicago to Los Angeles

Choose option:
5

Vertex New York : -> Los Angeles -> Chicago -> 
Vertex Los Angeles : -> New York -> Chicago -> 
Vertex Chicago : -> New York -> Los Angeles -> 

Choose option:
6

Exiting Flight Management...Thank You...
*/