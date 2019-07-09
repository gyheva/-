#include<bits/stdc++.h>
using namespace std;
int i,n,ans;
stack<int> q,p;
void print_sta(stack<int> pri, int i){
    int v=pri.top();
    pri.pop();
    if(i==n) printf("%d",v);
    else{
        print_sta(pri,i+1);
        printf("%d",v);
    }
    if(i==1) printf("\n");
}
void dfs(int nq,stack<int> que,int np,stack<int> pri){
    if(ans==20) return;
    if(np==n){
        ans++;
        print_sta(pri,1);
        return;
    }
    int v;
    if(nq){
        v=que.top();
        pri.push(v);
        que.pop();
        dfs(nq-1,que,np+1,pri);
        que.push(v);
        pri.pop();
    }
    if(nq+np<n){
        que.push(nq+np+1);
        dfs(nq+1,que,np,pri);
    }
}
int main(){
    cin>>n;
    dfs(0,q,0,p);
    //cout<<ans;
}
