#include<bits/stdc++.h>
#pragma GCC optimzie "Ofast"
#define prob "G"
#define ll long long
#define fi first
#define se second
using namespace std;
const int maxn = 500;
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
int n,m;
int vis[maxn+5][maxn+5];
string s[maxn+5];
void solve(){
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> s[i];
    vector<int> components;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j] == '*') continue;
            if(vis[i][j]) continue;
            int cnt = 0;
            queue<pi> Q;
            vis[i][j] = 1;
            Q.push({i,j});
            while(Q.size()){
                pi u = Q.front();
//                debug(u);
                Q.pop();
                cnt++;
                for(int i=0;i<4;i++){
                    int x = u.fi + dx[i];
                    int y = u.se + dy[i];
                    if(0 <= x && x <= n-1 && 0 <= y && y <= m-1){
                        if(vis[x][y]) continue;
                        if(s[x][y] == '*') continue;
                        vis[x][y] = 1;
                        Q.push({x,y});
                    }
                }
            }
            components.push_back(cnt);
        }
    }
    sort(components.begin(),components.end());
    cout << components.size() << endl;
    for(int u: components) cout << u << " ";
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


