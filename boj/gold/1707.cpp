#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

vector<vector<int>> list;
vector<int> visited;
vector<int> check;
bool isBip; // 이분 그래프 여부

void dfs(int v);

int main()
{
  fastio;

  int k;
  cin >> k;

  while (k--)
  {
    int v, e;
    cin >> v >> e;

    // 초기화
    list = vector<vector<int>>(v + 1, vector<int>());
    visited = vector<int>(v + 1, false);
    check = vector<int>(v + 1, 0);
    isBip = true;

    for (int i = 0; i < e; i++)
    {
      int u, v;
      cin >> u >> v;
      list[u].push_back(v);
      list[v].push_back(u);
    }

    // 모든 노드에서 dfs 탐색
    for (int i = 1; i <= v; i++)
    {
      if (isBip)
        dfs(i);
      else
        break;
    }

    if (isBip)
      cout << "YES" << "\n";
    else
      cout << "NO" << "\n";
  }
}

void dfs(int v)
{
  visited[v] = true;
  for (int next : list[v])
  {
    if (!visited[next])
    {
      // 현재 노드와 다른 집합으로 저장
      check[next] = (check[v] + 1) % 2;
      dfs(next);
    }
    // 이미 방문했으면서 현재 노드와 집합이 같을 경우 이분 그래프 아님
    else if (check[next] == check[v])
      isBip = false;
  }
}