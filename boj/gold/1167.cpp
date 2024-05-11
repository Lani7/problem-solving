#include <iostream>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

vector<vector<pair<int, int>>> list;
vector<bool> visited;   // 방문 체크
vector<int> e_distance; // 거리 저장
void bfs(int v);

int main()
{
  fastio;
  int v;
  cin >> v;

  list.resize(v + 1);

  for (int i = 0; i < v; i++)
  {
    int s;
    cin >> s;
    while (true)
    {
      int e;
      cin >> e;
      if (e == -1)
        break;
      int dis;
      cin >> dis;
      list[s].push_back({e, dis});
    }
  }

  visited = vector<bool>(v + 1, false);
  e_distance = vector<int>(v + 1, 0);

  // 임의의 노드부터 탐색
  bfs(1);

  // 임의의 노드에서 거리가 가장 먼 노드(트리의 지름을 구성하는 노드 중 하나) 구하기
  int max_idx = 1;
  for (int i = 2; i <= v; i++)
  {
    if (e_distance[max_idx] < e_distance[i])
      max_idx = i;
  }

  // 초기화
  fill(visited.begin(), visited.end(), false);
  fill(e_distance.begin(), e_distance.end(), 0);

  // 임의의 노드에서 거리가 가장 먼 노드(트리의 지름을 구성하는 노드 중 하나)부터 탐색
  bfs(max_idx);

  // 트리의 지름(트리를 구성하는 노드 중 두 노드 사이의 거리가 가장 긴 것) 구하기
  int result = 0;
  for (int i = 0; i < e_distance.size(); i++)
    result = max(result, e_distance[i]);
  cout << result;
}

void bfs(int v)
{
  queue<int> q;
  q.push(v);
  visited[v] = true;

  while (!q.empty())
  {
    v = q.front();
    q.pop();
    for (auto w : list[v])
    {
      if (!visited[w.first])
      {
        q.push(w.first);
        visited[w.first] = true;
        // 거리 저장
        e_distance[w.first] = e_distance[v] + w.second;
      }
    }
  }
}