#include <iostream>
using namespace std;

int arr[1025][1025] = {};
int darr[1025][1025] = {};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;

  cin >> n >> m;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> arr[i][j];
      // 합배열 만들기
      darr[i][j] = darr[i][j - 1] + darr[i - 1][j] - darr[i - 1][j - 1] + arr[i][j];
    }
  }

  for (int i = 0; i < m; i++)
  {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int sum = darr[x2][y2] - darr[x2][y1 - 1] - darr[x1 - 1][y2] + darr[x1 - 1][y1 - 1];
    cout << sum << "\n";
  }
}