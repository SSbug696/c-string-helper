# Example

#### Replace
    
    string  str =  "This text is a bit strange! Yeah!";
    string target = "!";
    string sep = "?!";
    StringHelper sh(str);
    sh.replace(sep, target);
    
    >> Output: This text is a bit strange?! Yeah?!

#### Remove
    
    string  str =  "This text is a bit strange! Yeah!";
    StringHelper sh(str);
    sh.remove(" Yeah!");
    
    >> Output: This text is a bit strange!
    
#### Reverse
    string  str =  "This text is a bit strange! Yeah!";
    StringHelper sh(str);
    sh->reverse();

#### Set sub-string
    string  str =  "This text is a bit strange! Yeah!";
    StringHelper sh(str);
    string sub_string = "Some text ";
    // Set in begin
    sh.set(sub_string, 0);

    >> Output: Some text This text is a bit strange! Yeah!
    
#### Find and wrap sub-string
    string  str =  "This text is a bit strange! Yeah!";
    StringHelper sh(str);
    sh.wrap("text", "<<", ">>");

    >> Output: This <<text>> is a bit strange! Yeah!