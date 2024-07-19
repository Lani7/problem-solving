#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;

  int n;
  cin >> n;

  int dist[101][101];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cin >> dist[i][j];
  }

  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (dist[i][k] == 1 && dist[k][j] == 1)
          dist[i][j] = 1;
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cout << dist[i][j] << " ";
    cout << "\n";
  }
}