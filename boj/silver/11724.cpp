#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

vector<vector<int>> list;
vector<bool> visited;
void dfs(int v);

int main()
{
  fastio;

  int n, m;
  cin >> n >> m;

  list = vector<vector<int>>(n + 1);
  visited = vector<bool>(n + 1, false);

  for (int i = 0; i < m; i++)
  {
    int s, e;
    cin >> s >> e;
    list[s].push_back(e);
    list[e].push_back(s);
  }

  int count = 0;
  for (int i = 1; i <= n; i++)
  {
    if (!visited[i])
    {
      count++;
      dfs(i);
    }
  }
  cout << count;
}

void dfs(int v)
{
  if (visited[v])
    return;
  visited[v] = true;
  for (int i : list[v])
    if (!visited[i])
      dfs(i);
}