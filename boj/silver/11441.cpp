#include <iostream>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n;
  int s[n];

  for (int i = 1; i <= n; i++)
  {
    int num;
    cin >> num;
    s[i] = s[i - 1] + num;
  }

  cin >> m;
  for (int k = 0; k < m; k++)
  {
    int i, j;
    cin >> i >> j;
    cout << s[j] - s[i - 1] << '\n';
  }
}