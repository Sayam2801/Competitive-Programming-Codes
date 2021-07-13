#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long 
#define vl vector<ll>
#define sz(v) v.size()
#define pb push_back
#define rz resize
#define endl '\n'
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll ans;
vector<vector<ll> > edge;
vl dp,total;
void dfs(ll start,ll parity)
{
    dp[start]=1,total[start]=1;
    ll sum=0,cnt=0;
    for(ll i=0;i<sz(edge[start]);i++)
    {
        ll node=edge[start][i];//Explore all the adjacent nodes of the starting node
        if(node!=parity)
        {
            dfs(node,start);
            dp[start]+=(2*dp[node])%mod;//Include the total number of vertical paths associated with neighbouring node in that of starting node
            dp[start]%=mod;//Keep taking modulus at each step in order to prevent integer overflow
            cnt++;//{x}//There is one vertical path always possible that is, the starting node itself(Singleton set)
            total[start]+=total[node]%mod;//Adding total number of vertical paths of child node to that of starting node
            total[start]%=mod;
            total[start]+=dp[node]%mod;//Add count of vertical paths into total number of valid vertical paths of starting node
            total[start]%=mod;
            sum+=dp[node];//Include total number of vertical paths of each neighbouring node into sum
        }
    }
    for(ll i=0;i<sz(edge[start]);i++)
    {
        ll node=edge[start][i];
        if(node!=parity)
        {//Total number of valid vertical paths of right subtree, V(y)=total number of vertical paths of the whole tree-V(x) where V(x) is number of valid vertical paths of the left subtree..
            total[start]+=(dp[node]*(sum-dp[node]+mod)%mod)%mod;//total number of vertical paths of starting node= V(x)*V(y)
            total[start]%=mod;
        }
    }
    return;
}
int main()
{
    fastIO
    ll t;
    cin>>t;
    while(t--)
    {
        ans=0;
        ll n;
        cin>>n;
        edge.rz(n+1),dp.rz(n+1),total.rz(n+1);//Resize all vectors with n+1 for each case
        for(int i=1;i<=n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            //Push each vertex v into the adjacency list of u and vice versa
            edge[u].pb(v);
            edge[v].pb(u);
        }
        dfs(1,1);//Run DFS from the starting node
        ans=total[1]%mod;//Returns the total number of valid vertical paths in the whole tree involving root node
        ans%=mod;
        cout<<ans<<endl;
        edge.clear(),dp.clear(),total.clear();//Don't forget to clear memory for all vectors involved
    }
    return 0;
}