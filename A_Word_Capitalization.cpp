#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    char ch=s[0];
    if(ch>='a'&&ch<='z')
      cout<<(char)toupper(ch);
    else
    {
        cout<<ch;
    }
    for(int i=1;i<s.length();i++)
       cout<<s[i];
    cout<<endl;
    return 0;
}