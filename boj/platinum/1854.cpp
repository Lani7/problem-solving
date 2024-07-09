#include <iostream>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;

  int n, m, k;
  cin >> n >> m >> k;

  typedef pair<int, int> node;
  vector<vector<node>> list(n + 1);
  priority_queue<int> dist[1001];

  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    list[a].push_back({b, c});
  }

  priority_queue<node, vector<node>, greater<node>> pq;
  pq.push({0, 1});
  dist[1].push(0);

  while (!pq.empty())
  {
    node cur = pq.top();
    pq.pop();
    int cur_dist = cur.first;
    int cur_v = cur.second;

    for (node next : list[cur_v])
    {
      int next_v = next.first;
      int value = next.second;
      if (dist[next_v].size() < k)
      {
        dist[next_v].push(cur_dist + value);
        pq.push({cur_dist + value, next_v});
      }
      else if (cur_dist + value < dist[next_v].top())
      {
        dist[next_v].pop();
        dist[next_v].push(cur_dist + value);
        pq.push({cur_dist + value, next_v});
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    if (dist[i].size() == k)
      cout << dist[i].top() << "\n";
    else
      cout << "-1 \n";
  }
}