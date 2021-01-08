#include<iostream>
using namespace std;
#include <unordered_map> 
#include<string>
int main()
{
  
  unordered_map<string,int> output;
  //insert
  output["abc"] = 1;
  pair<string,int> p("pqr",2);
  output.insert(p);

  //find and access
  cout<<output["abc"]<<endl;  
  cout<<output["pqr"]<<endl;

  //check presence
  if (output.count("abc")>0)
  {
    cout<<"present"<<endl;
  }
  
  


}