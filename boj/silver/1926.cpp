#include <iostream>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int map[501][501];
bool visited[501][501] = {false};
int n, m;
int bfs(int x, int y);

int main()
{
  fastio;

  cin >> n >> m;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> map[i][j];

  int max_area = 0; // 최대 그림 넓이
  int count = 0;    // 그림 개수
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      if (!visited[i][j] && map[i][j] != 0)
      {
        max_area = max(max_area, bfs(i, j));
        count++;
      }
    }

  cout << count << '\n';
  cout << max_area;
}

int bfs(int x, int y)
{
  queue<pair<int, int>> q;
  q.push({x, y});
  visited[x][y] = true;
  int area = 0; // 그림 넓이

  while (!q.empty())
  {
    pair<int, int> now = q.front();
    q.pop();
    area++;

    for (int dir = 0; dir < 4; dir++)
    {
      int nx = now.first + dx[dir];
      int ny = now.second + dy[dir];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      if (visited[nx][ny] || map[nx][ny] != 1)
        continue;

      q.push({nx, ny});
      visited[nx][ny] = true;
    }
  }
  return area;
}