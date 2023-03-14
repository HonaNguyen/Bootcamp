#include<bits/stdc++.h>
#pragma GCC optimzie "Ofast"
#define prob "H"
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

int n, m, okay=1;
int vis[maxn+5], ans[maxn+5];
vector<int> Adj[maxn+5];
stack<int> topo;
void DFS(int u) {
    vis[u] = 1;
    for (int v: Adj[u]) {
        if (vis[v] == 1) {
            cout << "NO";
            exit(0);
        }
        if(!vis[v]) DFS(v);
    }
    topo.push(u);
    vis[u] = 2;
}
void solve(){
    cin >> n >> m;

    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        Adj[u].push_back(v);
    }

    for(int i=0;i<n;i++){
        if(!vis[i]) DFS(i);
    }
    int cnt = 0;
    vector<int> T;
    while(!topo.empty()) {
        T.push_back(topo.top());
        ans[topo.top()] = ++cnt;
        topo.pop();
    }

    cout << "YES" << endl;
    for(int i=0;i<n;++i) cout << T[i] << ' ';
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
