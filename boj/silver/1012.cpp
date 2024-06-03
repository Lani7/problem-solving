#include <iostream>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
queue<pair<int, int>> q;
int board[51][51];
bool visited[51][51];
int m, n, k;

int bfs(int i, int j);

int main()
{
  fastio;

  int t;
  cin >> t;

  for (int i = 0; i < t; i++)
  {
    int result = 0;
    cin >> m >> n >> k;

    // 초기화
    for (int j = 0; j < m; j++)
    {
      fill(board[j], board[j] + n, 0);
      fill(visited[j], visited[j] + n, false);
    }

    pair<int, int> veg[k]; // 배추 좌표 배열

    for (int j = 0; j < k; j++)
    {
      int x, y;
      cin >> x >> y;
      board[x][y] = 1;
      veg[j] = {x, y};
    }

    for (int j = 0; j < k; j++)
    {
      int x = veg[j].first;
      int y = veg[j].second;
      if (!visited[x][y])
        result += bfs(x, y);
    }
    cout << result << '\n';
  }
}

int bfs(int i, int j)
{
  q.push({i, j});
  visited[i][j] = true;

  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for (int dir = 0; dir < 4; dir++)
    {
      int nx = x + dx[dir];
      int ny = y + dy[dir];

      if (nx < 0 || nx >= m || ny < 0 || ny >= n)
        continue;
      if (visited[nx][ny] || board[nx][ny] == 0)
        continue;
      q.push({nx, ny});
      visited[nx][ny] = true;
    }
  }
  return 1;
}