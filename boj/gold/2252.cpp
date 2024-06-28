#include <iostream>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int indegree[32001];
int main()
{
  fastio;

  int n, m;
  cin >> n >> m;

  vector<vector<int>> list(n + 1);

  while (m-- > 0)
  {
    int a, b;
    cin >> a >> b;
    list[a].push_back(b);
    indegree[b]++;
  }

  queue<int> q;
  for (int i = 1; i <= n; i++)
  {
    if (indegree[i] == 0)
      q.push(i);
  }

  while (!q.empty())
  {
    int now = q.front();
    q.pop();
    cout << now << " ";
    for (int next : list[now])
    {
      indegree[next]--;
      if (indegree[next] == 0)
        q.push(next);
    }
  }
}