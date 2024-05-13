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
