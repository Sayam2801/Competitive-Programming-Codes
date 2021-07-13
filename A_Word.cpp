#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int ucnt=0,lcnt=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='a'&&s[i]<='z')
           lcnt++;
        else
          ucnt++;        
    }
    if(lcnt>=ucnt)
    {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        cout<<s<<endl;
    }
    else
    {
        transform(s.begin(),s.end(),s.begin(),::toupper);
        cout<<s<<endl;
    }
    return 0;
}