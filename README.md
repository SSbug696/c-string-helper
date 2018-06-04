# Example

  string str = "This   text is a bit strange! Yeah!   ";
  string sep = "!";
  string temp = "?!";
  StringHelper ss(str);
  

#### Trim (remove backspaces from left and right border)
  ss.lr_trim();

  >> Output: before trim 38 symbols length
  >> Output: This   text is a bit strange! Yeah!
  >> Output: after trim 35 symbols length. Left and right backspaces is removed

#### Inject substring
  string sset = " Some message: ";
  ss.set(sset, 0);

  >> Output: Some message: 1This text is a bit strange! Yeah!2

#### Find and wrap sub-string
  ss.wrap("message", "<<", ">>", 0, 0);

  >> Output: Some <<<message>>>: 1This text is a bit strange! Yeah!2

#### Replace which substring and reverse(optional)
  ss.replace(temp, sep, 0, 0)->reverse(); // can do ss.replace(temp, sep, 0, 0)
  
  >> Output: 2!haeY !egnarts tib a si txet sihT1 :>>egassem<< emoS 

#### Reverse string(full reverse with some sort of filter function for some symbols), step 1
  ss.reverse(checkSimbols);

  >> Output: s!haeY !1gnarts tib a si txet sihTe :>>ega2sem<< emoS 

#### Simple reverse, step 2
  ss.reverse();

  >> Output: Some <<mes2age>>: eThis text is a bit strang1! Yeah!s

