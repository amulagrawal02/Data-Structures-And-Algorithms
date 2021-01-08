#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> RemoveDuplicates(int *a , int size)
{
    unordered_map<int,bool> output;
    vector<int> seen;
    for (int i = 0; i < size; i++)
    {
        if(output.count(a[i]) > 0)
        {
            continue;
        }
        output[a[i]] = true;
        seen.push_back(a[i]);

    }
    return seen;
    
}
int main()
{
    int arr[] = {1,7,1,7,3,5,5,4};
    vector<int> output = RemoveDuplicates(arr,8);
    for (int i = 0; i < output.size(); i++)
    {
        cout<<output[i]<<" ";
    }
    
}