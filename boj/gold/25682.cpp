#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 2e9;
using namespace std;

int main()
{
  fastio;

  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<int>> b_board(n + 1, vector<int>(m + 1, 0));
  vector<vector<int>> w_board(n + 1, vector<int>(m + 1, 0));

  // 다시 칠해야 하는 수만큼 누적 합 벡터 구하기 (다시 칠해야 할 칸마다 1씩 누적합)
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      char c;
      cin >> c;
      if ((i + j) % 2 == 0)
      {
        if (c == 'B')
        {
          b_board[i][j] = b_board[i][j - 1] + b_board[i - 1][j] - b_board[i - 1][j - 1];
          w_board[i][j] = w_board[i][j - 1] + w_board[i - 1][j] - w_board[i - 1][j - 1] + 1;
        }
        else if (c == 'W')
        {
          b_board[i][j] = b_board[i][j - 1] + b_board[i - 1][j] - b_board[i - 1][j - 1] + 1;
          w_board[i][j] = w_board[i][j - 1] + w_board[i - 1][j] - w_board[i - 1][j - 1];
        }
      }
      else
      {
        if (c == 'B')
        {
          b_board[i][j] = b_board[i][j - 1] + b_board[i - 1][j] - b_board[i - 1][j - 1] + 1;
          w_board[i][j] = w_board[i][j - 1] + w_board[i - 1][j] - w_board[i - 1][j - 1];
        }
        else if (c == 'W')
        {
          b_board[i][j] = b_board[i][j - 1] + b_board[i - 1][j] - b_board[i - 1][j - 1];
          w_board[i][j] = w_board[i][j - 1] + w_board[i - 1][j] - w_board[i - 1][j - 1] + 1;
        }
      }
    }
  }

  int result = INF;
  int b_cnt = 0;
  int w_cnt = 0;
  // k*k 구간만큼 최소 개수 구하기
  for (int i = k; i <= n; i++)
  {
    for (int j = k; j <= m; j++)
    {
      b_cnt = b_board[i][j] - b_board[i - k][j] - b_board[i][j - k] + b_board[i - k][j - k];
      w_cnt = w_board[i][j] - w_board[i - k][j] - w_board[i][j - k] + w_board[i - k][j - k];
      result = min(result, min(b_cnt, w_cnt));
    }
  }
  cout << result;
}
