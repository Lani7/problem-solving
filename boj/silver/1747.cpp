#include <iostream>
#include <cmath>
#include <string>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int a[10000001];
void makePrime();
bool isPalindrome(int num);

int main()
{
  fastio;

  int n;
  cin >> n;
  for (int i = 0; i <= 10000000; i++)
    a[i] = i;

  makePrime();

  while (true)
  {
    if (a[n] && isPalindrome(a[n]))
    {
      cout << a[n];
      break;
    }
    n++;
  }
}

void makePrime()
{
  a[1] = 0;
  for (int i = 2; i <= sqrt(10000000); i++)
  {
    // 소수가 아닐 경우 건너뛰기
    if (a[i] == 0)
      continue;
    // 소수의 배수를 '소수 아님'으로 업데이트
    for (int j = i + i; j <= 10000000; j += i)
      a[j] = 0;
  }
}

bool isPalindrome(int num)
{
  string str = to_string(num);

  int start = 0;
  int end = str.size() - 1;
  while (start < end)
  {
    if (str[start] != str[end])
      return false;
    start++;
    end--;
  }
  return true;
}