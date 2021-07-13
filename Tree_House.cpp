// #include<iostream>
// #include<iomanip>
// #include<math.h>
// #include<map>
// #include<stack>
// #include<algorithm>
// #include<istream>
// #include<cstring>
// #include<string>
// #include<ostream>
// #include<unordered_set>
// #include<unordered_map>
// #include<queue>
// #include<vector>
// #include<set>
// using namespace std;
// /*#include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>*/
// //#include<ext/pb_ds/assoc_container.hpp>
// // #include<ext/pb_ds/tree_policy.hpp>
// using namespace std;
// //using namespace __gnu_pbds;
// //typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// const int MAX_N = 1e5 + 5;
// const int MAX_L = 20; // ~ Log N
// #define ll long long int
// #include<vector>
// const ll mx=100005;
// #define FORL(i,n) for(ll i=0;i<n;i++)
// #define iceil(n, x) (((n) + (x) - 1) / (x))
// #define mp make_pair
// #define pb push_back
// #define f first
// #define s second
// #define FOR(i,n) for(int i=0;i<n;i++)
// #define SORT(arr) sort(arr,arr+n)
// #define SORTVEC(v) sort(v.begin(),v.end())
// #define sz(v) v.size()
// const ll mod = 1e9+7;
// const ll MOD = 1e9+7;
// #define pf push_front
// #define pof pop_front
// #define gcd __gcd
// #define bitcount(x) __builtin_popcount(x)
// #define INF 1e18+42
// #define pob pop_back
// #define eb emplace_back
// #define all a.begin(),a.end()
// #define PI 3.14159265
// #define LSOne(S) (S & (-S))
// #define vpll vector<pair<ll,ll> > 
// #define int_input int t; cin>>t; while(t--)
// #define input ll t; cin>>t; while(t--)
// #define FORIS(s) for(int i=0;i<s.length();i++)
// #define FORLS(s) for(ll i=0;i<s.length();i++)
// #define vl vector<ll>
// #define vi vector<int>
// #define pii pair<int,int>
// #define pll pair<ll,ll>
// #define ppi pair<int,pair<int,int> > 
// #define ppl pair<ll,pair<ll,ll> > 
// #define int_min_heap priority_queue<int,vector<int>,greater<int> > 
// #define int_max_heap priority_queue<int> 
// #define ll_min_heap priority_queue<ll,vector<ll>,greater<ll> >
// #define ll_max_heap priority_queue<ll>
// #define i insert
// #define vvl vector<vector<ll> > 
// #define vvi vector<vector<int> >
// #define endl '\n'
// #define imp insert.make_pair
// #define int_map map<int,int>
// #define ll_map map<ll,ll>
// #define isBitSet(S, i) ((S >> i) & 1)
// #define MAXN 100005
// #define e(s) s.erase()
// #define c(mp) mp.clear()
// #define RALL(x) rbegin(x), rend(x)
// #define fastio ios::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
// #define vpii vector<pair<int,int> > 
// // #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
// // template <typename Arg1>
// // void __f(const char* name, Arg1&& arg1){
// //     cerr << name << " : " << arg1 << '\n';
// // }
// // template <typename Arg1, typename... Args>
// // void __f(const char* names, Arg1&& arg1, Args&&... args){
// //     const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
// // }

// // template<typename T1, typename T2>
// // ostream& operator << (ostream& os, const pair<T1, T2>& p) { return os << '(' << p.fi << ", " << p.se << ')'; }

// // template<typename T>
// // void printv(const T& v) { for(auto i : v) cerr << i << ' '; cerr << '\n'; }

// // template<typename T>
// // using minpq = priority_queue<T, vector<T>, greater<T>>;

// // template<typename T>
// // using maxpq = priority_queue<T>;

// //All indexing is 0-based
// // using namespace __gnu_pbds;
// //template<class key, class cmp = std::less<key>>
// //using ordered_set = tree<key, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// //methods: find_by_order(k); & order_of_key(k);
// //To make it an ordered_multiset, use pairs of (value, time_of_insertion)
// //to distinguish values which are similar

// //template<class key, class value, class cmp = std::less<key>>
// //using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

// //Returns no. of values x for which ceil(n / x) == y (y must be > 1).
// inline ll CC(ll n, ll y) { return iceil(n, y-1) - iceil(n, y); }

// //Returns no. of values x for which floor(n / x) == y
// inline ll FF(ll n, ll y) { return n / y - n / (y+1); }

