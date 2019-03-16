//In The Name Of God
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<double, double> dd;
typedef pair<dd, double> ddd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<dd> vdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;
typedef vector<vector<viii> > vvviii;
typedef vector<vector<iii> > vviii;
typedef set<int> si;
typedef vector<si> vsi;

#define forn(i, n) for (ll i = 0; i < n; i++)
#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0)
#define F first
#define S second

const ll MOD = 998244353;
const ll N = 1010;
ll dp[2][N][2 * N];
int n, kk;

ll solve(ll s, ll i, ll k) {
    if(i == n) {
        if(k == kk) return 1;
        else return 0;
    }
    ll &cur = dp[s][i][k];
    if(cur != -1) return cur;
    cur = 0;
    if(s == 0) { // same
        cur = (solve(0, i + 1, k + 1) + solve(0, i + 1, k)) % MOD;
        cur = (cur + (2 * solve(1, i + 1, k + 1)) % MOD) % MOD;

    } else { // diff
        cur = (solve(1, i + 1, k) + solve(1, i + 1, k + 2)) % MOD;
        cur = (cur + (2 * solve(0, i + 1, k)) % MOD) % MOD;
    }
    return cur;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> kk;
    forn(i, N) forn(j, 2 * N) {
            dp[0][i][j] = dp[1][i][j] = -1;
        }
    cout << ((2 * solve(0, 1, 1)) % MOD + (2 * solve(1, 1, 2)) % MOD) % MOD << endl;

    return 0;
}