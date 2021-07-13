#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll x,y,n,ans=0;
        cin>>x>>y>>n;
        for(ll i=0;i<n;i++)
        {
            if(x^i<y^i)
              ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}