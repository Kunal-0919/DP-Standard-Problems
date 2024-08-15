#include <bits/stdc++.h>
using namespace std;

#define range(x) begin(x), end(x)
typedef long long ll;
typedef vector<ll> vl;

void setIO(string name = "")
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
}

ll mod = 1e9 + 7;
ll n;
vl arr;
vector<vl> dp;
bool f(ll i, ll k)
{
    if (k == 0)
        return 1;
    if (k < 0 || i == n)
        return 0;
    if (dp[i][k] != -1)
        return dp[i][k];
    return dp[i][k] = f(i + 1, k) | f(i + 1, k - arr[i]);
}
void solve()
{
    cin >> n;
    arr.assign(n, 0);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    ll total = accumulate(range(arr), 0);
    dp.assign(n, vl(total, -1));
    if (total & 1)
        cout << "NO" << endl;
    else if (f(0, total / 2))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    setIO();
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
