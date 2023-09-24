#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	string s;
	cin >> s;

	int n = s.size(), ans = 1;

	auto f = [&] (int l, int r) {
		int ret = 1;
		while (0 <= l && r < n) {
			if (s[l] != s[r])
				break;
			else
				l--, r++, ret += 2;
		}
		return ret;
	};

	auto g = [&] (int l, int r) {
		int ret = 0;
		while (0 <= l && r < n) {
			if (s[l] != s[r])
				break;
			else
				l--, r++, ret += 2;
		}
		return ret;
	};

	for (int i = 0; i < n; i++) {
		if (i < n - 1) {
			ans = max(ans, g(i, i + 1));
		}

		if (0 < i && i < n - 1) {
			ans = max(ans, f(i - 1, i + 1));
		}
	}

	cout << min(ans, n);
}
