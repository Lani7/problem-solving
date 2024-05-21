#include <iostream>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
queue<pair<int, int>> q;
int board[1001][1001];
int dist[1001][1001];
int m, n;
void bfs();

int main()
{
  fastio;
  cin >> m >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> board[i][j];
      if (board[i][j] == 1)
        q.push({i, j});
      else if (board[i][j] == 0)
        dist[i][j] = -1;
    }
  }

  bfs();

  int max_dist = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (dist[i][j] == -1)
      {
        cout << "-1";
        return 0;
      }
      max_dist = max(dist[i][j], max_dist);
    }
  }
  cout << max_dist;
}

void bfs()
{
  while (!q.empty())
  {
    pair<int, int> now = q.front();
    q.pop();

    for (int dir = 0; dir < 4; dir++)
    {
      int nx = now.first + dx[dir];
      int ny = now.second + dy[dir];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      if (dist[nx][ny] >= 0)
        continue;
      q.push({nx, ny});
      dist[nx][ny] = dist[now.first][now.second] + 1;
    }
  }
}