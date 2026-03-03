#include<bits/stdc++.h>
#define ll long long
//#define int int64_t
#define fi first
#define se second
#define pb push_back
#define mpi make_pair
#define nl '\n'
const double pi = 3.14159;
using namespace std;
int main() {
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  setlocale(LC_ALL,"russian");
  int n,m;
  cin >> n;
  cin.ignore();
  int** a = new int *[n];
  int** b = new int *[n];
  int* sz = new int [n];
  for (int i = 0; i < n; ++i) {
    a[i] = new int[n];
    sz[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
        cin >> a[i][j];
        if (a[i][j] == 1) {
            ++sz[i];
        }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (sz[i] > 0) {
      b[i] = new int[sz[i]];
    }
    else {
        b[i] = nullptr;
    }
  }
  int idx;
  for (int i = 0; i < n; ++i) {
    idx = 0;
    for (int j = 0; j < n; ++j) {
        if (a[i][j] == 1) {
          b[i][idx++] = j+1;
        }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (sz[i] == 0) {
        cout << 0 << nl;
    }
    else {
        for (int j = 0; j < sz[i]; ++j) {
          cout << b[i][j] << " ";
        }
        cout << nl;
    }
  }
  for (int i = 0; i < n; ++i) {
    delete[] b[i];
  }
  delete[] b;
   for (int i = 0; i < n; ++i) {
    delete[] a[i];
  }
  delete[] a;
  delete[] sz;
}
