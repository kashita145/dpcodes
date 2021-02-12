//
//  main.cpp
//  dp1
//
//  Created by Kashita Talreja on 06/01/21.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
#pragma GCC optimize("O2")
#define CLR(s) memset(&s, 0, sizeof(s))
#define sz(x) ((long long)(x).size())
#define all(x)  x.begin(),x.end()
#define rall(x) (x).rbegin(), (x).rend()
#define trav(a,x) for (auto& a : x)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define leastsigbit(x)     __builtin_ffs(x)
const int MOD = 1e9 + 7;
#define hmap        unordered_map
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define pii pair<ll,ll>
#define vpii vector<pii>
#define tt ll tt;cin >> tt;while(tt--)
#define  fio ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define D1(x) { cerr << " [" << #x << ": " << x << "]\n"; }
#define D2(x) { cerr << " [" << #x << ": "; for(auto it:x) cerr << it << " "; cerr << "]\n";}
const double PI = acos(-1);
ll add(ll x, ll y) {ll res=x+y; return(res>=MOD?res-MOD:res);}
ll mul(ll x, ll y) {ll res=x*y; return(res>=MOD?res%MOD:res);}
ll sub(ll x, ll y) {ll res=x-y; return(res<0?res+MOD:res);}
ll power(ll a,ll b,ll m=MOD){ ll ans=1; a=a%m;  while(b>0) {  if(b&1)  ans=(1ll*a*ans)%m; b>>=1;a=(1ll*a*a)%m;}return ans;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll lcm( ll x, ll y) { return (x*y)/gcd(x,y);}
bool isprime(ll n){if(n < 2) return 0; ll i = 2; while(i*i <= n){if(n%i == 0) return 0; i++;} return 1;}
bool isPowerOfTwo(int x)
{
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x&(x-1)));
}
double distform(int x, int y, int z, int w) {//(x1,y1,x2,y2)
    return sqrt(1. * pow(x-z,2) + 1. * pow(y-w,2));
}
int dx[]={0,1,1,1,0,-1,-1,-1};
int dy[]={1,1,0,-1,-1,-1,0,1};

//1d approach
int solve2(int n, vector<int>v){
    int dp[n+1];
    memset(dp,0,sizeof(dp));

    for(int i=1;i<=n;i++){
        // you're making a rod of length "i"
        dp[i]=v[i-1];
        for(int j=0;j<i;j++){
            //going thru the other combinations to make find max profit for i 
            //consider price of "j" and the dp[i-j]
                dp[i]=max(dp[i],dp[i-j]+v[j-1]);
        }
    }

    return dp[n];
}


int  solve(){
    int n;
    cin>>n;
    vector<int> price(n);
    for(int i=0;i<n;i++)
        cin>>price[i];
    
    vector<vector<int>> dp(n+1,vector<int>(n+1));

    //initialising
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0)
                dp[i][j]=0;
        }
    }
    
    //filling
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if((i)<=j)// length is lesser than current rod length
                dp[i][j]=max(dp[i-1][j],price[i-1]+dp[i-1][j-(i)]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][n];
}

int32_t main(){
    int ans=solve();
    cout<<ans<<endl;
    return 0;
}
