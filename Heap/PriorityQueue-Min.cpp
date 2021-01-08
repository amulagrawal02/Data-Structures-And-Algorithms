#include <iostream>
using namespace std;
#include <vector>
class PriorityQueues
{
    vector<int> pq;

public:
    PriorityQueues()
    {
    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {

        return pq.size();
    }
    int getMin()
    {
        if (pq.size() == 0)
        {
            return 0; // Our Priority Queue is Empty
        }

        return pq[0];
    }
    void heaporder_from_children(int element, int Index)
    {
        if (Index == 0)
        {
            return;
        }
        int parentIndex = (Index - 1) / 2;
        if (pq[parentIndex] < pq[Index])
        {
            return;
        }
        swap(pq[Index], pq[parentIndex]);
        heaporder_from_children(element, parentIndex);
    }

    void Insert(int element)
    {
        if (pq.size() == 0)
        {
            pq.push_back(element);
            return;
        }

        pq.push_back(element);
        heaporder_from_children(element, pq.size() - 1);
    }

  
    int RemoveMin()
    {
        if (isEmpty())
        {
            return 0;
        }
        
        int parentValue = pq[0];
        // pq[0] = pq[pq.size()-1];
        swap(pq[0],pq[pq.size()-1]);
        
        pq.pop_back();
        int parentIndex = 0;
        int Lindex = (2*parentIndex)  + 1;
        int Rindex = (2*parentIndex)  + 2 ;
        while(Lindex < pq.size())
        {
            int minIndex = parentIndex;
            
            if (pq[Lindex] < pq[minIndex])
            {
                minIndex = Lindex;
                
            }
            if (Rindex < pq.size()  && pq[Rindex] < pq[minIndex])
            {
                minIndex = Rindex;
            }

            if (minIndex == parentIndex)
            {
                break;
            }
           
           
                swap(pq[parentIndex],pq[minIndex]);
                parentIndex = minIndex;
                Lindex = (parentIndex)*2 + 1;
                Rindex = (parentIndex)*2 + 2;
            
        }
        return parentValue;
    }

    void show()
    {
        for (int i = 0; i < pq.size(); i++)
        {
            cout << pq[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    PriorityQueues pq1;

    pq1.Insert(100);
    pq1.Insert(10);
    pq1.Insert(15);
    pq1.Insert(4);
    pq1.Insert(17);
    pq1.Insert(21);
    pq1.Insert(64);

    cout << "Size: " << pq1.getSize() << endl;
    cout << "Min: " << pq1.getMin() << endl;
    pq1.show();
    int j = pq1.getSize();
    for (int i = 0; i < j; i++)
    {

        cout << pq1.RemoveMin() << endl;
    }
}