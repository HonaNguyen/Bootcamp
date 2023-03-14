#include<bits/stdc++.h>
#pragma GCC optimzie "Ofast"
#define prob "G"
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

int n,m,s,t;
int vis[maxn+5];
ll dp[maxn+5],w[maxn+5];
vector<pi> Adj[maxn+5];

struct ii{
    int id;
    ll w;
};

struct cmp{
    bool operator () (ii A, ii B){
        return A.w > B.w;
    }
};

priority_queue<ii,vector<ii>,cmp> Heap;

void dijkstra(int s){
    for(int i=1;i<=n;i++){
        vis[i] = 0;
        dp[i] = 1e18;
    }
    while(Heap.size()) Heap.pop();

    dp[s] = w[s];
    vis[s] = 1;
    Heap.push({s,dp[s]});
    while(Heap.size()){
        ii u = Heap.top();
        Heap.pop();
        if(dp[u.id] < u.w) continue;
        vis[u.id] = 1;
        for(pi v: Adj[u.id]){
            if(vis[v.fi]) continue;
            if(dp[u.id] + w[v.fi] < dp[v.fi]){
                dp[v.fi] = dp[u.id] + w[v.fi];
                Heap.push({v.fi,dp[v.fi]});
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> w[i];
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        Adj[u].push_back({v,0});
        Adj[v].push_back({u,0});
    }

    dijkstra(1);

    for(int i=1;i<=n;i++) cout << dp[i] << " ";
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


