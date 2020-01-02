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

int N=10000000;

void PrimeSieve(int *p)
{
    p[0]=p[1]=0;
    p[2]=1;
    for(int i=3;i<=N;i+=2)
    {
        p[i]=1;
    }
    for(int i=3;i<=N;i++)
    {
        if(p[i]==1)
        {
            for(int  j=i*i;j<=N;j+=2*i)
            {
                p[j]=0;
            }
        }    
    }
    return;
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif                                  //file end
    int p[N+1]={0};
    PrimeSieve(p);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        int ans=0;
        for(int i=a;i<=b;i++)
        {
            if(p[i]==1)
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
