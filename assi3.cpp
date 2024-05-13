/*Assignment-3,Snehal Bhamare, 08A
Activity on vertex(AOV) network: Sandy is a well organized person.
Every day he makes a list of things which need to be done and
enumerates them from 1 to n. However, some things need to be done
before others. Write a C++ code to find out whether Sandy can solve all
his duties and if so, print the correct order*/
#include <iostream>
#include <string.h>
#include <stack>
#include <queue>
#define max 10
using namespace std;

class graph
{
    public:
    		int mat[max][max];
    		int vertex;
    		int visited[max];
    		int indegree[max];
    		queue <int> zeroArray;
    		graph(int v)
    		{
      			vertex=v; 
      			for(int i=1;i<=vertex;i++)
       			{
        			for(int j=1;j<=vertex;j++)
        			{
            			mat[i][j]=0;
        			}
       			}
				for(int i=1;i<=vertex;i++)
      			{
        			visited[i]=0;
      			}
    		}
    		int indegreeCount(int k)
    		{
        		int a=0;
        		for(int i=1;i<=vertex;i++)
        		{
            		if(mat[i][k]==1)
            		{
                		a=a+1;
            		}
        		}
				return a;
    		}
  			void addEdge(int u,int v)
  			{
    			mat[u][v]=1;
  			}
    		void display()
       		{
        		for(int i=1;i<=vertex;i++)
        		{
            		for(int j=1;j<=vertex;j++)
            		{
                		cout << mat[i][j] << "\t";
            		}
            		cout << endl;
        		}
       		}
			void pushZero()
			{
				for(int i=1;i<=vertex;i++)
    			{
      				if(indegreeCount(i)==0 && visited[i]==0)
      				{
        				zeroArray.push(i);
        				visited[i]=1;
      				}
    			}
			}
			void updateMatrix(int i)
			{
  				for(int j=1;j<=vertex;j++)
    			{
      				if(mat[i][j]!=0)
      				{
        				mat[i][j]=0;
      				}
    			}
			}
			void topologicalOrder()
			{
    			pushZero();
    			queue <int> answer;
    			int k;
    			while(!zeroArray.empty())
      			{
        			k=zeroArray.front();
        			answer.push(k);
        			zeroArray.pop();
        			updateMatrix(k);
        			pushZero();
      			}
  				while(!answer.empty())
    			{
      				cout << answer.front() << "->";
      				answer.pop();
    			}
			}
};

int main()
{
  	cout << "Enter number of jobs to be done by Sandy : ";
  	int k;
  	cin >> k;
  	graph obj(k);
  	int u,v;
  	int count;
  	int choice;
  	do
  	{
  		cout << "For edge" << count+1 << endl;
  		cout << "Enter source vertex : ";
      	cin >> u;
      	cout << "Enter destination vertex : ";
      	cin >> v;
    	obj.addEdge(u,v);
    	count++;
    	cout << "Do you want to continue ('1' for 'yes'&'0' for 'no')? : ";
    	cin >> choice;
  	}while(choice!=0);
  	obj.topologicalOrder();
  	return 0;
}

/*
Enter number of jobs to be done by Sandy : 5
For edge1
Enter source vertex : 1
Enter destination vertex : 2
Do you want to continue ('1' for 'yes'&'0' for 'no')? : 1
For edge2
Enter source vertex : 1
Enter destination vertex : 4
Do you want to continue ('1' for 'yes'&'0' for 'no')? : 1
For edge3
Enter source vertex : 2
Enter destination vertex : 3
Do you want to continue ('1' for 'yes'&'0' for 'no')? : 1
For edge4
Enter source vertex : 2
Enter destination vertex : 4
Do you want to continue ('1' for 'yes'&'0' for 'no')? : 1
For edge5
Enter source vertex : 4
Enter destination vertex : 3
Do you want to continue ('1' for 'yes'&'0' for 'no')? : 1
For edge6
Enter source vertex : 4
Enter destination vertex : 5
Do you want to continue ('1' for 'yes'&'0' for 'no')? : 0
1->2->4->3->5->%
*/
