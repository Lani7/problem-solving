#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 2e9;
using namespace std;

int main()
{
  fastio;
  int n, k, b;
  cin >> n >> k >> b;
  vector<int> v(n + 1, 0);

  for (int i = 0; i < b; i++)
  {
    int num;
    cin >> num;
    v[num]++;
  }

  for (int i = 1; i <= n; i++)
    v[i] += v[i - 1];

  int result = INF;

  for (int i = k; i <= n; i++)
  {
    int sum = v[i] - v[i - k];
    result = min(result, sum);
  }

  cout << result << "\n";
}