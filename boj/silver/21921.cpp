#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;
  int n, x;
  cin >> n >> x;

  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int sum = 0;
  int result = -1;
  int count = 0;

  for (int i = 0; i < x; i++)
  {
    sum += a[i];
    if (sum > result)
    {
      result = sum;
      count = 1;
    }
  }

  for (int i = x; i < n; i++)
  {
    sum += a[i];
    sum -= a[i - x];
    if (sum > result)
    {
      result = sum;
      count = 1;
    }
    else if (sum == result)
      count++;
  }

  if (result == 0)
    cout << "SAD";
  else
  {
    cout << result << "\n";
    cout << count << "\n";
  }
}