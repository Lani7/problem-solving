#include <iostream>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int map[101][101];
bool visited[101][101] = {false};
int n, m;
void bfs(int i, int j);

int main()
{
  fastio;

  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++)
      map[i][j] = s[j] - '0';
  }

  bfs(0, 0);
  cout << map[n - 1][m - 1];
}

void bfs(int i, int j)
{
  queue<pair<int, int>> q;
  q.push(make_pair(i, j));
  visited[i][j] = true;

  while (!q.empty())
  {
    int now[2];
    now[0] = q.front().first;
    now[1] = q.front().second;
    q.pop();

    // 상하좌우 탐색
    for (int k = 0; k < 4; k++)
    {
      int x = now[0] + dx[k];
      int y = now[1] + dy[k];

      if (x >= 0 && y >= 0 && x < n && y < m)
      {
        if (map[x][y] != 0 && !visited[x][y])
        {
          visited[x][y] = true;
          map[x][y] = map[now[0]][now[1]] + 1; // 깊이 업데이트
          q.push(make_pair(x, y));
        }
      }
    }
  }
}