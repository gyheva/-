#include<bits/stdc++.h>
using namespace std;
int i,j,n,b[6][6],ans,k,m[6][6];
string s;
bool f;
void dfs(int x,int t,int a[6][6]){
    //cout<<x<<" "<<y<<" || "<<t<<" "<<sum<<endl;
    /*for(int i=1;i<=5;i++){
            for(int j=1;j<=5;j++){
                cout<<a[i][j];
            }
            cout<<endl;
        }*/

    if(x==6){
        for(int i=1;i<=5;i++){
            for(int j=1;j<=5;j++){
                m[i][j]=a[i][j];
            }
        }
        for(int i=2;i<=5;i++){
            for(int j=1;j<=5;j++){
                if(m[i-1][j]==0){
                    m[i][j]=m[i][j]^1;
                    t++;
                    if(j-1>=1) m[i][j-1]=m[i][j-1]^1;
                    if(i-1>=1) m[i-1][j]=m[i-1][j]^1;
                    if(i+1<=5) m[i+1][j]=m[i+1][j]^1;
                    if(j+1<=5) m[i][j+1]=m[i][j+1]^1;
                }
            }
        }
        if(m[5][1]+m[5][2]+m[5][3]+m[5][4]+m[5][5]==5&&t<=6) ans=min(ans,t);
        return;
    }
    a[1][x]=1^a[1][x];
    a[2][x]=a[2][x]^1;
    if(x-1>=1) a[1][x-1]=a[1][x-1]^1;
    if(x+1<=5) a[1][x+1]=a[1][x+1]^1;
    dfs(x+1,t+1,a);
    a[1][x]=1^a[1][x];
    a[2][x]=a[2][x]^1;
    if(x-1>=1) a[1][x-1]=a[1][x-1]^1;
    if(x+1<=5) a[1][x+1]=a[1][x+1]^1;
    dfs(x+1,t,a);
}
int main(){
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=5;j++){
            cin>>s;
            for(k=0;k<5;k++){
                b[j][k+1]=s[k]-48;
            }
        }
        ans=10;
        dfs(1,0,b);
        if(ans==10) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
}
