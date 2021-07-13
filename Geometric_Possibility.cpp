#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int long_len=INT_MIN,sum=0,length[n];
        for(int i=0;i<n;i++)
        {
            cin>>length[i];
            long_len=max(long_len,length[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(length[i]!=long_len)
               sum+=length[i];
        }
        if(long_len<sum)
           cout<<"Yes"<<endl;
        else 
           cout<<"No"<<endl;
    }
    return 0;
}