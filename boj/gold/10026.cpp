#include <iostream>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char board[101][101];
bool visited[101][101];
int n, cnt;

void non_color_blind_bfs(int i, int j);
void color_blind_bfs(int i, int j);
void bfs(int i, int j, char c);

int main()
{
  fastio;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cin >> board[i][j];
  }

  // 적록색약이 아닌 경우
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (!visited[i][j])
      {
        bfs(i, j, 'N');
        cnt++;
      }
    }
  }
  cout << cnt << "\n";

  // 초기화
  cnt = 0;
  for (int i = 0; i < n; i++)
    fill(visited[i], visited[i] + n, false);

  // 적록색약인 경우
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (!visited[i][j])
      {
        bfs(i, j, 'Y');
        cnt++;
      }
    }
  }
  cout << cnt << "\n";
}

void bfs(int i, int j, char c)
{
  queue<pair<int, int>> q;
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

      if (nx < 0 || nx >= n || ny < 0 || ny >= n)
        continue;
      if (visited[nx][ny])
        continue;
      // 적록색약이 아닌 경우
      if (c == 'N')
      {
        if (board[nx][ny] != board[x][y])
          continue;
      }
      // 적록색약인 경우
      else if (c == 'Y')
      {
        if (board[x][y] != 'B' && board[nx][ny] == 'B')
          continue;
        if (board[x][y] == 'B' && board[nx][ny] != 'B')
          continue;
      }
      q.push({nx, ny});
      visited[nx][ny] = true;
    }
  }
}