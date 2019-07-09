#include<bits/stdc++.h>
using namespace std;
struct peo{
    long long x,y,pro;
}p[11000];
bool cmp(peo a,peo b){
    if(a.pro!=b.pro) return a.pro<b.pro;
    else return a.y<b.y;
}
long long a,b,n,i,maxi,tot,cur,fin[50000];
char sum[50000];
void multi(long long k){
    //cout<<"k:"<<k<<endl;
    int ans[50000];
    memset(ans,0,sizeof(ans));
    //cout<<tot<<endl;
    int i=0;
    for(i=0;i<strlen(sum);i++){
        ans[i]+=k*(sum[i]-'0');
        ans[i+1]=ans[i]/10;
        ans[i]%=10;
        //cout<<i<<" "<<ans[i+1]<<" "<<ans[i]<<endl;
    }
    while(ans[i]>=10){
        ans[i+1]=ans[i]/10;
        ans[i]%=10;
        i++;
    }
    if(ans[i]==0) i--;
    tot=i;
    //cout<<"tot:"<<tot<<endl;
    for(int i=tot;i>=0;i--){
        sum[i]=ans[i]+'0';
        //cout<<sum[i];
    }
    //cout<<endl;
}
void divd(long long k){

    //for(int i=tot;i>=0;i--) cout<<sum[i];
    //cout<<"**sum"<<endl;
    int ys=0,f=0,ans[50000];
    //cout<<sum[0]<<endl;
    int lens=strlen(sum);
    for(int i=lens-1;i>=0;i--){
        ys*=10;
        ys+=sum[i]-'0';
        ans[i]=ys/k;
        ys%=k;
        //cout<<"ans["<<i<<"]"<<ans[i]<<endl;
    }
    int lena=lens;
    while(lena>1&&ans[lena-1]==0){
        lena--;
    }
    //cout<<"size:"<<ans.length()<<endl;
    //for(int i=0;i<ans.length();i++) cout<<ans[i];
    //cout<<endl;
    if(lens>cur){
        for(int i=0;i<lena;i++) fin[i]=ans[i];
        cur=lena;
    }
    else if(lens==cur){
        for(int i=cur-1;i>=0;i--){
            if(fin[i]<ans[i]){
                f=1;
                break;
            }
            else if(fin[i]>ans[i]){
                f=2;
                break;
            }
        }
        if(f==1){
            for(int i=0;i<lena;i++) fin[i]=ans[i];
        }
    }

}
int main(){
    cin>>n>>a>>b;
    for(i=1;i<=n;i++){
        cin>>p[i].x>>p[i].y;
        p[i].pro=p[i].x*p[i].y;
    }
    sort(p+1,p+n+1,cmp);
    i=-1;
    while(a){
        i++;
        sum[i]=a%10+'0';
        a/=10;
    }
    tot=i;
    for(int i=1;i<=n;i++){
        //cout<<i<<endl;
        if(p[i].y>p[i-1].x*p[i-1].y&&i-1>=1){
            divd(p[i-1].y);

        }
        if(i!=n) multi(p[i].x);
    }
    divd(p[n].y);
    for(int i=cur-1;i>=0;i--) cout<<fin[i];
}
