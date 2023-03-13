#include<bits/stdc++.h>
#pragma GCC optimzie "Ofast"
#define prob "2E"
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
    int n,x;
    cin >> n >> x;
    vector<int> ans;
    for(int i=1;i<=n-3;i++) ans.push_back(i);
    if(n == 1){
        cout << "YES" << endl;
        cout << x;
        return;
    }
    if(n == 2){
        if(x == 0){
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        cout << 0 << " " << x;
        return;
    }
    int XOR = 0;
    for(int i=1;i<=n-3;i++) XOR ^= i;
    if(XOR == x){
        ans.push_back(1<<17);
        ans.push_back(1<<18);
        ans.push_back((1<<17)^(1<<18));
    }
    else{
        ans.push_back(0);
        ans.push_back(XOR^(1<<17));
        ans.push_back((1<<17)^x);
    }
    cout << "YES" << endl;
    for(int u: ans) cout << u << " ";

//    int cur = 0;
//    for(int u: ans) cur ^= u;
//    cout << cur << endl;
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


