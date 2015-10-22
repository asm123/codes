#include<iostream>
#define for(a,b,c) for(int a=b;a<=c;a++)
using namespace std;int a[101][101],t;int main(){cin>>t;while(t--){int l,m=0;cin>>l;for(i,1,l)for(j,1,i){cin>>a[i][j];(a[i][j]=max(a[i-1][j-1],a[i-1][j])+a[i][j])>m?m=a[i][j]:m;}cout<<m<<endl;}}