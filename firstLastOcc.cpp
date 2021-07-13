#include<bits/stdc++.h>
using namespace std;
int firstOcc(int arr[],int n,int i,int val) {
    if(i==n) return -1;
    if(arr[i]==val) return i;
    return firstOcc(arr,n-1,i+1,val);
}
int lastOcc(int arr[],int n,int i,int val) {
    if(i==n) return -1;
    int restArray=lastOcc(arr,n,i+1,val);
    if(restArray!=-1) return restArray;
    if(arr[i]==val) return i;
    return -1;
}
int main() {
    int arr[8]={8,4,3,5,7,2,4,1};
    int n;
    cin>>n;
    cout<<firstOcc(arr,8,0,n)<<endl;
    cout<<lastOcc(arr,8,0,n)<<endl;
    return 0;
}