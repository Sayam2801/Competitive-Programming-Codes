//Program to print all subsequences of string in lexicographically ordered manner
#include <bits/stdc++.h>
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>*/

using namespace std;
//using namespace __gnu_pbds;

//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e18 + 42;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > ppi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
#define pb push_back
//#define mp make_pair
#define f first
#define s second
#define endl '\n'
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORS(s) for(int i=0;i<s.length();i++)
#define FORL(i,n) for(ll i=0;i<n;i++)
#define vpll vector<pair<ll,ll> > 
#define input int t; cin>>t; while(t--)
#define SORT(arr) sort(arr,arr+n);
#define LSOne(S) (S & (-S))
#define isBitSet(S, i) ((S >> i) & 1)
#define mod 998244353
#define all a.begin(),a.end()
#define MAXN 100005
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
int noOfDigits(ll k)
{
    int cnt=0;
    while(k)
    {
        cnt++;
        k/=10;
    }
    return cnt;
}
class DisJointSet
{
    public:
              vector<int> par;
              vector<int> size;
              int total_size;
              void init(int n)
              {
                  par.resize(n);
                  size.resize(n);
                  for(int i=0;i<n;i++) 
                     par[i]=i;
                  for(int i=0;i<n;i++)
                     size[i]=1;
                  total_size=n;
              }
              int get_superParent(int x)
              {
                  if(x==par[x])
                      return x;
                  else
                      return par[x]=get_superParent(par[x]); //Path Compression
              }
              void unite(int x,int y)
              {
                  int superParentX=get_superParent(x);
                  int superParentY=get_superParent(y);
                  if(superParentX!=superParentY)
                  {
                      par[superParentX]=superParentY;
                      size[superParentY]+=size[superParentX];
                      size[superParentX]=0;
                      total_size--;//When two different components get connected, then their total size reduces by 1 as they become common and their unique identity is vanished..
                  }
              }
};
vector<int> graph[100005];
vector<bool> visited(100005,false);
void dfs(int src)
{
    visited[src]=true;
    for(int it:graph[src])
    {
        if(!visited[it])
           dfs(it);
    }
    return;
}
bool isPerfect(int n)
{
  int sum=0;
  for(int i=1;i<=n/2;i++)
  {
    if(n%i==0)
      sum+=i;
  }
  if(sum==n)
    return true;
  return false;
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
string findSubsequence(string s,ll binary,ll len)
{
     string res="";
     for(ll i=0;i<len;i++)
     {
         if(binary&(1<<i))
          res+=s[i];
     }
     return res;
}
void possibleSubsequences(string s,ll n){ 
   map<int,set<string> > mp;
   ll limit=pow(2,n),len=n;
   for(ll i=1;i<=limit-1;i++)
   {
       string sub=findSubsequence(s,i,len);
       mp[sub.length()].insert(sub);
   } 
   for(auto it:mp)
   {
      cout<<"Subsequences of string of length "<<it.first<<" are as follows:"<<endl;
      for(auto temp:it.second)
        cout<<temp<<endl;
   }
   return;
} 
void countSubsequences(int arr[],int n,int x)
{
  set<vector<int> > s;
  int limit=pow(2,n);
  FOR(i,limit-1)
  {
    int j=0,temp=i;
    vector<int> t;
    while(temp)
    {
      if(temp&1)
        t.pb(arr[j]);
      temp/=2;
      j++;
    }
    int sum=0;
    for(auto x:t)
      sum+=x;
    if(sum==x)
      s.insert(t);
  }
  for(auto x:s)
  {
    for(auto ele:x)
      cout<<ele<<" ";
    cout<<endl;
  }
  return;
}
ll findLengthOfShortestSubarray(vector<ll> &arr)
{
  ll n = arr.size();
        
        ll idx = n-1;
        while(idx > 0 && arr[idx] >= arr[idx-1]) idx--;

        if(idx == 0) return 0;
        
        ll res = idx;
        
        for(int i = 0; i < idx; i++){
            if(i && arr[i] < arr[i-1]) break;
            ll val = arr[i];
            
            ll j = lower_bound(arr.begin()+idx, arr.end(), val) - arr.begin();
            res = min(res, j-i-1);
        }
        
        return res;
}
void solve(){
  
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //input{
        //cout << "Test Case: "<<t  << ": ";
        solve();
    //}
    return 0;
}