#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FORL(i,n) for(ll i=0;i<n;i++)
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define FOR(i,n) for(int i=0;i<n;i++)
#define SORT(arr) sort(arr,arr+n)
#define SORTVEC(v) sort(v.begin(),v.end())
#define sz(v) v.size()
#define mod 1e9+7
#define MOD 10000
#define INF 1e18+42
#define pob pop_back
#define eb emplace_back
#define vl vector<ll>
#define vi vector<int>
#define pii pair<int,int>
#define ppi pair<int,pair<int,int> > 
#define ppl pair<ll,pair<ll,ll> > 
#define int_min_heap priority_queue<int,vector<int>,greater<int> > 
#define int_max_heap priority_queue<int> 
#define ll_min_heap priority_queue<ll,vector<ll>,greater<ll> >
#define ll_max_heap priority_queue<ll>
#define i insert
#define imp insert.make_pair
#define int_map map<int,int>
#define ll_map map<ll,ll>
#define str string 
#define e(s) s.erase()
#define c(mp) mp.clear()
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        FORL(i,n)
           cin>>arr[i];
        vl store;
        ll cnt=1;
        FORL(i,n)
        {
            ll op;
            cin>>op;
            if(op==1)
            {
                ll x;
                cin>>x;
                FORL(i,n)
                   arr[i]=(arr[i]*x)%MOD;
                store.pb(arr[cnt-1]);
            }
            else
            { 
                ll x;
                cin>>x;
                arr[cnt-1]=(arr[cnt-1]+x)%MOD;
                store.pb(arr[cnt-1]);
            }
            cnt++;
        }
        for(auto x:store)
           cout<<x<<endl;
    }
    return 0;
}