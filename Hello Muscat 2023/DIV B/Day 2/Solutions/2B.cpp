#include<bits/stdc++.h>
#pragma GCC optimzie "Ofast"
#define prob "A"
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
int n,m;
int a[501][501];
int dp[501][1024];
void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }
    dp[0][0] = 1;
    for(int i=1;i<=m;i++) dp[1][a[1][i]] = 1;

    for(int i=2;i<=n;i++){
        for(int j=0;j<=1023;j++){
            for(int k=1;k<=m;k++){
                dp[i][j] |= dp[i-1][a[i][k]^j];
            }
        }
    }

    int state = -1;
    for(int i=1;i<=1023;i++) if(dp[n][i]) {state = i; break;}
    if(state == -1){
        cout << "NIE";
        return;
    }
    vector<int> ans;
    for(int i=n;i>=1;i--){
        for(int j=1;j<=m;j++){
            if(dp[i-1][state^a[i][j]]){
                ans.push_back(j);
                state ^= a[i][j];
                break;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    cout << "TAK" << endl;
    for(int u: ans) cout << u << " ";
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


