#include<bits/stdc++.h>
#pragma GCC optimzie "Ofast"
#define prob "J"
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
int parent[maxn+5],isBridges[maxn+5];
int articulation[maxn+5];
int Rank[maxn+5],Troot[maxn+5];
vector<int> Cuts;
vector<int> Bridges;
vector<pi> Edges;
vector<pi> Adj[maxn+5];
map<pi,int> Map;
int Find(int u){
    if(Troot[u] != u) Troot[u] = Find(Troot[u]);
    return Troot[u];
}
void Union(int u,int v){
    u = Find(u);
    v = Find(v);
    if(u == v) return;
    if(Rank[u] < Rank[v]){
        Rank[v] += Rank[u];
        Troot[u] = v;
    }
    else{
        Rank[u] += Rank[v];
        Troot[v] = u;
    }
}
void DFS(int u){
    low[u] = num[u] = ++num_vis;
    for(pi v : Adj[u]){
        if(!num[v.fi]){
            if(Root == u) child++;
            parent[v.fi] = u;
            DFS(v.fi);
            low[u] = min(low[u],low[v.fi]);
            if(low[v.fi] >= num[u]) articulation[u] = 1;
            if(low[v.fi] > num[u]){
                Bridges.push_back(v.se);
                isBridges[v.se] = 1;
                Map[{u,v.fi}] = 1;
                Map[{v.fi,u}] = 1;
            }
        }
        else if(parent[u] != v.fi){
            low[u] = min(low[u],num[v.fi]);
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) Troot[i] = i, Rank[i] = 1;
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        Union(u,v);
        Edges.push_back(make_pair(u,v));
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

    vector<vector<pi>> Components(n+1);
    vector<pi> ANS;
    for(pi u: Edges) Components[Find(u.fi)].push_back(u);
    for(int i=1;i<=n;i++){
        if(Rank[i] <= 1) continue;
        int tmp = Components[i].size() - (Rank[i] - 1);
        for(pi v: Components[i]){
            if(Map[v]) continue;
            ANS.push_back(v);
            tmp--;
            if(tmp == 0) break;
        }
    }
    vector<int> T;
    for(int i=1;i<=n;i++) if(Rank[i] > 1 && Find(i) == i) T.push_back(i);
    for(int i=0;i<T.size()-1;i++) ANS.push_back(make_pair(T[i],T[i+1]));
    cout << ANS.size() << endl;
    for(pi u: ANS) cout << u.fi << " " << u.se << endl;
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



