#include<bits/stdc++.h>

#define ll long long
#define int int64_t
#define fi first
#define se second

using namespace std;

string bit(int n)
{
    string s = "";

    while (n != 0)
    {
        s += to_string(n%2);
        n /= 2;
    }

    reverse(s.begin(), s.end());

    return s;
}

int32_t main() {
    //freopen("ladder.in", "r", stdin);
    //freopen("ladder.out", "w", stdout);

    int n;

    cin >> n;

    int a = n;
    int r1 = n;

    string s1 = "";

    while (r1 != 0)
    {
        s1 += to_string(r1%2);
        r1 /= 2;
    }

    int sz = s1.size();

    vector<pair<int, string>> v;

    for (int i = n; i; i = (i-1) & n)
    {
        v.push_back(make_pair(i, bit(i)));
    }

    for (auto [i, j] : v)
    {
        while (j.size() < sz)
        {
            j = '0' + j;
        }

        cout << i << " " << j << '\n';
    }
}
