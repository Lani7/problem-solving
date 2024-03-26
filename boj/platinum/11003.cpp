#include <iostream>
#include <deque>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;

  int n, l;
  cin >> n >> l;

  deque<pair<int, int>> dq;

  for (int i = 1; i <= n; i++)
  {
    int num;
    cin >> num;

    // 덱의 마지막에서 num보다 큰 값은 덱에서 제거
    while (!dq.empty() && dq.back().second > num)
      dq.pop_back();

    // 덱의 마지막 위치에 저장(인덱스, 숫자)
    dq.push_back(make_pair(i, num));

    // 덱의 처음에서 슬라이드윈도우 범위를 벗어난 값을 덱에서 제거
    while (dq.front().first <= i - l)
      dq.pop_front();

    // 덱의 첫번째 데이터 출력
    cout << dq.front().second << " ";
  }
}