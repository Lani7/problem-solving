#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  int n, x;
  cin >> n;
  int a[n];

  for (int i = 0; i < n; i++)
    cin >> a[i];

  cin >> x;

  sort(a, a + n);

  int start = 0;
  int end = n - 1;
  int cnt = 0;

  while (start < end)
  {
    int sum = a[start] + a[end];
    if (sum > x)
      end--;
    else if (sum < x)
      start++;
    else
    {
      start++;
      cnt++;
    }
  }
  cout << cnt;
}
