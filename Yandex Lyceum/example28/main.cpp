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

    string n;

    cin >> n;

    int a = conv_bit(n);
    int r1 = a;

    string s1 = "";

    while (r1 != 0)
    {
        s1 += to_string(r1%2);
        r1 /= 2;
    }

    int sz = s1.size();

    vector<string>v;

    for (int i = a; i; i = (i-1) & a)
    {
        v.push_back(bit(i));
    }
    for (auto i : v)
    {
        while (i.size() < sz)
        {
            i = '0' + i;
        }
        cout << i << '\n';
    }
}
