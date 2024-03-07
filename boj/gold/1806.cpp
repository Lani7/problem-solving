#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, s;
  cin >> n >> s;

  vector<int> a(n + 1, 0);

  int start = 1;
  int end = 1;
  int count = 0;
  int result = numeric_limits<int>::max();

  for (int i = 1; i <= n; i++)
  {
    int num;
    cin >> num;
    a[i] = a[i - 1] + num;
  }

  while (start <= end && end <= n)
  {
    int sum = a[end] - a[start - 1];
    if (sum < s)
      end++;
    else
    {
      count++;
      int lenth = end - start + 1;
      if (result > lenth)
        result = lenth;
      if (sum > s)
        start++;
      else if (sum == s)
      {
        start++;
        end++;
      }
    }
  }

  if (!count)
    result = 0;

  cout << result << "\n";
}