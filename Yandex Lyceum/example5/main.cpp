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
  int n;
  cin >> n;
  int** a = new int *[n];
  for (int i = 0; i < n; ++i) {
        a[i] = new int[n];
    for (int j = 0; j < n; ++j) {
        cin >> a[i][j];
    }
  }
  int* b = new int[1000];
  int id = 0, val;
  while (cin >> val) {
    b[id++] = val-1;
  }
  int s = 0;
  for (int i = 1; i < id; ++i) {
    int u = b[i-1];
    int v = b[i];
    if (a[u][v] == 0) {
        cout << 0;
    for (int j = 0; j < n; ++j) {
        delete[] a[j];
    }
    delete[] a;
    delete[] b;
    return 0;
    }
    s += a[u][v];
  }
  cout << s;
  delete[] b;
  for (int i = 0; i < n; ++i) {
    delete[] a[i];
  }
  delete[] a;
}
