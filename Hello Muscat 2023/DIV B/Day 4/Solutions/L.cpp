#include<bits/stdc++.h>
#pragma GCC optimzie "Ofast"
#define prob "L"
#define ll long long
#define fi first
#define se second
using namespace std;
const int maxn = 2e5;
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

int n,m,Root,child,num_vis;
int low[maxn+5],num[maxn+5];
int parent[maxn+5];
int articulation[maxn+5];
vector<int> Cuts;
vector<int> Bridges;
vector<pi> Adj[maxn+5];
void DFS(int u){
    low[u] = num[u] = ++num_vis;
    for(pi v : Adj[u]){
        if(!num[v.fi]){
            if(Root == u) child++;
            parent[v.fi] = u;
            DFS(v.fi);
            low[u] = min(low[u],low[v.fi]);
            if(low[v.fi] >= num[u]) articulation[u] = 1;
            if(low[v.fi] > num[u]) Bridges.push_back(v.se);
        }
        else if(parent[u] != v.fi){
            low[u] = min(low[u],num[v.fi]);
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        Adj[u].push_back(make_pair(v,i));
        Adj[v].push_back(make_pair(u,i));
    }
    for(int i=1;i<=n;i++){
       if(!num[i]){
          Root = i;
          child = 0;
          DFS(i);
          if(child < 2) articulation[i] = 0;
       }
    }
    for(int i=1;i<=n;i++) if(articulation[i]) Cuts.push_back(i);
    cout << Cuts.size() << endl;
    for(int u: Cuts) cout << u << " ";
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



