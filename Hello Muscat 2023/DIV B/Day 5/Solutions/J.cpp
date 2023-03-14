#include<bits/stdc++.h>
#pragma GCC optimzie "Ofast"
#define prob "J"
#define ll long long
#define fi first
#define se second
using namespace std;
const int maxn = 500;
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

struct ed{ /// Neighbor vertice - Time - Max Weight
    int vertice,time,weight;
};


struct ii{ /// Vertice - Total Time - Total Weight - Total cup
    int id,time;
};
struct cmp{
    bool operator() (ii A, ii B){
        return A.time > B.time;
    }
};
priority_queue<ii,vector<ii>,cmp> Heap;

vector<ed> Adj[maxn+5];
int dp[maxn+5],vis[maxn+5];
int dijkstra(int val){
    for(int i=1;i<=n;i++){
        dp[i] = INF;
        vis[i] = 0;
    }
    while(Heap.size()) Heap.pop();
    dp[1] = 0;
    int weight = 3000000 + 100 * val;
    Heap.push({1,dp[1]});
    while(Heap.size()){
        ii u = Heap.top();
        Heap.pop();
        if(dp[u.id] < u.time) continue;
        vis[u.id] = 1;
        for(ed v: Adj[u.id]){
            if(weight > v.weight) continue;
            if(u.time + v.time > 1440) continue;
            if(vis[v.vertice]) continue;
            if(dp[u.id] + v.time < dp[v.vertice]){
                dp[v.vertice] = dp[u.id] + v.time;
                Heap.push({v.vertice,dp[v.vertice]});
            }
        }
    }
    if(dp[n] != INF && dp[n] <= 1440) return 1;
    return 0;
}
void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        dp[i] = 0;
        vis[i] = 0;
        Adj[i].clear();
    }
    for(int i=1;i<=m;i++){
        int u,v,t,w;
        cin >> u >> v >> t >> w;
        Adj[u].push_back({v,t,w});
        Adj[v].push_back({u,t,w});
    }

    int L = 0, R = 1e7, res = 0;
    while(L <= R){
        int mid = (L + R) >> 1;
        if(dijkstra(mid)){
            res = mid;
            L = mid + 1;
        }
        else{
            R = mid - 1;
        }
    }
    cout << res;
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



