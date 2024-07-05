#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;

  int v, e, k;
  cin >> v >> e >> k;

  typedef pair<int, int> edge;
  vector<vector<edge>> list(v + 1);
  vector<int> dist(v + 1, INT_MAX);
  vector<bool> visited(v + 1, false);
  priority_queue<edge, vector<edge>, greater<edge>> pq; // 오름차순 정렬

  for (int i = 0; i < e; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    list[u].push_back({v, w});
  }

  // 시작 노드 삽입
  pq.push({0, k});
  dist[k] = 0;

  while (!pq.empty())
  {
    edge now = pq.top();
    pq.pop();
    int now_v = now.second; // 현재 선택 노드
    if (visited[now_v])
      continue;
    visited[now_v] = true;
    for (auto next : list[now_v])
    {
      int next_v = next.first; // 인접 노드
      int value = next.second; // 에지 가중치
      if (dist[now_v] + value < dist[next_v])
      {
        // 최단 거리 업데이트
        dist[next_v] = dist[now_v] + value;
        pq.push({dist[next_v], next_v});
      }
    }
  }

  for (int i = 1; i <= v; i++)
  {
    if (visited[i])
      cout << dist[i] << "\n";
    else
      cout << "INF" << "\n";
  }
}