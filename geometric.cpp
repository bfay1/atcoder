#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long A, X, M, ans = 0; cin >> A >> X >> M;

	auto bp = [&] (long long a, long long i) {
		long long ret = 1;
		while (i) {
			if (i & 1)
				ret *= a;
			ret %= M;
			a *= a;
			ret %= M;
			i >>= 1;
		}
		return ret;
	};

	for (long long i = 0; i < X; i++, ans %= M)
		ans += bp(A, i);

	cout << ans << "\n";

	return 0;
}
