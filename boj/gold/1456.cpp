#include <iostream>
#include <cmath>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

long arr[10000001];
int main()
{
  fastio;

  long a, b;
  cin >> a >> b;

  for (int i = 2; i <= 10000000; i++)
    arr[i] = i;

  for (int i = 2; i <= sqrt(10000000); i++)
  {
    // 소수가 아니면 건너뛰기
    if (arr[i] == 0)
      continue;
    // 소수의 배수값을 '소수 아님'으로 업데이트
    for (int j = i + i; j <= 10000000; j += i)
      arr[j] = 0;
  }

  int count = 0;
  for (int i = 2; i <= 10000000; i++)
  {
    // 소수인 경우 n제곱 개수 구하기
    if (arr[i])
    {
      long tmp = arr[i];
      // n제곱값이 최대범위 b를 초과할 경우 반복문 탈출
      if (arr[i] > b / tmp)
        break;
      // n제곱값이 long 범위를 초과할 경우를 위해 이항정리
      while ((double)arr[i] <= (double)b / tmp)
      {
        if ((double)arr[i] >= (double)a / tmp)
          count++;
        tmp *= arr[i];
      }
    }
  }
  cout << count;
}
