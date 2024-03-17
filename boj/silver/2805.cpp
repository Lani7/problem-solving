#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

long long check(long long a[], long long mid);
int n, m;

int main()
{
  fastio;

  cin >> n >> m;

  long long a[n];
  long long low = 1, high = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    high = max(high, a[i]);
  }

  while (low < high)
  {
    long long mid = (low + high) / 2;
    if (check(a, mid) < m)
      high = mid;
    else
      low = mid + 1;
  }

  cout << low - 1 << "\n";
}

long long check(long long a[], long long mid)
{
  long long sum = 0;
  for (int i = 0; i < n; i++)
    if (a[i] > mid)
      sum += a[i] - mid;
  return sum;
}