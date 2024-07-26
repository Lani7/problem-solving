#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 2e9
using namespace std;

int main()
{
  fastio;

  int n, m;
  cin >> n >> m;

  int dist[101][101];

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i == j)
        dist[i][j] = 0;
      else
        dist[i][j] = 10000000;
    }
  }

  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    dist[a][b] = 1;
    dist[b][a] = 1;
  }

  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
  }

  int min = INF;
  int answer = 0;

  for (int i = 1; i <= n; i++)
  {
    int num = 0;
    // 각 행의 합은 케빈 베이컨의 수
    for (int j = 1; j <= n; j++)
      num += dist[i][j];
    if (num < min)
    {
      min = num;
      answer = i;
    }
  }
  cout << answer;
}