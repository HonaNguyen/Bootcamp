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
int parent[maxn+5];
int dp[maxn+5];
void solve(){
    int n,a,b;
    cin >> n >> a >> b;
    queue<int> Q;
    for(int i=0;i<=n;i++) dp[i] = 1e9;
    dp[a] = 0;
    Q.push(a);
    while(Q.size()){
        int u = Q.front();
        Q.pop();
        if(u == b){
            cout << dp[b] << endl;
            vector<int> T;
            while(b != a){
                T.push_back(b);
                b = parent[b];
            }
            T.push_back(b);
            reverse(T.begin(),T.end());
            for(int u: T) cout << u << " ";
            return;
        }
        int x = 1ll * (u + 1) % n;
        if(dp[u] + 1 < dp[x]){
            dp[x] = dp[u] + 1;
            parent[x] = u;
            Q.push(x);
        }

        x = (1ll * u * u % n + 1) % n;
        if(dp[u] + 1 < dp[x]){
            dp[x] = dp[u] + 1;
            parent[x] = u;
            Q.push(x);
        }

        x = (1ll * u * u % n * u % n + 1) % n;
        if(dp[u] + 1 < dp[x]){
            dp[x] = dp[u] + 1;
            parent[x] = u;
            Q.push(x);
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


