#include <bits/stdc++.h>
using namespace std;


long long gcd(long long a, long long b) {
        if (b == 0)
                return a;
        return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
        return (a * b) / gcd(a, b);
}

int main()
{
        long long n; cin >> n;
        vector<long long> a(n), pr;
        for (auto& x : a)
                cin >> x;

        const long long maxn = *max_element(a.begin(), a.end());

        vector<long long> lp(maxn + 1);
        set<long long> seen;
        bool pairwise = (long long) set(a.begin(), a.end()).size() == n - count(a.begin(), a.end(), 1LL) + 1;

        auto pf = [&] (auto self, long long x) -> void {
                if (x == lp[x])
                        return;

                pairwise &= (x == 1 || lp[x] == 1 || seen.insert(lp[x]).second);
                self(self, lp[x]);
        };

        for (int i = 2; i <= maxn; i++) {
                if (lp[i] == 0) {
                        lp[i] = i;
                        pr.push_back(i);
                }
                for (int j = 0; i * pr[j] <= maxn; j++) {
                        lp[i * pr[j]] = pr[j];
                        if (pr[j] == lp[i])
                                break;
                }
        }

        long long g = 0;

        for (const auto& x : a) {
                pf(pf, x);
                g = gcd(g, x);
        }

        if (pairwise)
                cout << "pairwise coprime";
        else if (g == 1)
                cout << "setwise coprime";
        else
                cout << "not coprime";
}
