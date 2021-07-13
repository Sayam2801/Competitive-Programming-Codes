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
//Time Complexity: O(n^3) or O(n^4) depending upon implementation
//EDITORIAL:1415D - XOR-gun

/*First let's compute array b1,b2,…,bn
, where bi is the index of the highest bit equal to 1 in the binary notation of ai. The statement says bi≤bi+1. These values can be computed by dividing the given numbers by 2

until they are zero.

Note that if for a given i
the equality bi−1=bi=bi+1=t holds, then we can apply an operation to ai and ai+1, and the resulting integer is smaller than ai−1. Indeed, in ai−1 the highest bit set is t, but in ai⊕ai+1 the t-th and higher bits are zeros. That means if there is such an i (it is easy to check in a single linear pass), then the answer is 1

.

Now note that if there is no such i
, then the size of the array n is not bigger than 2⋅(⌊log2109⌋+1)=60

! Indeed, there are no more than two integers with the same highest bit set. It is much easier to solve the problem in such constraints.

Consider some solution. In the final array, let's denote it as c
, there is i such that ci>ci+1. Note that each element of the final array is equal to XOR of some subsegment of the initial array, and each element of the initial array belongs to exactly one such subsegment. Let this subsegment for ci be al,al+1,…,am, and for ci+1 be am+1,am+2,…,ar. Then it's clear that to find an optimal solution it is enough to loop through all possible values of l, m, and r and check whether XOR of all elements of the left subsegment is larger than XOR of all elements of the right subsegment. If this inequality holds, update answer with value r−l−1. *///The complexity of this part is O(n3) or O(n4) depending on implementation.
void solve(){
    ll n;
    cin>>n;
    ll arr[n];
    FORL(i,n)
       cin>>arr[i];
    ll ans=(ll)INT_MAX;
    ll idx[n];
    FORL(i,n)
    {
        ll ele=arr[i];
        ll cnt=0;
        while(ele>>=1)
          cnt++;
        idx[i]=cnt;//Store the position of leftmost set bit
    }
    FORL(i,n-2)
    {
        if(idx[i]==idx[i+1] && idx[i+1]==idx[i+2])//If the position of last set bit of three consecutive numbers is same then ans will be 1 as we can check for the condition xor for first two elements greater than xor for last two elements
        {
            cout<<"1"<<'\n';
            return;
        }
    }
    FORL(i,n)
    {
        ll first_xor=0;
        for(ll j=i;j<n;j++)
        {
            first_xor^=arr[j];
            ll second_xor=0;
            for(ll k=j+1;k<n;k++)
            {
                second_xor^=arr[k];
                if(first_xor>second_xor)
                   ans=min(ans,k-i-1);
            }
        }
    }
    if(ans!=(ll)INT_MAX)
    cout<<ans<<endl;
    else
    {
        cout<<-1<<endl;
    }
    //In this problem, we just need to check for all possible three consecutive pairs i.e. their XOR values in each triplet comparing those XOR values, if the XOR value of left subset is greater than the XOR value of right subset then a decreasing array can be formed...
    return;
}
int main()
{
    fastio
    ll h=1;
    //input {
        //cout<<"Test Case "<<h<<":";
        solve();
        h++;
    //}
    return 0;
}