#include<iostream>
#include<queue>
using namespace std;
int main()
{
    priority_queue<int> pq; // By default priority_queus is max-heap
    pq.push(100);
    pq.push(21);
    pq.push(7);
    pq.push(165);
    pq.push(78);
    pq.push(4);

    cout<<pq.size()<<endl;
    cout<<pq.top()<<endl;
    cout<<pq.empty()<<endl;
    while(!pq.empty())
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
}