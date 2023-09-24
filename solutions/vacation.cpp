#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
 
signed main()
{
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(3));

    auto f = [] (int x) {
	vector<int> p;
	for (int i = 0; i < 3; i++) {
	    if (i != x) {
		p.push_back(i);
	    }
	}
	return make_pair(p[0], p[1]);
    };

    for (int i = 1; i <= n; i++) {
	for (int j = 0; j < 3; j++) {
	    int x;
	    cin >> x;
	    auto [a, b] = f(j);
	    dp[i][j] = max(dp[i - 1][a] + x, dp[i - 1][b] + x);
	}
    }

    cout << *max_element(dp.back().begin(), dp.back().end()) << "\n";
}
