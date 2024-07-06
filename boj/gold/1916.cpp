#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;
  int n, m;
  cin >> n >> m;

  typedef pair<int, int> edge;
  vector<vector<edge>> list(n + 1);
  vector<bool> visited(n + 1);
  vector<int> dist(n + 1, INT_MAX);
  priority_queue<edge, vector<edge>, greater<edge>> pq;

  for (int i = 0; i < m; i++)
  {
    int s, e, value;
    cin >> s >> e >> value;
    list[s].push_back({e, value});
  }

  int start, end;
  cin >> start >> end;
  pq.push({0, start});
  dist[start] = 0;

  while (!pq.empty())
  {
    edge cur = pq.top();
    pq.pop();
    int cur_v = cur.second;
    if (visited[cur_v])
      continue;
    visited[cur_v] = true;
    for (edge next : list[cur_v])
    {
      int next_v = next.first;
      int value = next.second;
      if (dist[cur_v] + value < dist[next_v])
      {
        dist[next_v] = dist[cur_v] + value;
        pq.push({dist[next_v], next_v});
      }
    }
  }

  cout << dist[end];
}