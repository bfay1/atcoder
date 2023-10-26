#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> p(n), count(n);
	for (auto& x : p) cin >> x;

	for (int i = 0; i < n; i++) {
		for (int j = -1; j <= 1; j++) {
			count[(p[i] - i + j + n) % n]++;
		}
	}

	cout << *max_element(count.begin(), count.end()) << "\n";
}
