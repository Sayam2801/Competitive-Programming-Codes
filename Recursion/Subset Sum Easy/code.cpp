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

int cnt=0;

bool Subsetzero(int a[],int n,int b[],int i,int j)
{
    if(i==n){
        int sum=0;
        for(int k=0;k<j;k++){
            sum+=b[k];
        }
        if(sum==0 && j>0 && cnt==0){
            cout<<"Yes"<<endl;
            cnt++;
            return true;
        }
        else
            return false;
    }
    Subsetzero(a,n,b,i+1,j);
    b[j]=a[i];
    Subsetzero(a,n,b,i+1,j+1);
    return false;
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
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int b[n];
        Subsetzero(a,n,b,0,0);
        if(cnt==0)
            cout<<"No"<<endl;
        cnt=0;
    }
    return 0;
}

