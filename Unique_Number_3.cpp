#include<bits/stdc++.h>
using namespace std;
bool getBit(int n,int pos) 
{
    return (n&(1<<pos))!=0;
}
int setBit(int n,int pos)
{
    return n|(1<<pos);
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) 
           cin>>v[i];
        int result=0;
        for(int i=0;i<64;i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                if(getBit(v[j],i))
                   sum++;
            }
            if(sum%3!=0)
               result=setBit(result,i);
        }
        cout<<result<<endl;
    }
    return 0;
}