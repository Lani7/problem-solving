#include <iostream>
#include <algorithm>
#include <climits>
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

  long long count = LLONG_MAX;
  long long result[3];

  for (int i = 0; i < n - 1; i++)
  {
    int start = i + 1;
    int end = n - 1;
    while (start < end)
    {
      long long sum = (long long)a[start] + a[end] + a[i];
      if (count > abs(sum))
      {
        count = abs(sum);
        result[0] = a[start];
        result[1] = a[end];
        result[2] = a[i];
      }
      if (sum > 0)
        end--;
      else if (sum < 0)
        start++;
      else
        break;
    }
  }

  sort(result, result + 3);
  for (auto el : result)
    cout << el << " ";
}