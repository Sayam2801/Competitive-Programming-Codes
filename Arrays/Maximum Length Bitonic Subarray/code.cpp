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

int maxBiotonic(vector<int>a)
{
    vector<int>b(a.size());                   //right to left increasing array
    vector<int>c(a.size());                   //left to right increasing array
    int greatestR=1,greatestL=1;
    b[0]=1;
    for(int i=1;i<a.size();i++)
    {
        if(a[i]>a[i-1])
            greatestR++;
        else
            greatestR=1;
        b[i]=greatestR;
    }
    c[a.size()-1]=1;
    for(int i=a.size()-2;i>=0;i--)
    {
        if(a[i]>a[i+1])
            greatestL++;
        else
            greatestL=1;
        c[i]=greatestL;
    }
    int length=0;
    for(int i=0;i<a.size();i++)
        length=max(length,b[i]+c[i]-1);
    return length;
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
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            a.pb(x);
        }
        cout<<maxBiotonic(a)<<endl;
    }
    return 0 ;
}
