#include<bits/stdc++.h>
#pragma GCC optimzie "Ofast"
#define prob "1A"
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
int n;
double x[maxn+5];
double a[maxn+5][maxn+5];
void gauss(){
    /// Transfer to Gaussian Reduced Echelon Form
    for(int i=0;i<n;i++){
        /// swap row
        if(a[i][i] == 0){
            int i2 = -1;
            for(int row=i+1;row<n;row++){
                if(a[row][i] != 0){
                    i2 = row;
                    break;
                }
            }
            /// if founded the swap
            for(int j=0;j<=n;j++) swap(a[i][j],a[i2][j]);
        }

        double tmp = a[i][i];
        for(int j=0;j<=n;j++) a[i][j] /= tmp;

        for(int i1=0;i1<n;i1++){
            if(i1 == i) continue;
            if(a[i1][i] == 0) continue;
            double coef = a[i1][i];
            for(int j=i;j<=n;j++){
                a[i1][j] = a[i1][j] - coef * a[i][j];
            }
        }
    }

//    for(int i=n-1;i>=0;i--){
//        double sum = a[i][n];
//        for(int j=i+1;j<n;j++){
//            sum -= x[j] * a[i][j];
//        }
//        x[i] = sum / a[i][i];
//    }

    for(int i=0;i<n;i++) x[i] = a[i][n];
}
void solve(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++) cin >> a[i][j];
    }
    gauss();
    for(int i=0;i<n;i++) cout << x[i] << endl;
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


