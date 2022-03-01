#include <bits/stdc++.h>

using namespace std;

bool isKey(char c)
{
  const string lower = "rgb";
  return lower.find(c) != string::npos;
}

bool solve(string s)
{
  vector<char> keys;
  vector<char> doors;
  for (int i = 0; i < s.size(); i++)
  {
    if (isKey(s[i]))
    {
      keys.push_back(toupper(s[i]));
      continue;
    }
    if (find(keys.begin(), keys.end(), s[i]) != keys.end())
    {
      continue;
    }
    return false;
  }
  return true;
}

int main()
{

  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    if (solve(s))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}
