#include <bits/stdc++.h>

#define int int64_t
#define ll long long
#define ln "\n"

using namespace std;

bool next_permutation(int *A, int n) {
    int i, j;

    for (i = n - 1; (i > 0) && (A[i - 1] > A[i]); i--);

    if (i) {
        for (j = n - 1; (j >= i) && (A[j] < A[i - 1]); j--);
            swap(A[i - 1], A[j]);

        for (; i + 1 < n; i++, n--)
            swap(A[i], A[n - 1]);

        return true;
  }

    return false;
}

int32_t main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;

    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int k;

    cin >> k;

    while (k--) {
        next_permutation(a, n);

        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << '\n';
    }
}
