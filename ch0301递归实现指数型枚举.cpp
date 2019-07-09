#include<bits/stdc++.h>
using namespace std;
//method 1:µÝ¹é
vector<int> que;
vector<int>::iterator it;;
int n;
void calc(int k){
    if(k==n+1){
        for(it=que.begin();it!=que.end();it++){
            cout<<(*it)<<" ";
        }
        cout<<endl;
        return;
    }
    else{
        calc(k+1);
        que.push_back(k);
        calc(k+1);
        que.pop_back();

    }
}
int main(){
    cin>>n;
    calc(1);
}
//method 2:Î»ÔËËã
int i,n,num,cur,h[1000000];
int main(){
    cin>>n;
    for(i=0;i<n;i++) h[1<<i]=i+1;
    for(i=0;i<(1<<n);i++){
        num=i;
        cur=0;
        while(num){
            if(num&1) cout<<h[1<<cur]<<" ";
            num>>=1;
            cur++;
        }
        cout<<endl;
    }
}
