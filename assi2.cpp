#include<iostream>
#include<stack>
#include<queue>

using namespace std;

class Graph
{
    public: 
        int n; 
        int adjmat[8][8];
        
        Graph(int v): n(v) {}

        void addEdge(int u, int v)
        {
            adjmat[u][v]=1;
            adjmat[v][u]=1;
        }

        void admat()
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    adjmat[i][j]=0;
                }
            }
        }

        void dismat()
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    cout<<" "<<adjmat[i][j]<<" ";
                }
                cout<<endl;
            }
        }

        void disp()
        {
            for(int i=0; i<n; i++)
            {
                cout<<i<<"->";
                for(int j = 0; j < n; j++)
                {
                    if(adjmat[i][j] == 1)
                        cout<<j<<" ";
                }
                cout<<endl;
            }
        }

        void DFS(int s)
        {
            bool *visited = new bool[n];
            for(int i = 0; i < n; i++)
                visited[i] = false;

            cout<<"Starting Node is : "<<s<<endl;
            traversing(s, visited);
            cout<<endl;
            
            delete [] visited;
        }

        void traversing(int s, bool *visited)
        {
            cout<<s<<" ";
            visited[s]=true;
            for(int i = 0; i < n; i++)
            {
                if(adjmat[s][i] == 1 && !visited[i])
                {
                    traversing(i, visited);
                }
            }
        }

        void BFS(int s)
        {
            bool *visited = new bool[n];
            for(int i = 0; i < n; i++)
                visited[i] = false;

            cout<<"Starting Node is : "<<s<<endl;
            queue <int> q;
            visited[s]=true;
            q.push(s);

            while(!q.empty())
            {
                int current = q.front();
                q.pop();
                cout<<current<<" ";

                for(int i = 0; i < n; i++)
                {
                    if(adjmat[current][i] == 1 && !visited[i])
                    {
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }
            cout<<endl;

            delete [] visited;
        }
};

int main()
{
    int v = 8;
    int src, dest, bfs, dfs, con=1;
    Graph g(v);
    g.admat();

    do
    {
        int ch;
        cout<<"---------- M E N U ----------"<<endl;
        cout<<"1. Add Edge."<<endl;
        cout<<"2. Show Matrix."<<endl;
        cout<<"3. Show List."<<endl;
        cout<<"4. DFS."<<endl;
        cout<<"5. BFS"<<endl;
        cout<<"Enter your choice : ";
        cin>>ch;

        switch(ch)
        {
            case 1 : cout<<"Enter Edge (source & Destination) : ";
                     cin>>src>>dest;
                     g.addEdge(src, dest);
                     cout<<"Edge Added..."<<endl;
                     break;

            case 2 : g.dismat();
                     break;

            case 3 : g.disp();
                     break;

            case 4 : cout<<"Enter the Starting Node : "<<endl;
                     cin>>dfs;
                     g.DFS(dfs);
                     break;

            case 5 : cout<<"Enter the Starting Node : "<<endl;
                     cin>>bfs;
                     g.BFS(bfs);
                     break;

            default : cout<<"Invalid Choice. Please try Again..."<<endl;                  
        }
        cout<<"Want to Proceed..? (YES=1, NO=0)"<<endl;
        cin>>con;
    }
    while(con!=0);
    return 0;
}
