#include<bits/stdc++.h>
using namespace std;
long long n,i,j,a[3][250010],c[250010],t[250010],ans,x;
void merge(int k, int l, int mid, int r)
{
	int x = l, y = mid + 1;
	for (int i = l; i <= r; i++)
	{
		if (y>r || x <= mid&&a[k][x]<a[k][y])
			c[i] = a[k][x++];
		else ans += mid - x + 1, c[i] = a[k][y++];
	}
	for (int i = l; i <= r; i++) a[k][i] = c[i];
}

void mergesort(int k, int l, int r)
{
	if (l == r) return;
	int mid = (l + r) / 2;
	mergesort(k, l, mid);
	mergesort(k, mid + 1, r);
	merge(k, l, mid, r);
}

long long calc(int k)
{
	ans = 0;
	mergesort(k, 0, n*n-1);
	return ans;
}

int main(){
    while(cin>>n){
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        for(i=0;i<n*n-1;i++){
            cin>>x;
            if(x) a[1][i]=x;
            else i--;
        }
        long long a1=calc(1);
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        for(i=0;i<n*n-1;i++){
            cin>>x;
            if(x) a[2][i]=x;
            else i--;
        }
        long long a2=calc(2);
        //cout<<a1<<" "<<a2;
        if(a1%2==a2%2) cout<<"TAK"<<endl;
        else cout<<"NIE"<<endl;
    }
}
/*
long long merge_sort(long long l,long long r){
    //cout<<l<<" "<<r<<endl;
    if(l==r) return 0;
    long long ans=0;
    long long mid=(l+r)/2;
    //cout<<l<<"__"<<mid<<endl;
    ans=merge_sort(l,mid);
    //cout<<2<<endl;
    ans+=merge_sort(mid+1,r);
    long long nl=l,nr=mid+1;
    long long k=1;
    while(nl<=mid&&nr<=r){
        //cout<<nl<<"*"<<nr<<endl;
        long long cur1=a[nl];
        long long curr=a[nr];
        if(cur1<=curr){
            t[k]=a[nl];
            nl++;
            k++;
        }
        else{
            ans+=mid-nl+1;
            t[k]=a[nr];
            nr++;
            k++;
        }
    }
    for(long long i=nl;i<=mid;i++){
        t[k]=a[i];
        k++;
    }
    for(long long i=nr;i<=r;i++){
        t[k]=a[i];
        k++;
    }
    for(long long i=l;i<=r;i++) a[i]=t[i];
    return ans;
}
*/
