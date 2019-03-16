#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rev(a) reverse(all(a))
#define int long long
#define forlr(l, r) for(int i = (int)l; i <= (int)r; i++)
#define forrl(l, r) for(int i = (int)r; i >= (int)l; i--)
#define pii pair<int, int>
#define ld long double
#define vii vector<pii >
#define F first
#define S second
#define sz size()

using namespace std;
const int inf = 1e18, mod = 1e9 + 7, N = 1e5;
int a[N];
bool used[N];
vector<int> g[N];

int dfs(int u)
{
    int ans = a[u];
    used[u] = 1;
    for(auto to : g[u])
    {
        if (used[to] == 0)
        {
            ans = min(ans, dfs(to));
        }
    }
    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if (used[i] == 0)
        {
            ans += dfs(i);
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}
