#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    unordered_map<string,int> ourmap;
    ourmap["abc"] = 1;
    ourmap["abc1"] = 0;
    ourmap["abc2"] = 2;
    ourmap["abc3"] = 3;
    ourmap["abc4"] = 4;
    ourmap["abc5"] = 5;

    unordered_map<string,int> :: iterator it = ourmap.begin();
    while (it != ourmap.end())
    {
        cout<<"Key : "<<it -> first<<endl<<" " <<"value : "<<it -> second <<endl;
        it++;
    }
    

}