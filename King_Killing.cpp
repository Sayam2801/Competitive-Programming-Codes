#include<iostream>
#include<iomanip>
#include<math.h>
#include<map>
#include<stack>
#include<algorithm>
#include<istream>
#include<cstring>
#include<string>
#include<ostream>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<vector>
#include<set>
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>*/
//#include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
#define ll long long int
#include<vector>
const ll mx=100005;
#define FORL(i,n) for(ll i=0;i<n;i++)
#define iceil(n, x) (((n) + (x) - 1) / (x))
#define ALL(v) v.begin(),v.end()
#define vb vector<bool>
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define FOR(i,n) for(int i=0;i<n;i++)
#define SORT(arr) sort(arr,arr+n)
#define SORTVEC(v) sort(v.begin(),v.end())
#define sz(v) v.size()
#define mod 1e9+7
const ll MOD = 1e9+7;
#define pf push_front
#define pof pop_front
#define gcd __gcd
#define bitcount(x) __builtin_popcount(x)
#define INF 1e18+42
#define pob pop_back
#define eb emplace_back
#define all a.begin(),a.end()
#define PI 3.14159265
#define LSOne(S) (S & (-S))
#define vpll vector<pair<ll,ll> > 
#define int_input int t; cin>>t; while(t--)
#define input ll t; cin>>t; while(t--)
#define FORIS(s) for(int i=0;i<s.length();i++)
#define FORLS(s) for(ll i=0;i<s.length();i++)
#define vl vector<ll>
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ppi pair<int,pair<int,int> > 
#define ppl pair<ll,pair<ll,ll> > 
#define int_min_heap priority_queue<int,vector<int>,greater<int> > 
#define int_max_heap priority_queue<int> 
#define ll_min_heap priority_queue<ll,vector<ll>,greater<ll> >
#define ll_max_heap priority_queue<ll>
#define i insert
#define vvl vector<vector<ll> > 
#define vvi vector<vector<int> >
#define endl '\n'
#define imp insert.make_pair
#define int_map map<int,int>
#define ll_map map<ll,ll>
#define isBitSet(S, i) ((S >> i) & 1)
#define MAXN 100005
#define e(s) s.erase()
#define c(mp) mp.clear()
#define RALL(x) rbegin(x), rend(x)
#define vpii vector<pair<int,int> > 
#define fastio ios::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
// #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
// template <typename Arg1>
// void __f(const char* name, Arg1&& arg1){
//     cerr << name << " : " << arg1 << '\n';
// }
// template <typename Arg1, typename... Args>
// void __f(const char* names, Arg1&& arg1, Args&&... args){
//     const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
// }

// template<typename T1, typename T2>
// ostream& operator << (ostream& os, const pair<T1, T2>& p) { return os << '(' << p.fi << ", " << p.se << ')'; }

// template<typename T>
// void printv(const T& v) { for(auto i : v) cerr << i << ' '; cerr << '\n'; }

// template<typename T>
// using minpq = priority_queue<T, vector<T>, greater<T>>;

// template<typename T>
// using maxpq = priority_queue<T>;

//All indexing is 0-based
// using namespace __gnu_pbds;
//template<class key, class cmp = std::less<key>>
//using ordered_set = tree<key, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
//methods: find_by_order(k); & order_of_key(k);
//To make it an ordered_multiset, use pairs of (value, time_of_insertion)
//to distinguish values which are similar

//template<class key, class value, class cmp = std::less<key>>
//using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

//Returns no. of values x for which ceil(n / x) == y (y must be > 1).
inline ll CC(ll n, ll y) { return iceil(n, y-1) - iceil(n, y); }

//Returns no. of values x for which floor(n / x) == y
inline ll FF(ll n, ll y) { return n / y - n / (y+1); }

