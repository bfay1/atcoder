#include <bits/stdc++.h>
using namespace std;

int main()
{
        int n; cin >> n;
        vector<int> a(n);
        map<int, vector<int>> g;
        set<int> unvis;

        for (auto& x : a) {
                cin >> x;
                unvis.insert(x);
        }

        if (n == 1) return cout << "0\n", 0;

        int distinct = unvis.size();

        for (int l = 0, r = n - 1; l < r; l++, r--) {
                g[a[l]].push_back(a[r]);
                g[a[r]].push_back(a[l]);
        }

        auto connect = [&] (auto self, int u) -> void {
                if (unvis.find(u) == unvis.end()) return;
                unvis.erase(u);
                for (const auto& v : g[u])
                        self(self, v);
        };

        int components = 0;

        for (const auto& x : a) {
                if (unvis.find(x) != unvis.end()) {
                        connect(connect, x);
                        components++;
                }
        }

        cout << distinct - components << "\n";
}
