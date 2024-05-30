#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;

  long Min, Max;
  cin >> Min >> Max;

  vector<bool> checked(Max - Min + 1);
  int count = 0;

  for (long i = 2; i * i <= Max; i++)
  {
    long square = i * i; // 제곱수
    long start_index = Min / square;
    // 나머지가 있을 경우 1을 더해줘서 Min보다 큰 제곱수부터 시작함
    if (Min % square != 0)
      start_index++;

    // 제곱수 표시
    for (long j = start_index; j * square <= Max; j++)
      checked[j * square - Min] = true;
  }

  // 제곱수가 아닌 수의 개수 세기
  for (int i = 0; i <= Max - Min; i++)
    if (!checked[i])
      count++;
  cout << count;
}