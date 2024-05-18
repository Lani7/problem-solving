#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;

  int n, k;
  cin >> n >> k;

  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int count = 0;

  for (int i = n - 1; i >= 0; i--)
  {
    if (a[i] <= k)
    {
      count += k / a[i];
      k %= a[i];
    }
  }

  cout << count;
}