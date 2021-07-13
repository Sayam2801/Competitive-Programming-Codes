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
#define mod 1000000007
#define MOD 1000000007
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
#define vs vector<string>
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
#define sq(n) n*n
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
class Triplet
{
    public:
    ll x,y;
    ll g;
};
Triplet extendedEuclideanAlgorithm(ll a,ll b)
{
    if(b==0)
    {
        Triplet ans;
        ans.x=1;
        ans.y=0;
        ans.g=a;
        return ans;
    }
    Triplet smallAns=extendedEuclideanAlgorithm(b,a%b);
    Triplet ans;
    ans.x=smallAns.y;
    ans.y=smallAns.x-(a/b)*smallAns.y;
    return ans;
}
ll mmE(ll a,ll m)
{
    Triplet ans=extendedEuclideanAlgorithm(a,m);
    return (ans.x%m + m)%m;
}
string findSubsequence(string s,int binary,int n)
{
    string ans="";
    for(int i=0;i<n;i++)
    {
        if(binary&(1<<i))
           ans+=s[i];
    }
    return ans;
}
/* Explanation:
The difference between the diagonal elements of the spiral is the arithmetic sequence 0,2,4,6,8,…. Sum of n terms of this is n(n−1) (by the usual AP formula). This sum, incremented by 1, gives the diagonal element at position (n,n)

.

Given (x,y)
, we find the maximum of these two, which is the "layer" of the spiral that this point belongs to. Then, we find the diagonal value of that layer as v=n(n−1)+1. For even layers, the value at (x,y) is then v+x−y, for odd layers v−x+y. 
From the above, we know that the function we want is

f=m∗(m−1)+1+(−1)m∗(x−y)

where m=max(x,y)

.

Some basic calculation will show that one expression for max of two numbers is

m=max(x,y)=x+y+abs(x−y)2

Plugging one into another, we find that one alternate form for f

is:

f=(x−y)⋅ik+14((k−2)⋅k)+1

where k=abs(x−y)+x+y

.

This is the function the solution implements. 
The position (x,y) is located on arm max(x,y) (assigned to variable z). Then, the largest number on arm n is n2, which alternates between being in the bottom left and top right position on the arm. Subtracting x from y gives the sequence −n+1,−n+2,…,−1,0,1,…,n−1,n−2 moving along arm n, so we choose the appropriate sign based on the parity of n, adjust by n−1 to get a sequence starting at 0, and subtract this value from n2.

CSES Problem Set - Number Spiral Problem Solution - Competitive Programming Questions
All Programming Resources August 21, 2020 0 Comments
Share:

    Facebook
    Twitter
    Google+
    Pinterest

CSES  Problem Set - Number Spiral Problem Solution - Competitive Programming Questions Series


// SO IN THIS PROBLEM WE ARE GIVEN A NUMBER SPIRAL AND ARE TASK IS TO FIND THE NUMBER IN SOME ROW AND COLUMN THAT WILL BE DENOTED BY X AND Y 

// SO OUR TASK IS TO FIND NUMBER IN SPIRAL AT ANY ROW Y AND COLOUMN X IN THE SPIRAL 

// ALSO CONSTRAINTS ARE LARGE FOR X AND Y THAT IS 10^9, SO WE HAVE TO USE FAIRLY FAST ALGORITHM 

// THAT SOLVES IT WITHOUT TIME LIMIT EXCEEDED ERRORS. SO WE WILL PREFER TO USE THE LONG LONG TYPE 

// AND ALSO NOT TO USE NESTED LOOPS SO THAT WE SOLVE IT IN FAIRLY LINEAR TIME, AND THUS NOT EXCEEDING TIME LIMIT 

// SO LETS SEE THE SOLUTION: 

#include<bits/stdc++.h> 

// so we have our header file 

using namespace std;

int main () 

{

        // so we have our main function 

        // now we have to input the number of test cases and value of x and y for each test case 

        // so lets generate these variables first 

        long long t;

        // this will denote the number of test cases 

        long long x; 

        // this will denote the COLOUMN number, for which user wants the output number in the spiral 

        long long y;

        // this will denote the ROW number, for which user wants the output number in the spiral

        // so lets take the input for test cases

        cin >> t;

        // now lets generate a while loop, in which we will take the input corresponding to each test case 

  // that is we will calculate the x and y for each test case and then we will calculate the output for that x and y also

  // so let generate the while loop and this while loop will be executed t times and thus till t is greater than zero 

        while (t>0) {

                // now lets take the input for x and y for each test case 

                // also we will decrement t after each execution of test case and thus this loop will occur t times 

                // and obviously it should go on till t>0 

                // so lets take the input 

                cin >> y >> x; // make a small correction here, we have to input y first then x : row and column

                // so we have done with input of x and y that is column and row corresponding to each test case 

                // now lets calculate the output number in the spiral for the input x and y 

                // for this we initialize a variable z 

                // z will contain the maximum of x and y 

                // thus :

                long long z;

                z = max(x,y);

                // now notice the spiral in the question


                // NOTICE THAT THE DIFFERENCE OF DIAGONAL ELEMENTS IN THE SPIRAL FORMS AN ARITHMETIC PROGRESSION 

                // THE AP IS OF THE FORM: 0,2,4,6,8,.....

                // THUS YOU CAN SEE AP IS BEING FORMED 

                // ALSO NOTE THAT : SUM OF N TERMS OF THIS IS N(N-1) 

                // NOW THIS SUM INCREMENTED BY 1 GIVES THE DIAGNOL ELEMENT AT (N,N)

                // YOU CAN CROSS CHECK THIS FACT BY CHECKING FOR N =1,2,3... IN GIVEN SPIRAL 

                // THIS IS THE LOGIC OF THE GIVEN SPIRAL, NOTE THIS IT IS IMPORTANT 

                // WE WILL STORE THIS NUMBER AT DIAGNOL (N,N) IN ANOTHER VARIABLE 

                // SO LETS DO IT 


                long long  ap;

                // now what will be value of N, N will surely be maximum of x and y, thus N = z simply 

                // thus:

                ap = z*(z-1) + 1;

                // thus ap stores the value at diagnol for (N,N) where N is maximum of x,y 

                // now lets initialise a variable to calculate final output answer 

                long long ans;

                // thus we initialised it 

                // now:

                if( z%2==0) {

                        // this shows that z is even 

                       // now:

                       ans = ap + y - x ;

                       // now this will give us right answer 

                       // we first calculated z, actually z represents the layer of spiral 

                       // which is maximum of x and y 

              // then we calculated ap which was diagnol number at (N,N) where N was layer number that is z 

                   // now if layer number is even then the number at row y and column x in spiral will be as shown above

                   // this is because, note in the spiral for 2nd row and 1st column that is (2,1) = (y,x) 

                   // we have diagonal ELEMENT ap for (2,1) as 3, as z=2 here 

                   // also if we go in left direction of 3 in the spiral, number increases to 4 

                   // this will only happen if we increment z by y-x as y>x here 

                   // thus ans will give right answer here 

                   // now apply this logic for every y and x where layer number z is even we will get right answer 

                   // thus this is the logic of this spiral

                   // every spiral has a logic, and this is the logic of this spiral through which it is made

                   }

                   else {

                           // now if layer number z is odd 

                           ans = ap + x - y;

                           // this will give right answer when z is odd 

                           // as you can see in case of (3,1) = (y,x) where ap is 7 and if we go in left direction 

                           // number decrements, this can happen only if we add x-y to ap as y>x here 

                           // thus ans will give right answer 

                           // this is logic of this spiral 

                           // you can check it by putting general x and y and use this algorithm 

                           // we have given you basic understanding how this logic worked 

                           // as every spiral has a logical function how it is made 

                           // we are calculating numbers, by first calculating layer number which was max of x and y 

                           // then we calculated diagonal number for that layer number z 

                           // then we checked if z was even or odd 

                           // then we applied our basic approach for each case 

                           // thus we calculated number in spiral at row y and coloumn x 

                           // this we did in fairly linear time complexity 

                           // see the basic reasoning we gave to understand the code

                }

                

                // now lets output the answer

                cout << ans << "\n";

                // also we decrement t after execution of each test case 

                t--;

              // you will get right answer after compiling this

// I hope you liked it, follow the blog for more resources

                                }

                return 0;

  }*/
void solve(){
     ll y,x;
     cin>>y>>x;
     ll m=max(y,x),m2=(m-1)*(m-1),ans=0;
     if(m%2==0)
     {
        if(m==x)
            ans=m2+y;
        else
            ans=m2+2*m-x;
     }
     else
     {
         if(m==y) 
            ans=m2+x;
        else
            ans=m2+2*m-y;
     }
     cout<<ans<<endl;
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