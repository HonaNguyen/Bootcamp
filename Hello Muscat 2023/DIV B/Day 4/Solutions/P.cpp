#include<bits/stdc++.h>
#pragma GCC optimzie "Ofast"
#define prob "P"
#define ll long long
#define fi first
#define se second
using namespace std;
const int maxn = 1e5;
const int INF = 1e9;
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

int n,m,Count,res;
int num[maxn+5],low[maxn+5],ans[maxn+5];
vector<int> Adj[maxn+5];
vector<pi> Edges;
stack<int> St;
void DFS(int u){
    low[u] = num[u] = ++Count;
    St.push(u);
    for(int v: Adj[u]){
        if(!num[v]){
            DFS(v);
            low[u] = min(low[u],low[v]);
        }
        else{
            low[u] = min(low[u],num[v]);
        }
    }
    if(low[u] == num[u]){
        while(true){
            int v = St.top();
            St.pop();
            ans[v] = res+1;
            low[v] = num[v] = INF;
            if(u == v) break;
        }
        res++;
    }
}
void solve(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        Edges.push_back(make_pair(u,v));
        Adj[u].push_back(v);
    }
    res = 0;
    for(int i=1;i<=n;i++){
        if(!num[i]){
            DFS(i);
        }
    }
    cout << res << endl;
//    for(pi u: Edges){
//        if(ans[u.fi] > ans[u.se]) swap(ans[u.fi],ans[u.se]);
//    }
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
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


