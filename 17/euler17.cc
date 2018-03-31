#include <iostream>
#include <map>
#include <string>

std::string numberToWords(int number, std::map<int, std::string> baseCases) {
  if (baseCases.count(number)) {
    return baseCases[number];
  }
  else if (number < 100) {
    int tens = (number / 10) * 10;
    int ones = number - tens;
    return numberToWords(tens, baseCases) + "" +
           numberToWords(ones, baseCases);
  }
  else if (number < 1000) {
    int hundreds = (number / 100);
    int numberNoHundreds = number - (hundreds * 100);
    if (numberNoHundreds == 0)
    {
      return numberToWords(hundreds, baseCases) + "hundred";
    }
    else {
      return numberToWords(hundreds, baseCases) + "hundredand" +
             numberToWords(numberNoHundreds, baseCases);
    }
  }
  else {
    return "???";
  }
}

int main() {
  std::map<int, std::string> baseCases;
  baseCases[0] = "";
  baseCases[1] = "one";
  baseCases[2] = "two";
  baseCases[3] = "three";
  baseCases[4] = "four";
  baseCases[5] = "five";
  baseCases[6] = "six";
  baseCases[7] = "seven";
  baseCases[8] = "eight";
  baseCases[9] = "nine";
  baseCases[10] = "ten";
  baseCases[11] = "eleven";
  baseCases[12] = "twelve";
  baseCases[13] = "thirteen";
  baseCases[14] = "fourteen";
  baseCases[15] = "fifteen";
  baseCases[16] = "sixteen";
  baseCases[17] = "seventeen";
  baseCases[18] = "eighteen";
  baseCases[19] = "nineteen";
  baseCases[20] = "twenty";
  baseCases[30] = "thirty";
  baseCases[40] = "forty";
  baseCases[50] = "fifty";
  baseCases[60] = "sixty";
  baseCases[70] = "seventy";
  baseCases[80] = "eighty";
  baseCases[90] = "ninety";
  baseCases[1000] = "onethousand";

  int charCount = 0;
  for (int i = 1; i <= 1000; i++) {
    std::string currString = numberToWords(i, baseCases);
    charCount += currString.length();
    std::cout << i << ": " << numberToWords(i, baseCases) << std::endl;
  }

  std::cout<<"CharCount: "<<charCount<<std::endl;
}
