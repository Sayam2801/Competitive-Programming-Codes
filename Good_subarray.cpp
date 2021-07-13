#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FORL(i,n) for(ll i=0;i<n;i++)
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,q;
        cin>>n>>q;
        ll arr[n];
        FORL(i,n)
           cin>>arr[i];
        FORL(i,q)
        {
            ll x,y;
            cin>>x>>y;
            arr[x-1]=y;
            set<ll> s;
            FORL(i,n)
               s.insert(arr[i]);
            //cout<<s.size()<<endl;
            if(s.size()==n-1)
            {
                cout<<n<<endl;
                continue;
            }
            ll cnt=1,max_cnt=0;
            FORL(i,n-1)
            {
                if(arr[i]==arr[i+1]){
                   max_cnt=max(max_cnt,cnt);
                   cnt=1;
                }
                else
                   cnt++;
            }
            cout<<max_cnt<<endl;
        }
    }
    return 0;
}