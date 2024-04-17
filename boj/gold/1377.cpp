#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;

  int n;
  cin >> n;
  pair<int, int> a[n];
  int result = -1;

  for (int i = 0; i < n; i++)
  {
    int num;
    cin >> num;
    a[i] = make_pair(num, i);
  }

  sort(a, a + n);

  for (int i = 0; i < n; i++)
  {
    // 정렬 전 인덱스 - 정렬 후 인덱스 (swap이 발생한 내부 for문 실행 횟수) 최댓값
    result = max(result, a[i].second - i);
  }
  // swap이 발생하지 않은 1회 더하기
  cout << result + 1;
}