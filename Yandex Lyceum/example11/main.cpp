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
    int q;
    cin >> q;
    string str;
    stack<char> st;
    bool f = false;
    while (q--) {
        string s;
        cin >> s;
        if (s == "TYPE") {
            char ch;
            cin >> ch;
            str.push_back(ch);
            if (f) {
                while (!st.empty()) {
                    st.pop();
                }
            }
            f = false;
        }
        else if (s == "UNDO") {
            if (!str.empty()) {
                st.push(str.back());
                str.pop_back();
                f = true;
            }
        }
        else if (s == "REDO") {
            if (f && !st.empty()) {
                str.push_back(st.top());
                st.pop();
            }
        }
    }
    cout << str;
}
