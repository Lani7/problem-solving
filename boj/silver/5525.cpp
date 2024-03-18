#include <iostream>
#include <string>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;

  int n, m;
  string s;
  cin >> n >> m >> s;

  // 부분 문자열 만들기
  string p;
  p.append("I");
  for (int i = 0; i < n; i++)
    p.append("OI");

  int count = 0;

  int skip[p.length() + 1];

  int tt = 1;
  int pp = 0;
  skip[tt] = 0;

  // 건너뛰기 표 만들기
  while (tt != p.length())
  {
    if (p[tt] == p[pp])
      skip[++tt] = ++pp;
    else if (pp == 0)
      skip[++tt] = pp;
    else
      pp = skip[pp];
  }

  // 검색
  tt = 0;
  pp = 0;
  while (tt < s.length())
  {
    while (tt != s.length() && pp != p.length())
    {
      if (s[tt] == p[pp])
      {
        tt++;
        pp++;
      }
      else if (pp == 0)
        tt++;
      else
        pp = skip[pp];
    }

    if (pp == p.length())
    {
      count++;
      pp = skip[pp];
    }
  }

  cout << count << "\n";
}