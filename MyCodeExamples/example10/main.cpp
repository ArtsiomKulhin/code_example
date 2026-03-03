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
    stack<int> st;
    queue<int> qu;
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        if (s == "ARRIVE") {
            int x;
            cin >> x;
            qu.push(x);
        }
        else if (s == "PROCESS") {
            if (st.empty() && qu.empty()) {
                cout << "IDLE" << '\n';
            }
            else if (!st.empty()) {
                cout << st.top() << '\n';
                st.pop();
            }
            else if (st.empty() && !qu.empty()) {
                cout << qu.front() << '\n';
                qu.pop();
            }
        }
        else if (s == "DEFER") {
            if (!qu.empty()) {
                st.push(qu.front());
                qu.pop();
            }
        }
    }
}
