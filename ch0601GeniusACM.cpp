#include<bits/stdc++.h>
using namespace std;
int n,i,q,m,j,a[500010],b[500010],c[500010];
long long t;
long long int val(int l,int r,int p){
    //cout<<l<<"---"<<r<<endl;
    for(int i=r+1;i<=r+p;i++) b[i]=a[i];
    sort(b+r+1,b+r+p+1);
    //for(int i=l;i<=r+p;i++) cout<<b[i]<<" ";
    //cout<<endl;
    int f1=l,f2=r+1;
    for(int i=l;i<=r+p;i++){
        if((b[f1]<=b[f2]&&f1<=r)||f2>r+p){
            c[i]=b[f1];
            f1++;
        }
        else{
            c[i]=b[f2];
            f2++;
        }
    }
    int pa=0;
    long long int sum=0;
    //for(int i=l;i<=r+p;i++) cout<<c[i]<<" ";
    //cout<<endl;
    while(pa<min(m,(r+p-l+1)/2)){
        long long mini=c[l+pa],maxi=c[r+p-pa];
        //cout<<mini<<"<->"<<maxi<<endl;
        sum+=(maxi-mini)*(maxi-mini);
        if(sum>t) break;
        pa++;
    }
    //cout<<l<<" "<<r+p<<" "<<sum<<endl;
    return sum;
}
int findr(int l){
    b[l]=a[l];
    int r=l;
    int p=1;
    while(p){
        p=min(p,q-r);
        if(val(l,r,p)<=t){
            r+=p;
            r=min(r,q);
            if(r==q) break;
            for(int i=l;i<=r;i++){
                b[i]=c[i];
            }
            p*=2;
        }
        else{
            p/=2;
        }
    }
    return r;
}
int calc(){
    int st=1,ans=0;
    while(st<=q){
        //cout<<st<<"*"<<endl;
        st=findr(st)+1;
        ans++;
    }
    return ans;
}
int main(){
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>q>>m>>t;
        for(j=1;j<=q;j++) cin>>a[j];
        cout<<calc()<<endl;
    }
}
