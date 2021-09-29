/*
    Name: Bruce Lynch
    Student Number: *********
    Date Completed: 09/26/2021
    
    Brief: This program checks the validity of a user input word ladder.
    
    Capitalization of characters does not affect the comparison of two words. A user enters in one word
    at a time into the terminal. Once the list is completed, the user enters ctrl+D and the program will
    indicate if the word ladder is valid. If the word ladder is invalid, the program will indicate the
    first pair of words that do not meet word ladder criteria.
*/

#include <iostream>
#include <vector>
#include <string>
//g++ -std=c++17 -Wall -o ladder ladder.cpp

// This function bool check() is responisible for checking the validity of the word ladder.
bool check(std::vector<std::string> ladder, std::vector<std::string> lower_ladder) {
    unsigned int counter {1}; // keeps track of index of the original word ladder.
    bool validity; // assists check() in returning true or false for the appropriate result.
    
    while(counter < ladder.size()) {
        int strikes {0};
        /* The following two strings assist in readability in the program - they online apply to the lowercase
            version of the original word ladder. */
        std::string current_word {lower_ladder.at(counter)};
        std::string previous_word {lower_ladder.at(counter - 1)};
        
        // Checks length of current word and previous word
        if(previous_word.length() == current_word.length()) {
            int index {0};
            for(char i : (previous_word)) {
                char j {current_word.at(index)};
                index++;
                if(i != j) {
                    strikes++; // Max of 1 strike for unmatched chars discerns if two words are too different.
                }
            }
        } else if (previous_word.length() != current_word.length()) {
            // If two words are of different length, we need not check any further in the ladder.
            std::cout << "Error: Invalid Transition [" << ladder.at(counter - 1);
            std::cout << "] -> [" << ladder.at(counter) << "]"<< std::endl;
            validity = false;
            break;
        }
        if((strikes > 1) || (strikes == 0)) {
            // 0 strikes means two identical words in consecutive order.
            std::cout << "Error: Invalid Transition [" << ladder.at(counter - 1);
            std::cout << "] -> [" << ladder.at(counter) << "]"<< std::endl;
            validity = false;
            break;
        }
        counter++;
    }
    
    if(validity == false) {
        return false;
    } else {
        return true;
    }
}

// int main() is for inputting purposes and prints the appropriate statement if the word ladder is valid.
int main() {
    std::string word {};
    std::vector< std::string > lower_ladder {};
    std::vector< std::string > ladder {};
    
    while (std::cin >> word) {
        std::string lower_word {};
        for( char i : word ) {
            char lowercase = std::tolower(i); // Converts chars from input into lower case chars.
            lower_word.push_back(lowercase); // Places lower case chars in a new string.
        }
        
        ladder.push_back(word); // Stores original input array
        lower_ladder.push_back(lower_word); // Stores original input array but in lower case
    }
    if (check(ladder, lower_ladder) == true) {
        std::cout << "Word ladder is valid." << std::endl;
        for(std::string i : ladder) {
            std::cout << i << std::endl;
        }
    }
    return 0;
}
