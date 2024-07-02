#include <iostream>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;

  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> list(n + 1);
  vector<vector<pair<int, int>>> reversedList(n + 1);
  int indegree[100001] = {0};

  for (int i = 0; i < m; i++)
  {
    int s, e, time;
    cin >> s >> e >> time;
    list[s].push_back({e, time});
    reversedList[e].push_back({s, time});
    indegree[e]++;
  }

  int start, end;
  cin >> start >> end;

  queue<int> q;
  q.push(start);
  int result[100001] = {0};

  while (!q.empty())
  {
    int now = q.front();
    q.pop();
    for (auto next : list[now])
    {
      indegree[next.first]--;
      result[next.first] = max(result[next.first], result[now] + next.second);
      if (indegree[next.first] == 0)
      {
        q.push(next.first);
      }
    }
  }

  int resultCnt = 0;
  bool visited[100001] = {false};

  q.push(end);
  visited[end] = true;
  while (!q.empty())
  {
    int now = q.front();
    q.pop();
    for (auto next : reversedList[now])
    {
      if (result[next.first] + next.second == result[now])
      {
        resultCnt++;
        if (!visited[next.first])
        {
          visited[next.first] = true;
          q.push(next.first);
        }
      }
    }
  }
  cout << result[end] << "\n";
  cout << resultCnt;
}