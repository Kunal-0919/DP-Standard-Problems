// Wine Shelf iterative
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
    ll n;
    vl arr;
    cin >> n;
    arr.assign(n, 0);
    for (auto &x : arr)
    {
        cin >> x;
    }
    vvl dp(n, vl(n, 0));
    // dp[i][j] = maximum profit in the range i to j.
    for (ll i = 0; i < n; i++)
        dp[i][i] = n * arr[i];

    // base case = dp[i][i] = n * arr[i];
    // transition = dp[i][j] = max(dp[i + 1][j] + year * arr[i], dp[i][j - 1] + arr[j] * year)
    for (ll length = 2; length <= n; length++)
    {
        for (ll i = 0; i <= n - length; i++)
        {
            ll j = i + length - 1;
            ll year = n - (j - i);
            dp[i][j] = max(arr[i] * year + dp[i + 1][j], arr[j] * year + dp[i][j - 1]);
        }
    }

    cout << dp[0][n - 1] << endl;
}

int main()
{
    setIO();
    ll t = 1;

    while (t--)
    {
        solve();
    }
}
