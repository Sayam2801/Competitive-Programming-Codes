#include <bits/stdc++.h>
using namespace std;
void reverse(string s)
{
    if(s.length()==0)
       return;
    string rem=s.substr(1);
    reverse(rem);
    cout<<s[0];
}
int main() {
    string s;
    cin>>s;
    reverse(s);
    return 0;
}