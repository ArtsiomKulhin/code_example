#include <bits/stdc++.h>

#define ll long long
#define nl '\n'
#define int int64_t
#define f first
#define s second
#define e_b emplace_back
#define pb push_back

using namespace std;

int32_t main() {
  //freopen("deadends.in","r",stdin);
  //freopen("deadends.out","w",stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,m;

  cin >> n >> m;

  vector<string>s(n);

  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};

  vector<vector<int>>d(n,vector<int>(m,0));
  vector<vector<bool>>fl(n,vector<bool>(m,false));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
        if(s[i][j] == '.') {
        for (int k = 0; k < 4; ++k) {
          int cx = i+dx[k];
          int cy = j+dy[k];
          if(cx >= 0 && cx < n && cy >= 0 && cy < m && s[cx][cy] == '.'){
            ++d[i][j];
          }
        }
      }
    }
  }
  queue<pair<int,int>> q;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
        if(s[i][j] == '.' && d[i][j] <= 1){
            fl[i][j] = true;
            q.push({i,j});
        }
    }
  }

  while(!q.empty()){
    auto [x,y] = q.front();

    q.pop();

    for (int k = 0; k < 4; ++k) {
        int cx = x+dx[k];
        int cy = y+dy[k];

        if(cx < 0 || cx >= n || cy < 0 || cy >= m){
            continue;
        }

        if(s[cx][cy] == '.' && !fl[cx][cy]){
            --d[cx][cy];

        if(d[cx][cy] <= 1){
            fl[cx][cy] = true;
            q.push({cx,cy});
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {

    for (int j = 0; j < m; ++j) {

        if(s[i][j] == '#'){
            cout << '#';
        }
        else{
            if(fl[i][j]){
                cout << 'X';
            }
            else{
                cout << '.';
            }
        }
    }

    cout << nl;
  }

}
