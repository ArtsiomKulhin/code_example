#include <bits/stdc++.h>

#define int int64_t
#define F first
#define S second

using namespace std;

const int MAX = 2e6;
int n, q, a[MAX], tr[MAX], pos, no, ko, val;

void MT(int v, int l ,int r) {
    if(l == r) {
        tr[v] = a[l];
        return;
    }

    int m = (l + r) / 2;

    MT(v * 2, l, m);
    MT(v * 2 + 1, m + 1, r);

    tr[v] = tr[v * 2] + tr[v * 2 + 1];
}

void UPD(int v, int l, int r) {
    if((pos < l) || (r < pos)) {
        return ;
    }

    if(l == r) {
        a[l] = val;

        tr[v] = a[l];

        return ;
    }

    int m = (l + r) / 2;

    UPD(v * 2, l, m);
    UPD(v * 2 + 1, m + 1, r);

    tr[v] = tr[v * 2] + tr[v * 2 + 1];
}

int TA(int v, int l, int r) {
    if((l > ko) || (r < no)) {
        return 0;
    }

    if((no <= l) && (r <= ko)) {
        return tr[v];
    }

    int m = (l + r) / 2;

    return TA(v * 2, l, m) + TA(v * 2 + 1, m + 1, r);
}

int32_t main(){
    //freopen("K.in","r",stdin);
    //freopen("K.out","w",stdout);

    char t ;

    cin >> n >> q;

    for(int i = 0 ; i < n ; ++i) {
        cin >> a[i] ;
    }

    MT(1, 0, n - 1);

    for(int j = 0 ; j < q ; ++j) {
        cin >> t;

        if(t == '=') {
            cin >> pos >> val;

            --pos ;

            UPD(1, 0, n - 1);
        }
        else {
            cin >> no >> ko;

            --no; --ko;

            cout << TA(1, 0, n - 1) << '\n';
        }
    }
}
