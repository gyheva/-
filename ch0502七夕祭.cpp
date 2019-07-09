#include<bits/stdc++.h>
using namespace std;
long long int n,m,q,q1,q2,i,x,y,row[100010],col[100010],fr,fc,avg,num,sr[100010],sc[100010],ac,ar;
int main(){
    cin>>n>>m>>q;
    for(i=1;i<=q;i++){
        cin>>x>>y;
        row[x]++;
        col[y]++;
    }
    for(i=1;i<=n;i++) q1+=row[i];
    for(i=1;i<=m;i++) q2+=col[i];
    fr=0;
    fc=0;
    if(q1%n==0) fr=1;
    if(q2%m==0) fc=1;
    if(fr&&fc) cout<<"both ";
    else if(fr) cout<<"row ";
    else if(fc) cout<<"column ";
    else cout<<"impossible ";
    if(fr){
        avg=q1/n;
        for(i=1;i<=n;i++) row[i]-=avg;
        for(i=1;i<=n;i++) sr[i]=sr[i-1]+row[i];
        sort(sr+1,sr+n+1);
        num=sr[n+1>>1];
        for(i=1;i<=n;i++) ar+=abs(sr[i]-num);
    }
    if(fc){
        avg=q2/m;
        for(i=1;i<=m;i++) col[i]-=avg;
        for(i=1;i<=m;i++) sc[i]=sc[i-1]+col[i];
        sort(sc+1,sc+m+1);
        num=sc[m+1>>1];
        for(i=1;i<=m;i++) ac+=abs(sc[i]-num);
    }
    if(fr||fc) cout<<ac+ar;
}
