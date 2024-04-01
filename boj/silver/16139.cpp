#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
  fastio;

  string s;
  int q;
  cin >> s >> q;

  vector<vector<int>> alphabet(26, vector<int>(s.length() + 1, 0));

  for (int i = 0; i < 26; i++)
  {
    for (int j = 0; j < s.length(); j++)
    {
      int c = s[j] - 'a';
      if (c == i)
        alphabet[i][j + 1] = alphabet[i][j] + 1;
      else
        alphabet[i][j + 1] += alphabet[i][j];
    }
  }

  for (int i = 0; i < q; i++)
  {
    char c;
    int start, end;
    cin >> c >> start >> end;
    cout << alphabet[c - 'a'][end + 1] - alphabet[c - 'a'][start] << "\n";
  }
}