#include <iostream>
#include <fstream>
#include <string>
#include "Hashtable.h"
#include "Filename.h"
#include <cctype> 

// Reads In File & Returns As Lines
bool getText(std::ifstream& file) { 
	bool isAlphabetic = false; 

	std::string fileLine; 

	std::getline(file, fileLine); 

	for (size_t i = 0; i < fileLine.length(); i++) {
		if (std::isalpha(i)) {
			isAlphabetic = true;
			break;
		}
	}
  
	return (isAlphabetic);
}

int main()
{
// Run Program Again
  char repeatanswer;
  
// Greeting Prompt
    std::string name;
    std::string beginanswer;
std::string optionanswer;
    std::cout << "What's your name?" << std::endl;
    std::cin >> name;
    do{
    std::cout << "Welcome " << name << ". " << "This program is designed to encrypt any sentence using a hashtable and a cipher file provided. It's also designed to decrypt any sentence that is written in code back to an english sentence. Would you like to continue? (y/n)" << std::endl;
    std::cin >> beginanswer;
    if (beginanswer == "y" || beginanswer == "Y"){
      std::cout << "\nGreat! Let's continue.\n" << std::endl;
    }
    if (beginanswer == "n" || beginanswer == "N"){
      std::cout << "Quiting Program." << std::endl;
      return 0;
    }

// Open Files
    std::ifstream in;
    std::ifstream in2;
    std::ifstream in3; 
    print(in, in2, in3);
    std::cout << "\n";

// Prints Encrypted File
    std::cout << "Encrypted: ";
    HashTable file = encode(in, in2, in3);
    file.clearHash();

// Close Files
      in.close();
      in2.close();
      in3.close();
      
// Try Again Prompt
std::cout << "Would you like to try again? (y/n)" << std::endl;
  std::cin >> repeatanswer;
    }
    while (repeatanswer == 'y' || repeatanswer == 'Y');
      std::cout << "Thank you for using my program! Goodbye." << std::endl;

    return 0;
}

