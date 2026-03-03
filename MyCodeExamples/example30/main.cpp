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

int conv_bit(string s)
{
    int x = stoi(s, nullptr, 2);

    return x;
}

int32_t main() {
    //freopen("ladder.in", "r", stdin);
    //freopen("ladder.out", "w", stdout);

    int n, m;

    cin >> n >> m;

    vector<int>v1, v2;

    for (int i = n; i; i = (i-1) & n)
    {
        v1.push_back(i);
    }

    for (int i = m; i; i = (i-1) & m)
    {
        v2.push_back(i);
    }

    set<int> se_mask1, se_mask2;

    for (auto i : v1)
    {
        cout << i << " ";

        se_mask1.insert(i);
    }

    cout << '\n';

    for (auto i : v2)
    {
        cout << i << " ";

        se_mask2.insert(i);
    }

    cout << '\n';

    vector<int> v;

    set_intersection(
        se_mask1.begin(), se_mask1.end(),
        se_mask2.begin(), se_mask2.end(),
        back_inserter(v)
    );

    sort(v.rbegin(), v.rend());

    for (auto i : v)
    {
        cout << i << " ";
    }
}
