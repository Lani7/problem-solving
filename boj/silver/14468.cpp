#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;
  string str;
  cin >> str;
  vector<int> start(26, 0);
  vector<int> end(26, 0);
  int count = 0;

  for (int i = 0; i < 52; i++)
  {
    int idx = str[i] - 'A';
    if (start[idx] == 0)
      start[idx] = i + 1;
    else
      end[idx] = i + 1;
  }

  for (int i = 0; i < 26; i++)
  {
    for (int j = 0; j < 26; j++)
    {
      if (start[i] < start[j] && start[j] < end[i] && end[i] < end[j])
        count++;
    }
  }

  cout << count;
}