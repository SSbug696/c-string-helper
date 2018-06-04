#include "StringHelper.h"

// Remove sub-string
void StringHelper::remove(const std::string val)
{
  int before_str = s.find(val);
  s.erase(before_str, val.size());
}

std::string &StringHelper::get()
{
  return s;
}

StringHelper *StringHelper::set(const std::string &s_str, size_t pos)
{
  int sz = s.size();
  if (pos > sz)
    pos = sz;

  s.insert(pos, s_str);
  return this;
}

StringHelper *StringHelper::wrap(const std::string &separator, const std::string &before, const std::string &after, size_t begin = 0, size_t end = 0)
{
  bool flag = true, changed = false;

  size_t tmp_contain = 0, tmp_it = 0,
         sep_sz = separator.size(),
         before_sz = before.size(),
         after_sz = after.size();

  if (end <= 0 || end > s.size())
    end = s.size();

  if (begin >= end)
  {
    begin = 0;
  }

  // Cut the sub - string
  std::string t_str = s.substr(begin, end - begin);
  // Remove substr from source string
  s.erase(begin, end - begin);

  while ((tmp_contain = t_str.find(separator, tmp_it)) != std::string::npos)
  {
    tmp_it = tmp_contain + 1 + sep_sz;
    // Size sub-string
    int sz_str = t_str.size();
    // Define the difference in size between separate string and template string
    std::string word = t_str.substr(tmp_contain, sep_sz);
    word.insert(0, before);
    word.insert(word.size(), after);
    // Remove the template-symbol
    t_str.erase(tmp_contain, sep_sz);

    int sz_source_string = word.size();
    sz_str = sz_str + (sz_source_string - sep_sz);
    // Change original size
    t_str.resize(sz_str);
    t_str.insert(tmp_contain, word);
  }

  s.insert(begin, t_str);
  return this;
}

StringHelper *StringHelper::replace(const std::string &temp, const std::string &separator, size_t begin = 0, size_t end = 0)
{
  bool flag = true, changed = false;

  size_t tmp_contain = 0, tmp_it = 0,
         sep_sz = separator.size(),
         tmp_size = temp.size();

  if (end > s.size())
    end = s.size();

  if (begin >= end)
    begin = 0;

  std::string t_str = s.substr(begin, end - begin);
  s.erase(begin, end - begin);

  while ((tmp_contain = t_str.find(separator, tmp_it)) != std::string::npos)
  {
    tmp_it = tmp_contain + 1 + sep_sz;
    int sz_str = t_str.size();
    t_str.erase(tmp_contain, sep_sz);
    sz_str = sz_str + (tmp_size - sep_sz);
    t_str.resize(sz_str);
    t_str.insert(tmp_contain, temp);
  }

  // Set updated string
  s.insert(begin, t_str);
  return this;
}

StringHelper *StringHelper::lr_trim()
{
  const unsigned int SZ = s.size();

  if (!SZ)
  {
    return this;
  }

  unsigned int begin_iter = 0,
               end_iter = SZ - 1,
               l_offset = 0,
               r_offset = 0,
               llock = 0,
               rlock = 0;

  for (; begin_iter < end_iter && (!rlock || !llock); begin_iter++, end_iter--)
  {
    if (s[begin_iter] == ' ' && !llock)
    {
      l_offset++;
    }
    else
      llock = 1;

    if (s[end_iter] == ' ' && !rlock)
    {
      r_offset++;
    }
    else
      rlock = 1;
  }

  s = s.substr(l_offset, SZ - l_offset - r_offset);
  return this;
}

StringHelper *StringHelper::reverse()
{
  int begin_iter = 0,
      end_iter = s.size() - 1;

  if (s.size() == 0)
  {
    return this;
  }

  for (; begin_iter < end_iter; begin_iter++, end_iter--)
  {
    std::swap(s[begin_iter], s[end_iter]);
  }
  return this;
}

StringHelper *StringHelper::reverse(bool (*f)(char))
{
  int begin_iter = 0,
      end_iter = s.size() - 1;
  // If determined check method. Stop change
  bool flag = (!f) ? false : true;

  if (s.size() == 0)
  {
    return this;
  }

  for (; begin_iter < end_iter; begin_iter++, end_iter--)
  {
    if (flag)
    {
      // Check through filter method. Swap if true
      if (!f(s[end_iter]) || !f(s[begin_iter]))
        continue;
    }

    std::swap(s[begin_iter], s[end_iter]);
  }
  return this;
}