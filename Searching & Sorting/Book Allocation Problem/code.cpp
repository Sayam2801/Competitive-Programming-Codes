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

bool isValid(int *books,int size,int students,int pages)
{
    int current_page=0;
    int k=1;
    for(int i=0;i<size;i++)
    {
        if(current_page+books[i] > pages)
        {
            k++;
            current_page = books[i];
            if(k>students)
                return false;
        }
        else
        {
            current_page+=books[i];
        }
    }
    return true;
}

int BinarySearchAlloc(int *books,int size,int students)
{
    int total_pages=0;
    int maxm = INT_MIN;
    for(int i=0;i<size;i++)
    {
        total_pages +=books[i];
        maxm=max(books[i],maxm);
    }
    int start = maxm;
    int end = total_pages;
    int ans;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(isValid(books,size,students,mid))
        {
            ans=mid;
            end=mid-1;
        }
        else
            start=mid+1;
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
        int n,k;
        cin>>n>>k;
        int books[n];
        for(int i=0;i<n;i++)
            cin>>books[i];
        cout<<BinarySearchAlloc(books,n,k)<<endl;
    }
    return 0;
}

