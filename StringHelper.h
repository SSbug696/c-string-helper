#include <string>
using namespace std;

class StringHelper {
  string & s;

public:
  StringHelper(string & str): s(str){}
  void remove(const string);
  string & get();
  StringHelper * set(const string &, int);
  StringHelper * wrap(const string &, const string &, const string &, int, int);
  StringHelper * replace(const string &, const string &, int, int);
  StringHelper * reverse(bool (*)(char));
};