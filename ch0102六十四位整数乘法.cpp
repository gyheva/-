#include<bits/stdc++.h>
using namespace std;
long long a,b,p;
long long mul(long long a, long long b, long long p){
    long long t=b,ans=0;

    for(;a;a>>=1){
        if(a&1) ans = (ans+t)%p;
        t = t*2%p;
    }
    return ans;
}
int main(){
    cin>>a>>b>>p;
    a%=p;
    b%=p;
    cout<<mul(a,b,p);
}
