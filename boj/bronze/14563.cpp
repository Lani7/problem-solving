#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int check_perfect_num(int n)
{
  int sum = 0;

  for (int i = 1; i < n; i++)
    if (n % i == 0)
      sum += i;

  if (sum == n)
    return 1;
  else if (sum < n)
    return -1;
  else
    return 2;
}

int main()
{
  fastio;

  int t;
  cin >> t;

  for (int i = 0; i < t; i++)
  {
    int n;
    cin >> n;
    switch (check_perfect_num(n))
    {
    case 1:
      cout << "Perfect \n";
      break;
    case -1:
      cout << "Deficient \n";
      break;
    case 2:
      cout << "Abundant \n";
      break;
    }
  }
}