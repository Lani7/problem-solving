#include <iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  int start_ptr = 1;
  int end_ptr = 1;
  int sum = 1;
  int count = 0;

  while (end_ptr <= n)
  {
    if (sum < n)
    {
      end_ptr++;
      sum += end_ptr;
    }
    else if (sum > n)
    {
      sum -= start_ptr;
      start_ptr++;
    }
    else
    {
      count++;
      end_ptr++;
      sum += end_ptr;
    }
  }

  cout << count << "\n";
}