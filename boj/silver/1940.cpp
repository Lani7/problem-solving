#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;

  cin >> n >> m;

  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int start = 0;
  int end = n - 1;
  int count = 0;

  sort(a, a + n);

  while (start < end)
  {
    if (a[start] + a[end] < m)
      start++;
    else if (a[start] + a[end] > m)
      end--;
    else
    {
      start++;
      end--;
      count++;
    }
  }

  cout << count << "\n";
}