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

vector<char>lower_case;
vector<char>upper_case;
char lower='a';
char upper='A';

void printtype(char ch)
{
    for(int i=0;i<26;i++)
    {
        if(lower_case[i]==ch)
        {
            cout<<"lowercase"<<endl;
            return;
        }
        if(upper_case[i]==ch)
        {
            cout<<"UPPERCASE"<<endl;
            return;
        }
    }
    cout<<"Invalid"<<endl;
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
    char ch;
    cin>>ch;
    for(int i=0;i<26;i++)
    {
        lower_case.pb(lower);
        lower++;
    }
    for(int i=0;i<26;i++)
    {
        upper_case.pb(upper);
        upper++;
    }
    printtype(ch);
    return 0 ;
}

