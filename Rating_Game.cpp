#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,p,q,r,anjali=0,maya=0;
    cin>>a>>b>>c>>p>>q>>r;
    if(a>p)
       anjali++;
    else if(a<p)
       maya++;
    if(b>q)
       anjali++;
    else if(b<q)
       maya++;
    if(c>r)
       anjali++;
    else if(c<r)
       maya++;
    cout<<anjali<<" "<<maya<<endl;
    return 0;
}