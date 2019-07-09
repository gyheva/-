#include<bits/stdc++.h>
using namespace std;
long long n,u,a[2000010],c[2000010],sum,avg,mid,i,j,ans;
int main(){
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    avg=sum/n;
    for(i=1;i<n;i++){
        c[i]=c[i-1]+a[i]-avg;
    }
    sort(c+1,c+n+1);
    mid=c[(n+1)/2];
    for(i=1;i<=n;i++){
        ans+=abs(mid-c[i]);
    }
    cout<<ans;
}
