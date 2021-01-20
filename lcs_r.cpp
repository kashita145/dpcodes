//
// Created by kashi on 14-10-2020.
//LCS-RECURSIVE
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
#define ff first
#define ss second
#define Endl endl
#define int long long
#define  fio ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
bool cmp(pair<int,int>p1,pair<int,int>p2){
    if(p1.ff == p2.ff)
        return p1.ss < p2.ss;
    return abs(p1.ff-p1.ss) < abs(p2.ff-p2.ss);
}
const int maxn=1e3+1;
int dp[maxn][maxn];

int lcs(string a, string b, int n, int m){
    if(n==0 || m==0)
        return 0;
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(a[n-1]==b[m-1])
        return dp[n][m]=1+lcs(a,b,n-1,m-1);
    else
        return dp[n][m]=max(lcs(a,b,n-1,m),lcs(a,b,n,m-1));
}

int32_t main(){
    string a,b;
    cin>>a>>b;
    memset(dp,-1,sizeof(dp));
    int n=a.size(),m=b.size();
    int ans=lcs(a,b,n,m);
    cout<<dp[n][m]<<endl;
}
