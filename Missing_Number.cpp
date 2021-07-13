#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        int no;
        cin>>no;
        mp[no]++;
    }
    bool check=0;
    for(int i=2;i<=n;i++)
    {
        if(mp.find(i)==mp.end())
        {
            cout<<i<<endl;
            check=1;
            break;
        }
    }
    if(!check)
       cout<<1<<endl;
    return 0;
}