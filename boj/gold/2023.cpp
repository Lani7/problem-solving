#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int n;
void dfs(int num, int place);
int isPrime(int num);

int main()
{
  fastio;
  cin >> n;

  for (auto i : {2, 3, 5, 7})
    dfs(i, 1);
}

void dfs(int num, int place)
{
  if (place == n)
  {
    if (isPrime(num))
      cout << num << "\n";
    return;
  }

  for (int i = 1; i < 10; i++)
  {
    if (i % 2 == 0)
      continue;
    if (isPrime(num * 10 + i))
      dfs(num * 10 + i, place + 1);
  }
}

int isPrime(int num)
{
  for (int i = 2; i <= num / 2; i++)
    if (num % i == 0)
      return 0;
  return 1;
}