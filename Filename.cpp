#include <iostream>
#include <string>
#include <fstream>
#include "Filename.h"

std::string optionanswer;

void print(std::ifstream& in, std::ifstream& in2, std::ifstream& in3) {

  std::string inputFile1 = "cipher.txt";
  std::string inputFile2 = "english.txt"; 
  std::string inputFile3 = "code.txt";

 // Option Menu
  std::string optionanswer;
  std::cout << "Which option would you like to choose? (1/2)" << std::endl;
  std::cout << "Option 1: Encrypting A File (1)" << std::endl;
  std::cout << "Option 2: Decrypting A File (2)" << std::endl;
  std::cin >> optionanswer;
  std::string line;

// Option 1
  if (optionanswer == "1") {
  
        std::cout << "Original File: ";
        std::ifstream inputFile2 ("english.txt");
        while (std::getline(inputFile2,line)){
          std::cout << line << std::endl;
        }
    
    inputFile1 = "cipher.txt";
  }

// Opens Files
  in.open(inputFile1);
  in2.open(inputFile2);
  in3.open(inputFile3);


// Option 2
    if (optionanswer == "2") {

      inputFile3 = "code.txt";
      inputFile1 = "cipher.txt";
      std::cout << "Decrypted File: ";
        std::ifstream inputFile2 ("english.txt");
        while (std::getline(inputFile2,line)){
          std::cout << line << std::endl;
        }
    }

    in.close();  
    in2.close();
    in3.close();
    in.open(inputFile1);
    in2.open(inputFile2);
    in3.open(inputFile3);

  optionanswer.clear();
  
  }

