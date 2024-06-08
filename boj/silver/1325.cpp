#include <iostream>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

vector<vector<int>> list;
vector<bool> visited;
vector<int> result;

void bfs(int v);

int main()
{
  fastio;
  int n, m;
  cin >> n >> m;

  list.resize(n + 1);
  visited.resize(n + 1);
  result.resize(n + 1);

  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    list[a].push_back(b);
  }

  for (int i = 1; i <= n; i++)
  {
    fill(visited.begin(), visited.end(), false);
    bfs(i);
  }

  // 최댓값 찾기
  int max_val = 0;
  for (int i = 1; i <= n; i++)
    max_val = max(result[i], max_val);

  // 최댓값의 index 찾기
  for (int i = 1; i <= n; i++)
    if (result[i] == max_val)
      cout << i << ' ';
}

void bfs(int v)
{
  queue<int> q;
  q.push(v);
  visited[v] = true;

  while (!q.empty())
  {
    int now = q.front();
    q.pop();

    for (int next : list[now])
    {
      if (visited[next])
        continue;
      q.push(next);
      visited[next] = true;
      result[next]++;
    }
  }
}