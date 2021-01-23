#include<iostream>
using namespace std;
void print(int **edge,int n, int sv,bool *visited)
{
    cout<<sv<<" ";
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edge[sv][i] == 1)
        {
            if (visited[i] == true)
            {
                continue;
            }
            
            print(edge,n,i,visited);
        }
            
    }     
}
int main()
{
    int n,e;
    cin>>n>>e;
    int **edge = new int*[n];
    for (int i = 0; i < n; i++)
    {
        edge[i] = new int[n];
        for (int j = 0;  j< n; j++)
        {
            edge[i][j] = 0;
        }
        
    }
    for (int i = 0; i < e; i++)
    {
        int s,f;
        cin>>s>>f;
        edge[s][f] = 1;
        edge[f][s] = 1;
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    
    
    print(edge,n,0,visited);

    for (int i = 0; i < n; i++)
    {
        delete[] edge[i];
    }

    delete[] edge;
    

}