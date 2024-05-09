#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

vector<vector<int>> list;
vector<bool> visited;
void dfs(int v);
void bfs(int v);

int main()
{
  fastio;
  int n, m, v;
  cin >> n >> m >> v;
  list.resize(n + 1);

  for (int i = 0; i < m; i++)
  {
    int s, e;
    cin >> s >> e;
    list[s].push_back(e);
    list[e].push_back(s);
  }

  for (int i = 1; i <= n; i++)
    sort(list[i].begin(), list[i].end());

  // 방문 배열 초기화
  visited = vector<bool>(n + 1, false);
  dfs(v);
  cout << "\n";
  // 방문 배열 초기화
  fill(visited.begin(), visited.end(), false);
  bfs(v);
}

void dfs(int v)
{
  visited[v] = true;

  cout << v << " ";

  for (int i = 0; i < list[v].size(); i++)
  {
    int w = list[v][i];
    if (!visited[w])
      dfs(w);
  }
}

void bfs(int v)
{
  queue<int> q;
  visited[v] = true;
  q.push(v);

  while (!q.empty())
  {
    v = q.front();
    q.pop();

    cout << v << " ";

    for (int i = 0; i < list[v].size(); i++)
    {
      int w = list[v][i];
      if (!visited[w])
      {
        q.push(w);
        visited[w] = true;
      }
    }
  }
}