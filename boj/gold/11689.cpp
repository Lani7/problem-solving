#include <iostream>
#include <cmath>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;

  long n;
  cin >> n;

  long result = n;
  for (long p = 2; p <= sqrt(n); p++)
  {
    // p가 소인수인 경우
    if (n % p == 0)
    {
      result = result - result / p; // 해당 소인수의 배수 빼기
      // 다른 소인수 구하기
      while (n % p == 0)
        n = n / p;
    }
  }
  // n이 마지막 소인수인 경우
  if (n > 1)
    result = result - result / n;
  cout << result;
}