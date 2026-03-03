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
  int kol_v = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
        if (a[i][j] == 1) {
            if (a[j][i] && i < j) {
                kol_v+=1;
            }
            else if(a[j][i] != 1){
                kol_v+=1;
            }
        }
    }
  }
  cout << kol_v;
  for (int i = 0; i < n; ++i) {
    delete[] a[i];
  }
  delete[] a;
}
