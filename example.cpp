#include <iostream>
#include <string>
#include "StringHelper.h"

using namespace std;

bool checkSimbols(char c)
{
  char arr[] = {'e', 'f', 'k', 'm', 's', 'x', '1', '2'};
  bool flag = false;
  for (int i = 0; i <= sizeof(arr) / sizeof(char) && !flag; i++)
  {
    if (arr[i] == c)
      flag = true;
  }
  return flag;
}

int main()
{
  string str = "1This text is a bit strange! Yeah!2   ";
  string sep = "!";
  string temp = "?!";
  StringHelper ss(str);

  cout << "before trim " << str.length() << " symbols length" << endl;
  ss.lr_trim();
  cout << str << endl;
  cout << "after trim " << str.length() << " symbols length. Left and right backspaces is removed" << endl;

  string sset = " Some message: ";
  ss.set(sset, 0);
  cout << str << endl;

  ss.wrap("message", "<<", ">>", 0, 0);
  cout << str << endl;

  ss.replace(temp, sep, 0, 0)->reverse(); // can do ss.replace(temp, sep, 0, 0)
  cout << str << endl;

  ss.reverse(checkSimbols);
  cout << str << endl;

  ss.reverse();
  cout << str << endl;

  return 0;
}
