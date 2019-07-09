#include<bits/stdc++.h>
using namespace std;
vector<int> num;
vector<int>::iterator it;
int n,f[30];
void dg(int k){
    if(k==n+1){
        for(it=num.begin();it!=num.end();it++){
            cout<<(*it)<<" ";
        }
        cout<<endl;
    }
    else{
        for(int i=1;i<=n;i++){
            if(f[i]==0){
                num.push_back(i);
                f[i]=1;
                dg(k+1);
                f[i]=0;
                num.pop_back();
            }
        }
    }
}
int main(){
    cin>>n;
    dg(1);
}
