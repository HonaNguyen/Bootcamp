#include<bits/stdc++.h>
#pragma GCC optimzie "Ofast"
#define prob "I"
#define ll long long
#define fi first
#define se second
using namespace std;
const int maxn = 100;
const int MOD = 1e9 + 7;
const int INF = 1e9;
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
struct edge{
    int u,v,w;
};
int n;
int trace[maxn+5],dp[maxn+5];
int a[maxn+5][maxn+5];
void solve(){
    cin >> n;
    vector<edge> edges;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
            if(a[i][j] != 100000){
                edges.push_back({i,j,a[i][j]});
            }
        }
    }


    for(int i=1;i<=n;i++){
        dp[i] = INF;
        trace[i] = -1;
    }

    int negStart = -1;
    for(int i=0;i<n;i++){
        negStart = -1;
        for(edge e: edges){
            if(dp[e.u] + e.w < dp[e.v]){
                dp[e.v] = max(-INF, dp[e.u] + e.w);
                trace[e.v] = e.u;
                negStart = e.v;
            }
        }
    }

    if(negStart == -1){
        cout << "NO";
        return;
    }

    int u = negStart;
    for(int i=1;i<=n;i++) u = trace[u];

    vector<int> negCycle(1,u);
    for(int v=trace[u]; v!= u; v=trace[v]){
        negCycle.push_back(v);
    }
    reverse(negCycle.begin(),negCycle.end());
    cout << "YES" << endl;
    cout << negCycle.size() << endl;
    for(int u: negCycle) cout << u << " ";
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


