#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;

  vector<int> s(n + 1, 0);

  for (int i = 1; i <= n; i++)
  {
    int num;
    cin >> num;
    s[i] += s[i - 1] + num;
  }

  int start = 1;
  int end = k;
  int result = numeric_limits<int>::min();

  while (end <= n)
  {
    int sum = s[end] - s[start - 1];
    result = max(sum, result);
    start++;
    end++;
  }

  cout << result << endl;
}