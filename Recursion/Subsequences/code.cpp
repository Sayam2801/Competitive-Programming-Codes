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

void subsequences(char str[],int index,int i,char str1[])
{
    if(str[index]=='\0'){
        str1[i]='\0';
        cout<<str1<<" ";
        cnt++;
        return;
    }
    subsequences(str,index+1,i,str1);
    str1[i]=str[index];
    subsequences(str,index+1,i+1,str1);
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif                                  //file end
    char str[1000],str1[1000];
    cin>>str;
    subsequences(str,0,0,str1);
    cout<<endl<<cnt<<endl;
    return 0;
}  
