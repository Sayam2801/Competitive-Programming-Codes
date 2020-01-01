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

int find_unique(int *a,int n)
{
    int count_for_each_bit[64]={0};
    for(int i=0;i<n;i++)
    {
        int j=0;
        while(a[i]>0)
        {
            count_for_each_bit[j] +=(a[i]&1);
            j++;
            a[i]=a[i]>>1;
        }
    }
    for(int i=0;i<64;i++)
    { 
        count_for_each_bit[i]%=3;
    }    
    int ans=0;
    int p=0;
    for(int i=0;i<64;i++)
    {
        ans+=count_for_each_bit[i]*pow(2,p);
        p++;
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
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<find_unique(a,n)<<endl;
    return 0;
}

