#include <string>


std::string to_camel_case(std::string text) {
  // TODO: Your code goes here!
    int l = text.size();
	  for (int i = 0; i < l; i++) {
		  if (text[i] == '-' || text[i] == '_')
			  text[i+1] = toupper(text[i + 1]);
	  }
 
	  text.erase(std::remove(text.begin(), text.end(), '-'), text.end());
    text.erase(std::remove(text.begin(), text.end(), '_'), text.end());
	  return text;
}
