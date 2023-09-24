#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
 
signed main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), dp(n, LLONG_MAX);

    for (auto& x : a) {
	cin >> x;
    }

    dp[0] = 0;
    dp[1] = abs(a[1] - a[0]);

    for (int i = 2; i < n; i++) {
	for (int j = 1; j <= min(i, k); j++) {
	    dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j]));
	}
    }

    cout << dp.back() << "\n";
}
