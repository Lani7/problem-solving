#include <iostream>
using namespace std;

int pass[4];
int my_pass[4];

void add(char c);
void remove(char c);
int check_val();

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int s, p;
  cin >> s >> p;

  string str;
  cin >> str;

  for (int i = 0; i < 4; i++)
    cin >> pass[i];

  int count = 0;

  // 첫 부분문자열 추가
  for (int i = 0; i < p; i++)
    add(str[i]);

  count += check_val();

  // 슬라이딩 윈도우
  int minus = 0;
  int plus = p;
  while (plus < s)
  {
    add(str[plus++]);
    remove(str[minus++]);
    count += check_val();
  }

  cout << count << "\n";
}

void add(char c)
{
  switch (c)
  {
  case 'A':
    my_pass[0]++;
    break;
  case 'C':
    my_pass[1]++;
    break;
  case 'G':
    my_pass[2]++;
    break;
  case 'T':
    my_pass[3]++;
    break;
  }
}

void remove(char c)
{
  switch (c)
  {
  case 'A':
    my_pass[0]--;
    break;
  case 'C':
    my_pass[1]--;
    break;
  case 'G':
    my_pass[2]--;
    break;
  case 'T':
    my_pass[3]--;
    break;
  }
}

int check_val()
{
  for (int i = 0; i < 4; i++)
  {
    if (pass[i] > my_pass[i])
      return 0;
  }
  return 1;
}