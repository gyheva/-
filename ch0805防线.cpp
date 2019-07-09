#include<bits/stdc++.h>
using namespace std;
int t,n,p,s,e,d,f,i,j,k;
int a[220000000];
void bin_se(int l, int r){
    if(l==r){
        if(a[l]%2==1) cout<<l<<" "<<a[l]-a[l-1]<<endl;
        else cout<<"There's no weakness."<<endl;
        return;
    }
    int mid=(l+r)/2;
    if(a[mid]%2==1) bin_se(l,mid);
    else bin_se(mid+1,r);
}
int main(){
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        memset(a,0,sizeof(a));
        f=0;
        for(int j=1;j<=n;j++){
            cin>>s>>e>>d;
            for(int k=s;k<=e;k+=d){
                f=max(f,k);
                a[k]++;
            }
        }
        for(int j=2;j<=f;j++) a[j]+=a[j-1];

        bin_se(1,f);
    }
}
