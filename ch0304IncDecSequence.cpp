#include<bits/stdc++.h>
using namespace std;
long long n,i,j,a[100010],b[100010],neg,pos;
long long qpow(long long b,long long p){
    long long ans=1;
    for(;p;p>>=1){
        if(p&1) ans*=b;
        b*=b;
    }
    return ans;
}
int main(){
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
    for(j=2;j<=n;j++){
        b[j]=a[j]-a[j-1];
        if(b[j]>0) pos+=b[j];
        else neg+=b[j];
    }
    cout<<max(pos,abs(neg))<<endl<<abs(pos+neg)+1;

}
