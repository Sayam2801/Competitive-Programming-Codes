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

int kadane(vector<int>a)
{
    int csum=0,maxsum=INT_MIN;
    for(int i=0;i<a.size();i++)
    {
        csum=csum+a[i];
        if(csum<0)
            csum=0;
        maxsum=max(maxsum,csum);
    }
    return maxsum;
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
        int n;
        cin>>n;
        vector<int>a;
        int sumofall=0;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            a.pb(x);
            sumofall=sumofall+x;
        }
        int k1=kadane(a);
        vector<int>b(n);
        for(int i=0;i<n;i++)
        {
            b[i]=-1*a[i];
        }
        int k2=sumofall-(-1*kadane(b));
        cout<<max(k1,k2)<<endl;
    }
    return 0 ;
}
