#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

vector<vector<int>> list;
vector<int> visited;

void bfs(int v);

int main()
{
  fastio;
  int n, m, k, x;
  cin >> n >> m >> k >> x;

  // 벡터 크기 설정 및 초기화
  list.resize(n + 1);
  visited.resize(n + 1);
  fill(visited.begin(), visited.end(), -1);

  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    list[a].push_back(b);
  }

  bfs(x);

  vector<int> result;
  for (int i = 0; i <= n; i++)
  {
    if (visited[i] == k)
      result.push_back(i);
  }

  if (result.empty())
    cout << "-1";
  else
  {
    sort(result.begin(), result.end());
    for (int e : result)
      cout << e << "\n";
  }
}

void bfs(int v)
{
  queue<int> q;
  q.push(v);
  visited[v] = 0;

  while (!q.empty())
  {
    int now = q.front();
    q.pop();

    for (int next : list[now])
    {
      // 방문하지 않은 경우
      if (visited[next] == -1)
      {
        q.push(next);
        visited[next] = visited[now] + 1;
      }
    }
  }
}