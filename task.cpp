#include <bits/stdc++.h>

int main()
{
	int n, q, parity = -1;
	std::unordered_map<char, char> mapping(26);
	std::unordered_set<int> immune;
	std::string s;

	std::cin >> n >> s >> q;

	while (q--) {
		int t, x;
		char c;
		std::cin >> t >> x >> c;
		if (t == 1) {
			mapping[s[x]] = c;
		} else {
			parity = t;
		}
	}

	if (parity == 2) {
		for (int i = 0; i < n; i++) {
			char x = s[i];
			if (mapping.find(x) != mapping.end()) {
				char y = immune.find(i) == immune.end() ? std::tolower(mapping[x]) : mapping[x];
				std::cout << (char) y;
			} else {
				std::cout << (char) std::tolower(x);
			}
		}
	} else if (parity == 3) {
		for (int i = 0; i < n; i++) {
			if (mapping.find(x) != mapping.end())
				std::cout << (char) std::toupper(mapping[x]);
			else
				std::cout << (char) std::toupper(x);
		}
	} else {
		for (int i = 0; i < n; i++) {
			if (mapping.find(x) != mapping.end())
				std::cout << (char) mapping[x];
			else
				std::cout << (char) x;
		}
	}
}
