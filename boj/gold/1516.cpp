#include <iostream>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;

  int n;
  cin >> n;

  vector<vector<int>> list(n + 1);
  int time[501];
  int indegree[501] = {0};
  int result[501] = {0};

  for (int i = 1; i <= n; i++)
  {
    cin >> time[i];
    int pre_build;
    cin >> pre_build;
    while (pre_build != -1)
    {
      list[pre_build].push_back(i);
      indegree[i]++;
      cin >> pre_build;
    }
  }

  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (indegree[i] == 0)
      q.push(i);

  while (!q.empty())
  {
    int now = q.front();
    q.pop();
    for (int next : list[now])
    {
      indegree[next]--;
      // result[next] = result[now] + time[now];
      result[next] = max(result[next], result[now] + time[now]);
      if (indegree[next] == 0)
        q.push(next);
    }
  }

  for (int i = 1; i <= n; i++)
  {
    result[i] += time[i];
    cout << result[i] << "\n";
  }
}