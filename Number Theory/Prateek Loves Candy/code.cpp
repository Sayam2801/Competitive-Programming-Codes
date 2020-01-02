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

int N=1000000;
vector<int> ind;

void PrimeSieve(int *p)
{
    p[0]=0;
    p[1]=0;
    p[2]=1;
    for(int i=3;i<=N;i+=2)
    {
        p[i]=1;
    }
    for(int i=3;i*i<=N;i+=2)
    {
        if(p[i])
        {
            for(int j=i*i;j<=N;j=j+2*i)
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
    for(int i=0;i<=N;i++)
    {
        if(p[i])
            ind.pb(i);
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<ind[n-1]<<endl;
    }
    return 0;
}


