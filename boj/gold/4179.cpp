#include <iostream>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int r, c;
char board[1001][1001];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

queue<pair<int, int>> q;
int f_dist[1001][1001];
int j_dist[1001][1001];

void bfs();

int main()
{
  fastio;
  cin >> r >> c;

  // 초기화
  for (int i = 0; i < r; i++)
  {
    fill(f_dist[i], f_dist[i] + c, -1);
    fill(j_dist[i], j_dist[i] + c, -1);
  }

  pair<int, int> j_loc;
  for (int i = 0; i < r; i++)
  {
    string line;
    cin >> line;
    for (int j = 0; j < c; j++)
    {
      board[i][j] = line[j];
      if (board[i][j] == 'F')
      {
        f_dist[i][j] = 0;
        q.push({i, j});
      }
      else if (board[i][j] == 'J')
      {
        j_dist[i][j] = 0;
        j_loc.first = i;
        j_loc.second = j;
      }
    }
  }

  // 불 bfs
  bfs();

  // 지훈 bfs
  q.push({j_loc.first, j_loc.second});
  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for (int dir = 0; dir < 4; dir++)
    {
      int nx = x + dx[dir];
      int ny = y + dy[dir];

      if (nx < 0 || nx >= r || ny < 0 || ny >= c)
      {
        // 배열 범위를 벗어났으므로 탈출
        cout << j_dist[x][y] + 1;
        return 0;
      }
      if (j_dist[nx][ny] >= 0 || board[nx][ny] == '#')
        continue;
      // 지훈의 이동 범위에 불이 이미 확산되어 있을 경우
      if (f_dist[nx][ny] != -1 && f_dist[nx][ny] <= j_dist[x][y] + 1)
        continue;
      q.push({nx, ny});
      j_dist[nx][ny] = j_dist[x][y] + 1;
    }
  }
  cout << "IMPOSSIBLE";
}

void bfs()
{
  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for (int dir = 0; dir < 4; dir++)
    {
      int nx = x + dx[dir];
      int ny = y + dy[dir];

      if (nx < 0 || nx >= r || ny < 0 || ny >= c)
        continue;
      if (f_dist[nx][ny] >= 0 || board[nx][ny] == '#')
        continue;

      q.push({nx, ny});
      f_dist[nx][ny] = f_dist[x][y] + 1;
    }
  }
}