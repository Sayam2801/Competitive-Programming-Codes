#include<bits/stdc++.h>
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>*/
//#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
#define ll long long int
const ll mx=100005;
#define FORL(i,n) for(ll i=0;i<n;i++)
#define iceil(n, x) (((n) + (x) - 1) / (x))
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
#define fastio ios::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

template<typename T1, typename T2>
ostream& operator << (ostream& os, const pair<T1, T2>& p) { return os << '(' << p.fi << ", " << p.se << ')'; }

template<typename T>
void printv(const T& v) { for(auto i : v) cerr << i << ' '; cerr << '\n'; }

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;

//All indexing is 0-based
using namespace __gnu_pbds;
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
/* Explanations:
Try removing coins from bottom, It’s more intuitive that way.
Lets say x times we take 2 from a , and 1 from b
and y times we take 2 from b and 1 from a

meaning:
a = 2x + 1y
b = 1x + 2y

on solving for a and b

2a - b = 3x
2b - a = 3y

x and y should be non negative , and from here we can derive (a+b)%3==0.
Let’s assume that we are removing xxx number of times 222 coins from pile aaa and 111 coin from pile bbb.

Let’s assume that we are removing yyy number of times 111 coin from pile aaa and 222 coins from pile bbb.

Mathematically we can write our assumptions as:
a=2x+y    ⋯(i)a = 2x + y \;\;\cdots (i)a=2x+y⋯(i)
b=x+2y    ⋯(ii)b = x + 2y \;\; \cdots (ii)b=x+2y⋯(ii)

We have two equations and we have two unknowns, means we can solve for xxx and yyy.
After solving the above equations for xxx and yyy, you will get:
x=2a−b3x = \frac{2a - b}{3}x=32a−b​
y=2b−a3y = \frac{2b - a}{3}y=32b−a​

Clearing xxx and yyy ∈Z+\in Z^{+}∈Z+ and they must be a multiple of 333.

One more important information we will get when we subtract (ii)(ii)(ii) from (i)(i)(i) i.e.
∣a−b∣=∣x−y∣|a - b| = |x - y|∣a−b∣=∣x−y∣

Source Code: https://github.com/strikersps/Competitive-Programming/tree/master/CSES/Coin-Piles 43
It means …When we reduce “a” by 2 then we must reduce “b” by 1 and when we reduce “a” by 1 the we must reduce “b” by 2. So if We assume that we take x times 2 and y times 1 to reach a to 0 then we must take x times 1 and y times 2 to reduce “b” to 0. i.e
a=2x+1y
b=1x+2y*/
void solve(){
   ll a,b;
   cin>>a>>b;
   if(a<b)
      swap(a,b);
    if(a>2*b)
    {
        cout<<"NO"<<endl;
        return;
    }
    a%=3,b%=3;
    if(a<b)
       swap(a,b);
    if((a==2 && b==1) || (a==b &&b==0))
       cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
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