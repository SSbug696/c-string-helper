#include <string>

using namespace std;

class StringHelper
{
  std::string &s;

public:
  StringHelper(std::string &str) : s(str) {}
  void remove(const std::string);
  string &get();
  StringHelper *set(const std::string &, size_t);
  StringHelper *wrap(const std::string &, const std::string &, const std::string &, size_t, size_t);
  StringHelper *replace(const std::string &, const std::string &, size_t, size_t);
  StringHelper *reverse(bool (*)(char));
  StringHelper *reverse();
  StringHelper *lr_trim();
};