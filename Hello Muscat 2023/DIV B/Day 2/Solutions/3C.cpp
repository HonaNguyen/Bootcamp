#include<bits/stdc++.h>
#pragma GCC optimzie "Ofast"
#define prob "3C"
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
void solve(){
    int n,q;
    cin >> n >> q;
    vector<int> setXor;
    vector<bool> vis(1<<20);
    vector<int> a(n);
    vector<vector<pi>> queries(n);
    vector<int> ans(q);
    int res = 1;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<q;i++){
        int L, X;
        cin >> L >> X;
        queries[L-1].push_back({X,i});
    }
//    debug(queries);
    setXor.push_back(0);
    vis[0] = 1;
    for(int i=0;i<n;i++){
        /// If a[i] belongs to the set
        if(vis[a[i]]){
            res = 1ll * res * 2 % MOD;
        }
        /// If a[i] not belong to the set -> add to the set
        else{
            int tmp = (int)(setXor.size());
            for(int j=0;j<tmp;j++){
                int u = setXor[j];
                setXor.push_back(u^a[i]);
                vis[setXor.back()] = 1;
            }
        }
//        debug(i,res,setXor);
        for(pi u: queries[i]) ans[u.se] = res * vis[u.fi];
    }
    for(int i=0;i<q;i++) cout << ans[i] << endl;
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


