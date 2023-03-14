#include<bits/stdc++.h>
#pragma GCC optimzie "Ofast"
#define prob "H"
#define ll long long
#define fi first
#define se second
using namespace std;
const int maxn = 5e5;
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
int n,m;

struct ed{ /// Neighbor vertice - Software version - Flip Edge (-1 = flip, 1 = not flip)
    int vertice,version,stateChange;
};
bool ccmp(ed A, ed B){
    if(A.version == B.version) return A.stateChange < B.stateChange;
    return A.version > B.version;
}

struct ii{ /// Vertice - Software Version - Num Changes
    int id,version,changes;
};
struct cmp{
    bool operator() (ii A, ii B){
        if(A.changes == B.changes) return A.version < B.version;
        return A.changes < B.changes;
    }
};
priority_queue<ii,vector<ii>,cmp> Heap;

vector<ed> Adj[maxn+5];
int dp[maxn+5],vis[maxn+5];
void dijkstra(int s){
    for(int i=1;i<=n;i++){
        dp[i] = INF;
        vis[i] = 0;
    }
    while(Heap.size()) Heap.pop();
    dp[s] = 0;
    vis[s] = 1;
    Heap.push({s,0,dp[s]});
    while(Heap.size()){
//        debug(Heap.size());
        ii u = Heap.top();
        Heap.pop();
        if(dp[u.id] < u.changes) continue;
//        vis[u.id] = 1;
//        debug(u.id);
//        debug(u.id,u.version,u.changes);
//        for(int i=1;i<=n;i++){
//            debug(dp[i]);
//        }
        for(ed v: Adj[u.id]){
            if(u.version >= v.version) continue;
//            if(vis[v.vertice]) continue;
//            debug(v.vertice, v.version, v.stateChange);
            int change = 0;
            if(v.stateChange == -1) change = 1;
            if(dp[u.id] + change < dp[v.vertice]){
                dp[v.vertice] = dp[u.id] + change;
                Heap.push({v.vertice,v.version,dp[v.vertice]});
            }
        }
//        cerr << endl << endl;
    }
}
void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        dp[i] = 0;
        vis[i] = 0;
        Adj[i].clear();
    }
    for(int i=1;i<=m;i++){
        int u,v,t;
        cin >> u >> v >> t;
        Adj[u].push_back({v,t,1});
        Adj[v].push_back({u,t,-1});
    }
    for(int i=1;i<=n;i++){
        sort(Adj[i].begin(),Adj[i].end(),ccmp);
//        debug(i);
//        for(ed u: Adj[i]){
//            debug(u.vertice, u.version, u.stateChange);
//        }
    }
    dijkstra(1);
    if(dp[n] == INF) dp[n] = -1;
    cout << dp[n] << endl;
}
int main(){
    if(fopen(prob".inp","r")){
        freopen(prob".inp","r",stdin);
        freopen(prob".out","w",stdout);
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tc = 1;
    cin >> tc;
    while(tc--) solve();
}


