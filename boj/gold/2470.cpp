#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;

  int n;
  cin >> n;

  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);

  int start = 0;
  int end = n - 1;
  int sum = 0;
  pair<int, int> result = {a[start], a[end]};

  while (start < end)
  {
    sum = a[start] + a[end];
    if (abs(sum) < abs(result.first + result.second))
      result = make_pair(a[start], a[end]);

    if (sum < 0)
      start++;
    else if (sum > 0)
      end--;
    else
    {
      cout << a[start] << " " << a[end] << endl;
      return 0;
    }
  }
  cout << result.first << " " << result.second << endl;
}
