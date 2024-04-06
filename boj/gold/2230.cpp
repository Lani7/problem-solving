#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 2e9;
using namespace std;

int main()
{
  fastio;
  int n, m;
  cin >> n >> m;

  int a[n];

  for (int i = 0; i < n; i++)
  {
    int num;
    cin >> num;
    a[i] = num;
  }

  sort(a, a + n);

  int start = 0, end = 0;
  int cnt = INF;
  int result = INF;

  while (start <= end && end < n)
  {
    if (a[end] - a[start] < m)
      end++;
    else
    {
      cnt = a[end] - a[start];
      start++;
    }
    result = min(result, cnt);
  }
  cout << result;
}