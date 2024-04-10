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

  int start = 0, end = 0;
  int odd_num = 0;
  int cnt = 0;
  int result = -1;

  if (a[start] % 2 == 1)
    odd_num++;
  else
    cnt++;

  while (start <= end && end < n)
  {
    if (odd_num > k)
    {
      result = max(result, cnt);
      if (a[start] % 2 == 1)
        odd_num--;
      else
        cnt--;
      start++;
    }
    else if (odd_num <= k)
    {
      end++;
      if (end >= n)
        break;
      if (a[end] % 2 == 1)
        odd_num++;
      else if (a[end] % 2 == 0)
        cnt++;
    }
  }
  result = max(result, cnt);

  cout << result;
}