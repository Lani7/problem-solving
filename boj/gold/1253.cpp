#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  long a[n];

  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a + n);

  int count = 0;

  for (int i = 0; i < n; i++)
  {
    int start = 0;
    int end = n - 1;

    while (start < end)
    {
      if (start == i)
        start++;
      else if (end == i)
        end--;

      if (start == end)
        break;

      if (a[start] + a[end] < a[i])
        start++;
      else if (a[start] + a[end] > a[i])
        end--;
      else
      {
        start++;
        end--;
        count++;
        break;
      }
    }
  }

  cout << count << "\n";
}