#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define pb push_back
#define mp make_pair
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define MOD 1000000007  //10^9+7

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

int KthRoot(int n,int k)
{
    int s=0,e=n;
    int ans;
    int mid;
    while(s<=e)
    {
        mid=(s+e)/2;
        if(pow(mid,k)<=n)
        {
            ans=mid;
            s=mid+1;
        }
        else
            e=mid-1;
    }
    return ans;
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
    #endif                                  //file end
    int t;
    cin>>t;
    while(t--)
    {
        int k,n;
        cin>>n>>k;
        cout<<KthRoot(n,k)<<endl;
    }
    return 0;
}

