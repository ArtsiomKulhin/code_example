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

  int** a = new int *[n];

  for (int i = 0; i < n; ++i) {
        a[i] = new int[n];

    for (int j = 0; j < n; ++j) {
        cin >> a[i][j];
    }
  }
  ll** d = new ll *[n];
  for (int i = 0; i < n; ++i) {
    d[i] = new ll [n];
    for (int j = 0; j < n; ++j) {
      if (i == j) {
        d[i][j] = 0;
      }
      else if (a[i][j] != 0) {
        d[i][j] = a[i][j];
      }
      else {
        d[i][j] = INF;
      }
    }
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
            if (d[i][k] == INF) {
                continue;
            }

        for (int j = 0; j < n; ++j) {
            if (d[k][j] == INF) {
                continue;
            }

            d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
        }
    }
  }

  if (n == 1 && a[0][0] == 0) {
    cout << "0 0 0" ;
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
        if (d[i][j] >= INF) {
            cout << "0 0 0";
            for (int k = 0; k < n; ++k) {
                delete[] a[k];
                delete[] d[k];
            }
            delete[] a;
            delete[] d;
            return 0;
        }
    }
  }

  ll diam = 0;
  int n1 = 0, n2 = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
        if (d[i][j] > diam) {
            diam = d[i][j];
            n1 = i;
            n2 = j;
        }
    }
  }

  if(d[n1][n2] == INF) {
    cout << "0 0 0";
    return 0;
  }

  cout << n1+1 << " " << n2+1 << " " << diam;

  for (int i = 0; i < n; ++i) {
    delete[] a[i];
    delete[] d[i];
  }

  delete[] a;
  delete[] d;
}
