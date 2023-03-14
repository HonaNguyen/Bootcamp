#include<bits/stdc++.h>
#pragma GCC optimzie "Ofast"
#define prob "E"
#define ll long long
#define fi first
#define se second
using namespace std;
const int maxn = 1e5;
const int MOD = 1e9 + 7;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};
typedef pair<int,int> pi;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
int dp[24][60];
void solve(){
    int a1,b1,a2,b2;
    cin >> a1 >> b1 >> a2 >> b2;
    int h1,m1,h2,m2;
    cin >> h1 >> m1 >> h2 >> m2;
    queue<pi> Q;
    for(int i=0;i<=26;i++)
        for(int j=0;j<=59;j++) dp[i][j] = 1e9;
    dp[h1][m1] = 0;
    Q.push({h1,m1});
    while(Q.size()){
        pi u = Q.front();
        Q.pop();
        if(u.fi == h2 && u.se == m2){
            cout << dp[h2][m2];
            return;
        }
        if(1 + 1 == 2){
            int newh = (u.fi + a1) % 24;
            int newm = (u.se + b1) % 60;
            if(dp[u.fi][u.se] + 1 < dp[newh][newm]){
                dp[newh][newm] = dp[u.fi][u.se] + 1;
                Q.push({newh,newm});
            }
        }
        if(1 + 1 == 2){
            int newh = (u.fi + a2) % 24;
            int newm = (u.se + b2) % 60;
            if(dp[u.fi][u.se] + 1 < dp[newh][newm]){
                dp[newh][newm] = dp[u.fi][u.se] + 1;
                Q.push({newh,newm});
            }
        }
    }
    cout << -1;
}
int main(){
    if(fopen(prob".inp","r")){
        freopen(prob".inp","r",stdin);
        freopen(prob".out","w",stdout);
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tc = 1;
//    cin >> tc;
    while(tc--) solve();
}


