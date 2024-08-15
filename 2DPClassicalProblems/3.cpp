#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define MP make_pair
#define rep(i, a, n) for (ll i = a; i <= n; i++)
#define sq(a) (a) * (a)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define endl '\n'
#define f first
#define s second
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<vector<ll>> vvl;
typedef vector<vector<bool>> vvb;
typedef set<ll> si;
typedef set<ll> sl;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef priority_queue<ll> maxHeap;
typedef priority_queue<ll, vl, greater<ll>> minHeap;
typedef map<ll, ll> mii;
typedef map<string, ll> msi;

void setIO(string name = "")
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    // if (sz(name))
    // {
    // freopen((name + ".in").c_str(), "r", stdin);
    // freopen((name + ".out").c_str(), "w", stdout);
    // }
}

const lld pi = 3.14159265358979323846;
ll mod = 1e9 + 7;

void solve()
{
    ll n, k;
    vl arr;
    cin >> n >> k;
    arr.assign(n, 0);
    for (auto &x : arr)
    {
        cin >> x;
    }

    vvl dp(n, vl(k + 1, 0));
    for (ll i = 0; i < n; i++)
        dp[i][0] = 1;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 1; j <= k; j++)
        {
            if (i > 0)
                dp[i][j] = dp[i - 1][j];
            if (j >= arr[i])
            {
                if (i > 0)
                    dp[i][j] += dp[i - 1][j - arr[i]];
                else
                    dp[i][j] += (j == arr[i]);
            }
        }
    }
    cout << dp[n - 1][k] << endl;
}

int main()
{
    setIO();
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
};
