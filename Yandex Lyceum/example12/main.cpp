#include<bits/stdc++.h>
#define ll long long
#define int int64_t
#define fi first
#define se second
using namespace std;
int32_t main()
{
    //freopen("explore.in", "r", stdin);
    //freopen("explore.out", "w", stdout);
    int n,k;
    cin >> n >> k;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        int id, t;
        cin >> id >> t;
        q.push({id,t});
    }
    vector<int> v;
    while (!q.empty()) {
        auto [id, t] = q.front();
        q.pop();
        if (t <= k) {
            v.push_back(id);
        }
        else {
            q.push({id, t - k});
        }
    }
    for (auto i : v) {
        cout << i << " ";
    }
}
