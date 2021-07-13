#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int no;
        cin>>no;
        ans^=no;
    }
    cout<<ans<<endl;
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long h=1;
    int t;
	cin>>t;
	while(t--) {
        //cout<<"Test Case "<<h<<":";
        solve();
        h++;
    }
    return 0;
}
