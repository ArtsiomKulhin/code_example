#include<bits/stdc++.h>

#define ll long long
//#define int int64_t
#define fi first
#define se second
#define pb push_back
#define mpi make_pair
#define nl '\n'

const double pi = 3.14159;
const int INF = 1e9;

using namespace std;

int main() {
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  setlocale(LC_ALL,"russian");

  int n;

  cin >> n;

  ll** a = new ll *[n];

  for (int i = 0; i < n; ++i) {
    a[i] = new ll[n];
    for (int j = 0; j < n; ++j) {
        cin >> a[i][j];
    }
  }

  bool* f = new bool[n];

  for (int i = 0; i < n; ++i) {
    f[i] = false;
  }

  f[0] = true;

  int x = 0, y = 0, mn = 1e9, k = 0, s = 0;

  while (k < n-1) {
    x = -1;
    y = -1;
    mn = 1e9;
    for (int i = 0; i < n; ++i) {
        if (!f[i]) {
            continue;
        }

        for (int j = 0; j < n; ++j) {
            if (!f[j] && a[i][j] > 0 && a[i][j] < mn) {
                mn = a[i][j];
                x = i;
                y = j;
            }
        }
    }

  if (mn == INF) {
    cout << -1;

    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }

    delete[] a;
    delete[] f;

    return 0;
  }

  s += mn;

  f[y] = true;

  ++k;
  }

  cout << s;

  for (int i = 0; i < n; ++i) {
    delete[] a[i];
  }

  delete[] a;
  delete[] f;
}
