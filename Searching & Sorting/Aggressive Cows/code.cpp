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

bool isValid(int *stalls,int size,int cows,int ans)
{
    int k=1;
    int flag=stalls[0];   //placed cow position
    for(int i=1;i<size;i++)
    {
        if((stalls[i]-flag)>=ans)
        {
            flag=stalls[i];
            k++;
        }
    }
    if(k>=cows)
        return true;
    return false;
}

int MaxStallSeparation(int *stalls,int size,int cows)
{
    int s=0,e=size-1;
    int ans=0;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(isValid(stalls,size,cows,mid))
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
    int n,c;
    cin>>n>>c;
    int stalls[n];
    for(int i=0;i<n;i++)
        cin>>stalls[i];
    sort(stalls,stalls+n);
    cout<<MaxStallSeparation(stalls,n,c)<<endl;
    return 0;
}

