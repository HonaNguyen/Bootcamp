#include<bits/stdc++.h>
#pragma GCC optimzie "Ofast"
#define prob "M"
#define ll long long
#define fi first
#define se second
using namespace std;
const int maxn = 3e5;
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

int n,m,cnt=1;
int tin[maxn+5],tout[maxn+5];
vector<int> Adj[maxn+5];
void DFS(int u,int p){
    tin[u] = cnt++;
    for(int v: Adj[u]){
        if(v == p) continue;
        DFS(v,u);
    }
    tout[u] = cnt++;
}
void solve(){
    cin >> n;
    for(int i=2;i<=n;i++){
        int x;
        cin >> x;
        Adj[i].push_back(x);
        Adj[x].push_back(i);
    }
    DFS(1,1);
    cin >> m;
    while(m--){
        int u,v;
        cin >> u >> v;
        if(tin[u] < tin[v] && tout[v] < tout[u]) cout << 1 << endl;
        else if(tin[v] < tin[u] && tout[u] < tout[v]) cout << 2 << endl;
        else cout << 3 << endl;
    }
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

