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

int BinarySearchInRotated(int *a,int size,int key)
{
    int s=0,e=size-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(a[mid]==key)
            return mid;
        if(a[s]<=a[mid])
        {
            if(a[s]<=key&&key<=a[mid])
                e=mid-1;
            else
                s=mid+1;
        }
        else if(a[mid]<=key && key<=a[e])
            s=mid+1;
        else
            e=mid-1;
    }
    return -1;
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
    int key;
    cin>>key;
    cout<<BinarySearchInRotated(a,n,key)<<endl;
    return 0;
}

