#include <string>
using namespace std;

class StringHelper {
  string & s;

public:

  StringHelper(string & str): s(str){}
 
  void remove(const string val) {
    // remove sub-string
    int before_str = s.find(val);
    s.erase(before_str, val.size());
  }
 
  string & get() {
    return s;
  }

  StringHelper * set(const string & s_str, int pos) {
    int sz = s.size();
    if( pos > sz || pos < 0 ) pos = sz;
    s.insert(pos, s_str);
    return this;
  }


  StringHelper * wrap(const string & separator, const string & before, const string & after, int begin = 0, int end = 0) {
    bool flag = true, changed = false;

    size_t  tmp_contain = 0, tmp_it = 0,
            sep_sz = separator.size(),
            before_sz = before.size(),
            after_sz  = after.size();

    if(end <= 0 || end > s.size()) end = s.size();
    if(begin >= end || begin < 0) {
      begin = 0;
      end   = s.size();
    }
  
    // cut the sub string
    string t_str = s.substr(begin, end - begin);
    // remove substr of source string
    s.erase(begin, end - begin);

    while( (tmp_contain = t_str.find(separator, tmp_it)) != string::npos) {
      //cout << tmp_contain << endl;
      tmp_it = tmp_contain + 1  + sep_sz;
      // size sub-string
      int sz_str = t_str.size();
      // define the difference in size between separate string and template string
      string word = t_str.substr(tmp_contain, sep_sz);
      word.insert(0, before);
      word.insert(word.size(), after);
      // remove the template-simbol
      t_str.erase(tmp_contain, sep_sz );

      int sz_source_string = word.size();
      sz_str = sz_str + ( sz_source_string - sep_sz );
      // change original size
      t_str.resize(sz_str);
      t_str.insert(tmp_contain, word);
    }
    // set updated string
    s.insert(begin, t_str);
    return this;
  }

    
  StringHelper * replace(const string & temp, const string & separator, int begin = 0, int end = 0) {
    bool flag = true, changed = false;

    size_t  tmp_contain = 0, tmp_it = 0,
            sep_sz = separator.size(),
            tmp_size = temp.size();

    if(end <= 0 || end > s.size()) end = s.size();
    if(begin >= end || begin < 0) {
      begin = 0;
      end   = s.size();
    }
  
    // cut the sub string
    string t_str = s.substr(begin, end - begin);
    // remove substr of source string
    s.erase(begin, end - begin);

    while( (tmp_contain = t_str.find(separator, tmp_it)) != string::npos) {
      //cout << tmp_contain << endl;
      tmp_it = tmp_contain + 1  + sep_sz;
      // size sub-string
      int sz_str = t_str.size();
      // remove the template-simbol
      t_str.erase(tmp_contain, sep_sz );
      // define the difference in size between separate string and template string
      sz_str = sz_str + ( tmp_size - sep_sz  );
      // change original size
      t_str.resize(sz_str);
      t_str.insert(tmp_contain, temp);
    }
    // set updated string
    s.insert(begin, t_str);
    return this;
  }


  StringHelper * reverse(bool (* f)(char) = 0) {
    int begin_iter = 0, 
        end_iter = s.size() - 1;
    // if determined check method. Stop change
    bool flag = (f == 0) ? false : true;
    if( s.size() == 0  ) {
      return this;
    } 

    for(; begin_iter < end_iter; begin_iter ++, end_iter --) {
      if(flag) {
        // check through black-list
        if( !f(s[end_iter]) || !f(s[begin_iter]) ) continue;
      }
      // replace object
      swap(s[begin_iter], s[end_iter]);
    }
    return this;
  }
};