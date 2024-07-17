#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
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
        dist[i][j] = 10000001;
    }
  }

  for (int i = 0; i < m; i++)
  {
    int s, e, w;
    cin >> s >> e >> w;
    if (w < dist[s][e])
      dist[s][e] = w;
  }

  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (dist[i][j] == 10000001)
        cout << "0 ";
      else
        cout << dist[i][j] << " ";
    }
    cout << "\n";
  }
}