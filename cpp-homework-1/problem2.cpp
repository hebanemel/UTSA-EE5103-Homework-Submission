#include <iostream>     // Header: input/output tools
#include <string>
int main()
{
  std::string word;
  std::cout << "Write a word: ";
  std::cin >> word;

  int length = word.length();
  std::cout << "The word length is " << length << std::endl;

  if (length <= 4) {
    std::cout << "Your word is short" << std::endl;
  }
  else if (length > 4 && length < 9 ) {
    std::cout << "Your word is medium" << std::endl;
  }
  else if (length >= 9) {
    std::cout << "Your word is long" << std::endl;
  }

  //Alphabetical comparison with the word "code"
  std::string code = "code";
  if (word < code){
    std::cout << "Your word is alphabetically before code";
  }
  if (word > code){
    std::cout << "Your word is alphabetically after code";
  }

    return 0;
}