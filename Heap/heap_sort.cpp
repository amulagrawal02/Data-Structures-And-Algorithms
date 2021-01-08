#include <iostream>
using namespace std;
void Insert(int pq[], int N)
{
    for (int i = 1; i < N; i++)
    {
        int ChildIndex = i;
        while (ChildIndex > 0)
        {
            int ParentIndex = (ChildIndex - 1) / 2;
            if (pq[ParentIndex] < pq[ChildIndex])
            {
                break;
            }

            swap(pq[ParentIndex],pq[ChildIndex]);
            ChildIndex = ParentIndex;

        }
    }
    // Remove Elements
    int Size = N;
    while(Size > 1)
    {
        swap(pq[0],pq[Size - 1]);
        Size--;
        int parentIndex = 0;
        int Lindex = (2*parentIndex)  + 1;
        int Rindex = (2*parentIndex)  + 2 ;
        while(Lindex < Size)
        {
            int minIndex = parentIndex;
            
            if (pq[Lindex] < pq[minIndex])
            {
                minIndex = Lindex;
                
            }
            if (Rindex < Size  && pq[Rindex] < pq[minIndex])
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
        
    }
}
    
int main()
{
    int input[] =  {5,8,1,2,0};
    Insert(input,5);
    for (int i = 0; i < 5; i++)
    {
        cout<<input[i]<<" ";
    }
    

}