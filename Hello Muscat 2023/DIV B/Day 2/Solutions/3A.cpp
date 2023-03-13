#include<bits/stdc++.h>
#pragma GCC optimzie "Ofast"
#define prob "3A"
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

const int xorBase = 63;
ll basis[xorBase];
void insertVector(ll mask){
    for(int i=xorBase-1;i>=0;i--){
        if(mask >> i & 1){
            if(!basis[i]){
                basis[i] = mask;
                return;
            }
            mask ^= basis[i];
        }
    }
}
void solve(){
    int n;
    cin >> n;
    while(n--){
        ll x;
        cin >> x;
        insertVector(x);
    }
    ll res = 0;
    for(int i=xorBase-1;i>=0;i--){
        if(!basis[i]) continue;
        if(res >> i & 1) continue;
        res ^= basis[i];
    }
    cout << res << endl;
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


