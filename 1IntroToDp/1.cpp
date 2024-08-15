// Tiling corridor
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int mod = 1e9 + 7;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= mod;
    }
    cout << dp[n] << endl;
    return 0;
}