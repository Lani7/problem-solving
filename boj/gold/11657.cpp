#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;

  int n, m;
  cin >> n >> m;

  typedef tuple<int, int, int> edge;
  vector<edge> edges;
  vector<long> dist(n + 1, LONG_MAX);

  for (int i = 0; i < m; i++)
  {
    int s, e, w;
    cin >> s >> e >> w;

    edges.push_back({s, e, w});
  }

  dist[1] = 0;

  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int start = get<0>(edges[j]);
      int end = get<1>(edges[j]);
      int time = get<2>(edges[j]);
      if (dist[start] == LONG_MAX)
        continue;
      if (dist[start] + time < dist[end])
        dist[end] = dist[start] + time;
    }
  }

  // 음수 사이클 확인
  bool isCycle = false;
  for (int i = 0; i < m; i++)
  {
    int start = get<0>(edges[i]);
    int end = get<1>(edges[i]);
    int time = get<2>(edges[i]);
    if (dist[start] == LONG_MAX)
      continue;
    if (dist[start] + time < dist[end])
      isCycle = true;
  }

  if (isCycle)
    cout << "-1 \n";
  else
  {
    for (int i = 2; i <= n; i++)
    {
      if (dist[i] == LONG_MAX)
        cout << "-1 \n";
      else
        cout << dist[i] << "\n";
    }
  }
}