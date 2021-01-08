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
    int getMax()
    {
        if (pq.size() == 0)
        {
            return 0; //  If Our Priority Queue is Empty
        }

        return pq[0];
    }
    void HeapOrder(int element, int Index)
    {
        if (Index == 0)
        {
            return;
        }
        
        int ParentIndex = (Index - 1) / 2;
        if(pq[ParentIndex] > pq[Index])
        {
            return;
        }
        swap(pq[ParentIndex],pq[Index]);
        HeapOrder(element,ParentIndex);

    }

    void Insert(int element)
    {
        if (pq.size() == 0)
        {
            pq.push_back(element);
            return;
        }
        pq.push_back(element);
        HeapOrder(element,pq.size()-1);   
    }
    int RemoveMax()
    {
        if(isEmpty())
        {
            return 0;
        }
        int ParentValue = pq[0];
        int ParentIndex = 0;
        swap(pq[ParentIndex],pq[pq.size()-1]);
        pq.pop_back();
        int LIndex = (2*ParentIndex) + 1;
        int RIndex = (2*ParentIndex) + 2;
        while (LIndex < pq.size())
        {
            int MaxIndex = ParentIndex;
            if (pq[LIndex] > pq[ParentIndex])
            {
                MaxIndex = LIndex;
            }
            if (RIndex < pq.size() && pq[RIndex] > pq[ParentIndex])
            {
               MaxIndex = RIndex;
            }
            if (MaxIndex == ParentIndex)
            {
                break;
            }

            swap(pq[ParentIndex] , pq[MaxIndex]);
            LIndex = (2*MaxIndex)+1;
            RIndex = (2*MaxIndex)+2;
            ParentIndex = MaxIndex;
            

        }
        return ParentValue;
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

    pq1.show();
   
   
    
         cout << pq1.RemoveMax() << endl;
          cout << pq1.RemoveMax() << endl;
          cout << pq1.RemoveMax() << endl;
       
    
        pq1.show();
    
}