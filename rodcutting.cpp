#include<iostream>
using namespace std;

#define max( a, b) (a>b? a:b)

int rodcutting(int arr[],int n){
    int val[n+1];
    val[0]=0;
    int i,j;
    for(i = 1;i<=n ; i++){
    int max_val = 0;
    cout<<max_val<<" ";
    for(j = 0;j<i;j++){
        max_val=max(max_val,arr[j]+val[i-j-1]);
        val[i] = max_val;
        cout<<val[i]<<" ";
    }
    }
    return val[n];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n ;i++){
        cin>>arr[i];
    }
    int x = rodcutting(arr,n);
    cout<<endl;
    cout<<x;
return 0;
}