//a and b are assumed to be taken modulo p
inline int add(int a, int b, int p = mod){ int c = a + b; if(c >= p) c -= p; return c; }
inline int sub(int a, int b, int p = mod){ int c = a - b; if(c < 0) c += p; return c; }
inline int mul(int a, int b, int p = mod){ return (a * 1ll * b) % p; }
ll mE(ll x,ll y)
{
    ll result=1;
    while(y)
    {
        if(y&1)
            result=((result%MOD)*(x%MOD))%MOD;
        x=((x%MOD)*(x%MOD))%MOD;
        y>>=1;
    }
    return result%MOD;
}
bool isPrime[MAXN];
vector<ll> primes;
//ll n=150000;
void sieve()
{
    isPrime[0]=isPrime[1]=0;
    isPrime[2]=1;
    for(ll i=3;i<MAXN;i+=2)
      isPrime[i]=1;
    for(ll i=2;i*i<MAXN;i++)
    {
      if(isPrime[i])
      {
        for(ll j=i*i;j<MAXN;j+=i)
          isPrime[j]=0;
      }
    }
    primes.pb(2);
    for(int i=3;i<=MAXN;i+=2)
    {
        if(isPrime[i])
             primes.pb(i);
    }
    return;
}
ll gcd(ll a,ll b)
{
    if(!a)   
       return b;
    return gcd(b%a,a);
}
// struct Treenode
// {
//     int data,level;
//     vector<Treenode *> child;
//     Treenode(int x)
//     {
//         data=x;
//         level=0;
//     }
// };
// void buildTree(Treenode *root,vvi &adjacent,vb &visited)
// {
//     visited[root->data]=1;
//     for(int i=0;i<sz(adjacent[root->data]);i++)
//     {
//         if(!visited[adjacent[root->data][i]])
//         {
//             Treenode *temp=new Treenode(adjacent[root->data][i]);
//             root->child.pb(temp);
//         }
//     }
//     for(int i=0;i<sz(root->child);i++)
//        buildTree(root->child[i],adjacent,visited);
//     return;
// }
// void dfs(Treenode *root,int l)
// {
//     root->level=l;
//     for(int i=0;i<sz(root->child);i++)
//     {
//         Treenode *curr=root->child[i];
//         dfs(curr,l+1);
//     }
//     return;
// }
// vpii leaves;
// void dfs2(Treenode *root)
// {
//     for(int i=0;i<sz(root->child);i++)
//     {
//         Treenode *curr=root->child[i];
//         dfs2(curr);
//     }
//     if(!sz(root->child))
//        leaves.pb({root->level,root->data+1});
//     return;
// }
// void solve()
// {
//     int n;
//     cin>>n;
//     vvi adjacent(n);
//     for(int i=0;i<n-1;i++)
//     {
//         int u,v;
//         cin>>u>>v;
//         u--,v--;
//         adjacent[u].pb(v);
//         adjacent[v].pb(u);
//     }
//     Treenode *root=new Treenode(0);
//     vb visited(n,0);
//     buildTree(root,adjacent,visited);
//     dfs(root,0);
//     vpii ans;
//     for(int i=0;i<sz(root->child);i++)
//     {
//         dfs2(root->child[i]);
//         vpii store;
//         pii p;
//         bool check=0;
//         sort(ALL(leaves));
//         p=leaves[0];
//         store.pb(p);
//         int value=p.f,j=1;
//         while(j<sz(leaves))
//         {
//             while(j<sz(leaves) && leaves[j].f==value)
//             {
//                 if(check)
//                    store.pb({p.f+1,leaves[j].s});
//                 else
//                    store.pb(leaves[j]);
//                 j++;
//             }
//             if(j<sz(leaves))
//             {
//                 store.clear();
//                 check=1;
//                 p.s=leaves[j].s;
//                 store.pb({p.f+1,leaves[j].s});
//                 value=leaves[j].f;
//                 j++;
//             }
//         }
//         leaves.clear();
//         for(auto x:store)
//            ans.pb(x);
//     }
//     sort(ALL(ans));
//     int day=ans[0].f;
//     vi result;
//     for(int i=0;i<sz(ans);i++)
//     {
//         if(ans[i].f==day)
//            result.pb(ans[i].s);
//         else
//            break;
//     }
//     cout<<sz(result)<<" "<<day<<endl;
//     for(auto x:result)
//        cout<<x<<" ";
//     cout<<endl;
//     return;
// }
// struct Treenode 
// {
//     int data,level;
//     vector<Treenode *> child;
//     Treenode(int x) 
//     {
//         data=x;
//         level=0;
//     }
// };
// vpii leaves;
// void DepthForSearchSecond(Treenode *root)
// {
//     for(int i=0;i<root->child.size();i++)
//     {
//         Treenode *current=root->child[i];
//         DepthForSearchSecond(current);
//     }
//     if(root->child.size()==0)
//        leaves.pb({root->level,root->data+1});
// }
// void DepthForSearch(Treenode *root,int l)
// {
//     root->level=l;
//     for(int i=0;i<root->child.size();i++)
//     {
//         Treenode *current=root->child[i];
//         DepthForSearch(current,l+1);
//     }
// }
// void createTree(Treenode *root,vvi &adjacent,vector<bool> &visited)
// {
//     visited[root->data]=1;
//     for(int i=0;i<adjacent[root->data].size();i++)
//     {
//         if(!visited[adjacent[root->data][i]])
//         {
//             Treenode *temp=new Treenode(adjacent[root->data][i]);
//             root->child.push_back(temp);
//         }
//     }
//     for(int i=0;i<root->child.size();i++)
//        createTree(root->child[i],adjacent,visited);
//     return;
// }
// void solve(){
//     int n;
//     cin>>n;
//     vvi adjacent(n);
//     FOR(i,n-1)
//     {
//         int u,v;
//         cin>>u>>v;
//         u--,v--;
//         adjacent[u].pb(v);
//         adjacent[v].pb(u);
//     }
//     Treenode *root=new Treenode(0);
//     vector<bool> visited(n,0);
//     createTree(root,adjacent,visited);
//     DepthForSearch(root,0);
//     vpii ans;
//     for(int i=0;i<root->child.size();i++)
//     {
//         DepthForSearchSecond(root->child[i]);
//         vpii v;
//         pii p;
//         bool f=0;
//         sort(leaves.begin(),leaves.end());
//         p=leaves[0];
//         v.pb(p);
//         int val=p.f;
//         int j=1;
//         while(j<leaves.size())
//         {
//             while(j<leaves.size() && leaves[j].f==val)
//             {
//                 if(f)
//                    v.pb({p.f+1,leaves[j].s});
//                 else
//                    v.pb(leaves[j]);
//                 j++;
//             }
//             if(j<leaves.size())
//             {
//                 v.clear();
//                 f=1;
//                 p.s=leaves[j].s;
//                 v.pb({p.f+1,leaves[j].s});
//                 val=leaves[j].s;
//                 j++;
//             }
//             leaves.clear();
//             for(auto x:v)
//                 ans.pb(x); 
//         }
//         sort(ans.begin(),ans.end());
//         int day=ans[0].f;
//         vi store;
//         for(int i=0;i<ans.size();i++)
//         {
//             if(ans[i].f==day)
//                store.pb(ans[i].s);
//             else
//                break;
//         }
//         cout<<sz(store)<<" "<<day<<endl;
//         for(auto x:store)
//            cout<<x<<" ";
//         cout<<endl;
//     }
// }
vvi v;
vi dp,ans;
//Finds the time for each vertex
void dfs(int x,int p)
{
    set<int> s;
    for(int ele:v[x])
    {
        if(ele==p) continue;
        dfs(ele,x);
        s.i(dp[ele]);
    }
    if(s.empty())
       dp[x]=0;//leaf node
    else if(s.size()==1 || p==0)
       dp[x]=*s.begin()+1;//if x=root or everyone arrives together, then there is no killing at this vertex
    else
       dp[x]=*s.begin()+1+1;//arrival(min+1) + 1(for kill)
    return;
}
//Which vertices in the subtree of x were alive at time T
void dfs2(int x,int p,int T)
{
    if(T>dp[x])
       return;//vertices in the subtree of x are already above x(hence are already dead)
    for(int ele:v[x])
    {
        if(ele==p) continue;
        if(p==0)
        {
            //No killing happens on root    
            if(dp[ele]==T-1)
               dfs2(ele,x,T-1); 
        }
        else
        {
            if(T<dp[x])
                dfs2(ele,x,T);//If T<dp[x], we need to go in the past and go deeper in the tree
            else
                dfs2(ele,x,T-1);//vertices alive in subtree of x at time T were alive in subtree of child at time T-1
        }
    }
    if(!T) //x is a valid leaf
        ans.pb(x);
    return;
}
void solve()
{
    int n;
    cin>>n;
    //clear and reassign vectors
    v.clear();
    dp.clear();
    ans.clear();
    v.resize(n+1);
    dp.resize(n+1);
    //take graph input
    FOR(i,n-1)
    {
        int a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    //find the times of each vertex and store them in a dp array
    dfs(1,0);
    //use the dp array and do another dfs to store the vertices and store them in a vector ans
    dfs2(1,0,dp[1]);
    sort(ans.begin(),ans.end());
    cout<<sz(ans)<<" "<<dp[1]<<endl;
    for(auto x:ans)
       cout<<x<<" ";
    cout<<endl;
    return;
}
int main()
{
    fastio
    ll h=1;
    input {
        //cout<<"Test Case "<<h<<":";
        solve();
        h++;
    }
    return 0;
}