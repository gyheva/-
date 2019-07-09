#include<bits/stdc++.h>
using namespace std;
deque<int> a[15];
int i,j,ans,pre,cur,now,k[15];
char x;
int main(){
    for(int i=1;i<=13;i++){
        for(int j=1;j<=4;j++){
            cin>>x;
            if(x>='2'&&x<='9') a[i].push_back(x-'0');
            else if(x=='0') a[i].push_back(10);
            else if(x=='A') a[i].push_back(1);
            else if(x=='J') a[i].push_back(11);
            else if(x=='Q') a[i].push_back(12);
            else a[i].push_back(13);
            //cout<<a[i].back()<<endl;
        }
    }
    cur=a[13].front();
    a[13].pop_front();
    while(true){
        if(cur==13){
            if(a[13].empty()) break;
            cur=a[13].front();
            a[13].pop_front();
            continue;
        }
        a[cur].push_front(cur);
        k[cur]++;
        pre=cur;
        cur=a[cur].back();
        a[pre].pop_back();
    }

    for(int i=1;i<=12;i++){
        pre=a[i].front();
        a[i].pop_front();
        for(j=2;j<=4;j++){
            now=a[i].front();
            a[i].pop_front();
            if(pre!=now) break;
        }
        if(j==5&&k[i]>=4) ans++;
    }
    cout<<ans;
}
