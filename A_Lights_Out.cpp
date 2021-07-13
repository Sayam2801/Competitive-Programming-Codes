#include<bits/stdc++.h>
using namespace std;
//Added 2 extra rows and columns in ans[][] to handle edge lamps 
//row 4 and column 4 are auxilliary
int arr[4][4],ans[4][4];
int main()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++){
           cin>>arr[i][j];
           ans[i][j]=arr[i][j];
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(arr[i][j])
            {
                //While toggling the current light, all the side-adjacent lights will also get that many no. of times.
                ans[i-1][j]+=arr[i][j];
                ans[i+1][j]+=arr[i][j];
                ans[i][j-1]+=arr[i][j];
                ans[i][j+1]+=arr[i][j];
            }
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
              if(ans[i][j]&1)
                 cout<<0;
              else
                cout<<1;
        }
        cout<<'\n';
    }
    return 0;
}