#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;

  int n, m;
  cin >> n >> m;

  vector<long long> s(n + 1, 0);

  for (int i = 1; i <= n; i++)
  {
    int num;
    cin >> num;
    s[i] = s[i - 1] + num;
  }

  long long result = -1;

  for (int i = m; i <= n; i++)
  {
    long long sum = s[i] - s[i - m];
    result = max(sum, result);
  }

  cout << result;
}