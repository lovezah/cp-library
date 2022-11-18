#include <bits/stdc++.h>

std::vector<int> get_z(std::string s) {
    int n = int(s.size());
	std::vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
<<<<<<< HEAD
        if (i <= r) z[i] = std::min(r - i + 1, z[i - l]);
=======
        if (i <= r) z[i] = std::min(r - i + 1, z[i-l]);
>>>>>>> 8c0386a3d31850710e0c1cf0ad4bc5c2498fef7f
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i] += 1;
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

