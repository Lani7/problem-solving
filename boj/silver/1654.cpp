#include <iostream>
#include <algorithm>
using namespace std;

int isMaxLen(int mid, int a[], int k);

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int k, n;
  cin >> k >> n;

  int a[k];
  int max_val;
  for (int i = 0; i < k; i++)
  {
    cin >> a[i];
    max_val = max(a[i], max_val);
  }

  long low = 1;
  long high = max_val;
  long mid;
  int result;

  while (low <= high)
  {
    mid = (low + high) / 2;
    if (isMaxLen(mid, a, k) >= n)
    {
      result = mid;
      low = mid + 1;
    }
    else
      high = mid - 1;
  }
  cout << result << "\n";
}

int isMaxLen(int mid, int a[], int k)
{
  int count = 0;
  for (int i = 0; i < k; i++)
    count += a[i] / mid;
  return count;
}