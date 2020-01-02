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

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif                                  //file end
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.pb(x);
    }
    int r[n];
    int l[n];
    int maxm1=0,maxm2=0;
    for(int i=0;i<n;i++)
    {
        maxm1=max(maxm1,a[i]);
        l[i]=maxm1;
    }
    for(int i=n-1;i>=0;i--)
    {
        maxm2=max(maxm2,a[i]);
        r[i]=maxm2;
    }
    int ans=0;
    for(int i=0;i<n;i++)
        ans=ans+min(l[i],r[i])-a[i];
    cout<<ans<<endl;
    return 0;
}
