#include <iostream> // For input/output (cin, cout, getline)
#include <string>   // For using the string class
#include <sstream>  // For using stringstream to parse the string

int main() {
    std::string line;

    // 1. Get the full line of input from the user
    std::cout << "Enter a sentence to parse: ";
    std::getline(std::cin, line);

    // 2. Create a stringstream object from the input line
    std::stringstream ss(line);

    std::string word;

    // 3. Parse the stringstream
    // This loop will extract one "word" (separated by spaces) at a time
    // until there are no more words left.
    std::cout << "\nParsing the string:" << std::endl;
    while (ss >> word) {
        // 4. Print each individual word
        std::cout << word << std::endl;
    }

    return 0;
}
