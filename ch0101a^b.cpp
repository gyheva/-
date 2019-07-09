#include<bits/stdc++.h>
using namespace std;
long long int a,b,t,p,ans;
int main(){
    cin>>a>>b>>p;
    t=a;
    if(p==1) ans=0;
    else ans=1;
    for(;b;b>>=1){
        if(b&1) ans = ans*t%p;
        t = t*t%p;
    }
    cout<<ans;
}
