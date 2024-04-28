#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 2e9;
using namespace std;

int main()
{
  fastio;

  int n;
  cin >> n;

  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  sort(arr, arr + n);

  int result = INF;
  for (int a_start = 0; a_start < n - 3; a_start++)
  {
    for (int a_end = a_start + 3; a_end < n; a_end++)
    {
      int b_start = a_start + 1;
      int b_end = a_end - 1;

      while (b_start < b_end)
      {
        int a_sum = arr[a_start] + arr[a_end];
        int b_sum = arr[b_start] + arr[b_end];
        int diff = b_sum - a_sum;
        result = min(result, abs(diff));

        if (diff > 0)
          b_end--;
        else if (diff < 0)
          b_start++;
        else
        {
          cout << '0';
          return 0;
        }
      }
    }
  }

  cout << result;
}