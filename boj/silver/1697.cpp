#include <iostream>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int dist[100001];
void bfs(int node, int k);

int main()
{
  fastio;

  int n, k;
  cin >> n >> k;

  fill(dist, dist + 100001, -1);
  dist[n] = 0;

  bfs(n, k);

  cout << dist[k] << endl;
}

void bfs(int node, int k)
{
  queue<int> q;
  q.push(node);

  while (dist[k] == -1)
  {
    int now = q.front();
    q.pop();
    for (int next : {now - 1, now + 1, now * 2})
    {
      if (next < 0 || next > 100000)
        continue;
      if (dist[next] != -1)
        continue;
      q.push(next);
      dist[next] = dist[now] + 1;
    }
  }
}