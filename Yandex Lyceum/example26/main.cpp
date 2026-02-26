#include <bits/stdc++.h>

#define int int64_t
#define ll long long
#define ln "\n"

using namespace std;

int fact(int n) {
    if (n < 0) {
        return 0;
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * fact(n - 1);
}

int32_t main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;

    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    int new_n = fact(n);

    while (new_n--) {
        next_permutation(a, a + n);

        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << '\n';
    }
}
