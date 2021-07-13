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
ll dp[100][100];
//Recursive Approach
ll minSum(ll weight[],ll n,ll sumFound,ll sum)
{
    //If whole length of the array has been traversed, then we'll find the minimum possible difference between the two sets
    if(n==0)
       return abs((sum-sumFound)-sumFound);
    if(dp[n][sumFound]!=-1)
        return dp[n][sumFound];
    //There are always two possibilities, either we include an element into one set or we exclude it...
    return dp[n][sumFound]=min(minSum(weight,n-1,sumFound+weight[n-1],sum),minSum(weight,n-1,sumFound,sum));
}
//Dynamic Programming Approach Time Complexity: O(n*sum) Pseudo Polynomial Time Complexity as it depends upon the size of input
ll minSumDP(ll weight[],ll n)
{
    ll sum=0;
    FORL(i,n)
       sum+=weight[i];
    bool dp[n+1][sum+1];
    //Initialize the top most row of the DP array, there can be a possible sum 0 for any number of elements....
    for(ll i=0;i<=n;i++)
       dp[i][0]=true;
    //Initialize the whole first column elements as 0 except dp[0][0], as for 0 elements, there can be a possible sum 0. 
    for(ll i=1;i<=sum;i++)
       dp[0][i]=false;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=sum;j++)
        {
            //Excluding the element
            dp[i][j]=dp[i-1][j];
            //Including the element into the set
            if(weight[i-1]<=j)
            dp[i][j] |= dp[i-1][j-weight[i-1]];
        }
    }
    ll ans=(ll)INT_MAX;
    //Iterate from j=sum/2 to 0 and try to find the largest possible value of j such that dp[n][j] is true and hence the difference between the two sets is minimum..
    for(ll j=sum/2;j>=0;j--)
    {
        if(dp[n][j]==true)
        {
            ans=sum-2*j;//The difference between the two possible subsets will be minimum only when j is as closest to (sum/2) as possible...
            break;
        }
    }
    return ans;
}
void solve(){
    /*

As N is maximum 20 you can take all possible combinations of elements and put them in one group and put others in another group and check their difference. Maximum complexity will be 2^20 which is acceptable. Something like this:-

for (ll i = 0; i < pow(2, n); i++) { ll sum1 = 0, sum2 = 0; for (ll j = 0; j < n ; j++) { if (i & 1 << j) sum1 += a[j]; else sum2 += a[j]; } min1 = min(min1, abs(sum1 - sum2)); }

Hope it helps!

    
    int n;
    cin>>n;
    ll weight[n],ans=(ll)INT_MAX;
    FORL(i,n)
       cin>>weight[i];
    FORL(i,pow(2,n))//We'll try for all the possible combinations of weights and check the minimum difference between the two subsets due to lower constraints..
    {
        ll s1=0,s2=0;
        FORL(j,n)
        {
            if(i&(1<<j))//If ith bit is set
               s1+=weight[j];
            else
               s2+=weight[j];
        }
        ans=min(ans,abs(s1-s2));
    }
    cout<<ans<<'\n';
    return;*/
    ll n;
    cin>>n;
    ll weight[n];
    FORL(i,n)
       cin>>weight[i];
    cout<<minSumDP(weight,n)<<endl;
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