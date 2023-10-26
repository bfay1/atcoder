
#define watch(x) cerr << #x << " is: " << x << "\n"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	int ans = 0;
	vector<vector<int>> g(N);

	for (int i = 0, x, y; i < M; i++) {
		cin >> x >> y;
		g[--x].push_back(--y);
	}

	for (int i = 0; i < N; i++) {
		vector<int> vis(N), q {i}, nq; vis[i] = true;

		for (; q.size(); swap(q, nq), nq.clear()) for (const auto& x : q) for (const auto& y : g[x]) if (!vis[y]) {
			vis[y] = true;
			nq.push_back(y);
			ans++;
		}
	}

	cout << ans - M;
}
