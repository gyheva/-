#include<bits/stdc++.h>
using namespace std;
vector<int> que;
vector<int>::iterator it;;
int n,m;
void calc(int k){
    if(que.size()==m){
        for(it=que.begin();it!=que.end();it++){
            cout<<(*it)<<" ";
        }
        cout<<endl;
        return;
    }
    else if(k==n+1) return;
    else{

        que.push_back(k);
        calc(k+1);
        que.pop_back();
        calc(k+1);

    }
}
int main(){
    cin>>n>>m;
    calc(1);
}
