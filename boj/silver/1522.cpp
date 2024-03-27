#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;

  string str;
  cin >> str;
  int bcnt = 0;           // 알파벳 b 개수
  int len = str.length(); // 문자열 길이

  for (int i = 0; i < len; i++)
  {
    if (str[i] == 'b')
      bcnt++;
  }

  int cnt = 0; // 교환 횟수
  for (int i = 0; i < bcnt; i++)
  {
    if (str[i] == 'a')
      cnt++;
  }

  int result = cnt;

  // 슬라이딩 윈도우
  for (int i = 1; i < len; i++)
  {
    // 제거 문자
    if (str[(i - 1) % len] == 'a')
      cnt--;
    // 추가 문자
    if (str[(i + bcnt - 1) % len] == 'a')
      cnt++;
    result = min(result, cnt);
  }
  cout << result;
}