//
// Created by kashi on 14-10-2020.
//LCS-iterative
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

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j==0)
                dp[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=0;
        }
    }
    return dp[n][m];
}

int32_t main(){
    string a,b;
    cin>>a>>b;
    memset(dp,-1,sizeof(dp));
    int n=a.size(),m=b.size();
    int ans=lcs(a,b,n,m);
    cout<<dp[n][m]<<endl;
}
