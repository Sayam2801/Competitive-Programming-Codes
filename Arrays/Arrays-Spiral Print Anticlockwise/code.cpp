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
    int m,n;
    cin>>m>>n;
    int a[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    int Endrow=m-1,Startrow=0,StartCol=0,EndCol=n-1;
    while(Endrow>=Startrow&&EndCol>=StartCol)
    {
        for(int i=Startrow;i<=Endrow;i++)
            cout<<a[i][StartCol]<<", ";
        StartCol++;
        for(int i=StartCol;i<=EndCol;i++)
            cout<<a[Endrow][i]<<", ";
        Endrow--;
        for(int i=Endrow;i>=Startrow;i--)
            cout<<a[i][EndCol]<<", ";
        EndCol--;
        for(int i=EndCol;i>=StartCol;i--)
            cout<<a[Startrow][i]<<", ";
        Startrow++;
    }
    cout<<"END"<<endl;
    return 0 ;
}