// //a and b are assumed to be taken modulo p
// inline int add(int a, int b, int p = mod){ int c = a + b; if(c >= p) c -= p; return c; }
// inline int sub(int a, int b, int p = mod){ int c = a - b; if(c < 0) c += p; return c; }
// inline int mul(int a, int b, int p = mod){ return (a * 1ll * b) % p; }
// ll mE(ll x,ll y)
// {
//     ll result=1;
//     while(y)
//     {
//         if(y&1)
//             result=((result%MOD)*(x%MOD))%MOD;
//         x=((x%MOD)*(x%MOD))%MOD;
//         y>>=1;
//     }
//     return result%MOD;
// }
// bool isPrime[MAXN];
// vector<ll> primes;
// //ll n=150000;
// void sieve()
// {
//     isPrime[0]=isPrime[1]=0;
//     isPrime[2]=1;
//     for(ll i=3;i<MAXN;i+=2)
//       isPrime[i]=1;
//     for(ll i=2;i*i<MAXN;i++)
//     {
//       if(isPrime[i])
//       {
//         for(ll j=i*i;j<MAXN;j+=i)
//           isPrime[j]=0;
//       }
//     }
//     primes.pb(2);
//     for(int i=3;i<=MAXN;i+=2)
//     {
//         if(isPrime[i])
//              primes.pb(i);
//     }
//     return;
// }
// // bool compare(pll &a,pll &b)
// // {
// //     return a.s>b.s;
// // }
// // void solve(){
// //     ll n,x;
// //     cin>>n>>x;
// //     map<ll,vl> mymap;
// //     for(ll i=2;i<n+1;i++)
// //     {
// //         ll u,v;
// //         cin>>u>>v;
// //         auto itr=mymap.find(u);
// //         if(itr->f==u)
// //            itr->s.pb(v);
// //         else
// //         {
// //             vl store;
// //             store.pb(v);
// //             mymap.i({u,store});
// //         }
// //     }
// //     for(auto i=mymap.begin();i!=mymap.end();i++)
// //     {
// //         vpll newmap;
// //         auto v=i->s;
// //         for(auto x=v.begin();x!=v.end();x++)
// //         {
// //             ll c=0;
// //             auto it=mymap.find(*x);
// //             if(it->f == *x)
// //                c=sz(it->s);
// //             else
// //                c=0;
// //             newmap.pb({*x,c});
// //         }
// //         sort(newmap.begin(),newmap.end(),compare);
// //         vl l;
// //         for(auto it=newmap.begin();it!=newmap.end();it++)
// //             l.pb(it->f);
// //         i->s=l;
// //     }
// //     map<ll,ll> m;
// //     for(ll i=1;i<n+1;i++)
// //     {
// //         auto var=mymap.find(i);
// //         if(var->f==i)
// //         {
// //             ll temp=0;
// //             if(i==1)
// //                temp=x;
// //             else
// //                temp=m.find(i)->s;
// //             ll j=1;
// //             for(auto itr=var->s.begin();itr!=var->s.end();itr++)
// //             {
// //                 m.i({*itr,temp*j});
// //                 j++;
// //             }
// //         }
// //     }
// //     ll ans=x;
// //     for(auto it=m.begin();it!=m.end();it++)
// //     {
// //         ans+=it->s;
// //         ans=ans%mod;
// //     }
// //     cout<<ans%mod<<endl;
// //     return;
// // }
// const int maxn = 3E5 + 5;
// const int mod = 1E9 + 7;

// vector<int> adj[maxn], subval, val;
// vector<pii> ch;

// void dfs(int now, int lst = -1)
// {
//     for (auto x : adj[now])
//     {
//         if (x == lst)
//             continue;
//         dfs(x, now);
//     }
//     ch.clear();
//     for (auto x : adj[now])
//     {
//         if (x != lst)
//             ch.eb(subval[x], x);
//     }
//     sort(RALL(ch));

//     int tok = 1;
//     for (auto [_val, id] : ch)
//         val[id] = tok++;
//     for (auto x : adj[now])
//     {
//         if (x != lst)
//             subval[now] += val[x] * subval[x];
//     }
// }

// void solve()
// {
//     int N, X;
//     cin >> N >> X;
//     subval.assign(N, 1), val.assign(N, 0);
//     for (int i = 0; i < N; ++i)
//         vector<int>().swap(adj[i]);

//     for (int i = 0; i < N - 1; ++i)
//     {
//         int u, v;
//         cin >> u >> v, --u, --v;
//         adj[u].eb(v), adj[v].eb(u);
//     }

//     dfs(0);

//     cout << subval[0] % mod * X % mod << endl;
// }
// int main()
// {
//     fastio
//     ll h=1;
//     input {
//         //cout<<"Test Case "<<h<<":";
//         solve();
//         h++;
//     }
//     return 0;
// }




#pragma GCC optimize("Ofast", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
using pii = pair<int, int>;
template <typename T>
using Prior = std::priority_queue<T, vector<T>, greater<T>>;
#define X first
#define Y second
#define vi vector<int>
#define eb emplace_back
#define ALL(x) begin(x), end(x)
#define RALL(x) rbegin(x), rend(x)
#define fastIO() ios_base::sync_with_stdio, cin.tie(0)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int getRand(int L, int R)
{
    if (L > R)
        swap(L, R);
    return (int)(rng() % (uint64_t)(R - L + 1) + L);
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p)
{
    os << "(" << p.first << "," << p.second << ")";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        if (i)
            os << " ";
    }
    return os;
}
const int MAXN = 3E5 + 5;
const int MOD = 1E9 + 7;
vector<int> adjacent[MAXN],subvalue,value;
vector<pii> ch;
void dfs(int now,int last = -1)
{
    for(auto x:adjacent[now])
    {
        if(x==last)
           continue;
        dfs(x,now);
    }
    ch.clear();
    for(auto x:adjacent[now])
    {
        if(x!=last)
            ch.eb(subvalue[x],x);
    }
    sort(RALL(ch));
    int temp=1;
    for(auto [_value, id]:ch)
        value[id]=temp++;
    for(auto x:adjacent[now])
    {
        if(x!=last)
            subvalue[now]+=value[x]*subvalue[x];
    }
    return;
}

void solve()
{
    int n,x;
    cin>>n>>x;
    subvalue.assign(n,1),value.assign(n,0);
    for(int i=0;i<n;i++)
        vi().swap(adjacent[i]);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        adjacent[u].eb(v);
        adjacent[v].eb(u);
    }
    dfs(0);
    cout<<(subvalue[0]%MOD * x%MOD)<<endl;
    return;
}

int32_t main()
{
    fastIO();
    int t;
    cin >> t;
    for (int _ = 1; _ <= t; ++_)
    {
        solve();
    }
    return 0;
}