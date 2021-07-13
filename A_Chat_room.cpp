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

string removeDuplicate(string str) 
{ 
   // Used as index in the modified string 
   int index = 0,n=str.length();  
   // Traverse through all characters 
   for (int i=0; i<n; i++) {     
     // Check if str[i] is present before it   
     int j;   
     for (j=0; j<i; j++)  
        if (str[i] == str[j]) 
           break; 
       
     // If not present, then add it to 
     // result. 
     if (j == i) 
        str[index++] = str[i]; 
   } 
   return str; 
} 
bool isSubSequence(string str1, string str2) 
{ 
   int j = 0; // For index of str1 (or subsequence 
   int m=str1.length(),n=str2.length();
   // Traverse str2 and str1, and compare current character  
   // of str2 with first unmatched char of str1, if matched  
   // then move ahead in str1 
   for (int i=0; i<n&&j<m; i++) 
       if (str1[j] == str2[i]) 
         j++; 
  
   // If all characters of str1 were found in str2 
   return (j==m); 
} 
//Recursive Implementation of detection of one string being a subsequence of another string
bool isSubsequenceRecursive(string a,string b,int n,int m)
{
     if(!n)
        return true;
    if(!m)
       return false;
    if(a[n-1]==b[m-1])
        return isSubsequenceRecursive(a,b,n-1,m-1);
    return isSubsequenceRecursive(a,b,n,m-1);
}
void solve(){
   string s,temp="";
   cin>>s;
   FOR(i,s.length())
   {
       if(s[i]=='h' || s[i]=='e' || s[i]=='l' || s[i]=='o')
          temp+=s[i];
        if(isSubSequence("hello",temp)==true)
         {
             cout<<"YES"<<endl;
             return;
         }
   }
   cout<<"NO"<<endl;
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