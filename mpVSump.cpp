#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int,int> mp1;
    unordered_map<int,vector<int>> mp2;
    
   for(int i=1;i<=5;i++)
   {
       mp2[0].push_back(i);
   }
   for(int i=1;i<=3;i++)
   {
       mp2[1].push_back(i);
   }

   for(int i=0;i<mp2.size();i++)
   {
       for(auto x : mp2[i])
       {
           cout << x << " ";
       }
       cout << "" << endl;
   }
    return 0;
}