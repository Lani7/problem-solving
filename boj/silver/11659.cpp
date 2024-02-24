#include <iostream>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, answer;

  cin >> n >> m;
  int s[100001] = {};

  // 합 배열 만들기
  for (int i = 1; i <= n; i++)
  {
    int input;
    cin >> input;
    s[i] = s[i - 1] + input;
  }

  for (int k = 0; k < m; k++)
  {
    int i, j;
    cin >> i >> j;
    answer = s[j] - s[i - 1];
    cout << answer << "\n";
  }

  return 0;
}