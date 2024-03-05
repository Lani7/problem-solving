#include <iostream>
#include <vector>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> s(n + 1, vector<int>(m + 1, 0));

  // 2차원 합배열 만들기
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      int num;
      cin >> num;
      s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + num;
    }
  }

  int k;
  cin >> k;

  for (int idx = 0; idx < k; idx++)
  {
    int i, j, x, y;
    cin >> i >> j >> x >> y;
    cout << s[x][y] - s[x][j - 1] - s[i - 1][y] + s[i - 1][j - 1] << '\n';
  }
}