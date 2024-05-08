#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

bool arrived;
vector<bool> visited;
vector<vector<int>> list;
void dfs(int v, int depth);

int main()
{
  fastio;
  int n, m;
  cin >> n >> m;

  list.resize(n);
  visited = vector<bool>(n, false);

  for (int i = 0; i < m; i++)
  {
    int s, e;
    cin >> s >> e;
    list[s].push_back(e);
    list[e].push_back(s);
  }

  for (int i = 0; i < n; i++)
  {
    dfs(i, 1);
    if (arrived)
      break;
  }

  if (arrived)
    cout << "1";
  else
    cout << "0";
}

void dfs(int v, int depth)
{
  if (depth == 5 || arrived)
  {
    arrived = true;
    return;
  }
  visited[v] = true;
  for (int w : list[v])
  {
    if (!visited[w])
      dfs(w, depth + 1);
  }
  visited[v] = false;
}