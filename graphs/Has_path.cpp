#include <iostream>
#include <queue>
using namespace std;
void print(int **edge, int n, int sv,int ev, bool *visited)
{
    queue<int> q;
    q.push(sv);
    
    int j = sv ;
   while(!q.empty())
    {
       
        for (int i = 0; i<n; i++)
        {
            
            if(j == ev)
            {
                cout<<"Yes";
                return;
            }
            if (edge[j][i] == 1)
            {
                if(visited[i] == true)
                {
                    continue;
                }
                q.push(i);
                visited[i] = true;
            }
        }
         visited[j] = true;
        q.pop();
        j = q.front();
        
    }
    cout<<"No"<<endl;
}
int main()
{
    int n, e;
    cin >> n >> e;
    int **edge = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edge[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edge[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int s, f;
        cin >> s >> f;
        edge[s][f] = 1;
        edge[f][s] = 1;
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    int start,end;
    cin>>start>>end;

    print(edge, n, start,end, visited);

    for (int i = 0; i < n; i++)
    {
        delete[] edge[i];
    }

    delete[] edge;
}