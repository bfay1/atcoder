#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	auto bp = [&] (int a, int b) {
		int ret = 1;
		while (b != 0) {
			if (b % 2 != 0)
				ret *= a;
			a *= a;
			b /= 2;
		}
		return ret;
	};

	int A, B;
	cin >> A >> B;

	cout << bp(A, B) + bp(B, A) << "\n";
}
