#include <bits/stdc++.h>

#define int int64_t
#define ll long long
#define ln "\n"

using namespace std;

int32_t main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int k;

    cin >> k;

    int n = -1;

    vector<int> vec;

    while (n != 0) {
        cin >> n;

        if (n == 0) {
            break;
        }

        vec.push_back(n);
    }

    int kol = 0;

    for (int i = 0; i < vec.size(); i++) {
        if ((vec[i] >> k) & 1) {
            kol++;
        }
    }
    cout << kol;
}
