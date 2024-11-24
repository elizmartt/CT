#include <iostream>
#include <string>
#include <list>
#include <utility>

class AnagramChecker {
public:
    bool AreAnagrams(const std::string& str1, const std::string& str2) {
        if (str1.length() != str2.length()) {
            return false;
        }
   
        std::list<std::pair<char, int>> charCount1;
        std::list<std::pair<char, int>> charCount2;

        for (char c : str1) {
            updateCharCount(charCount1, c);
        }

        for (char c : str2) {
            updateCharCount(charCount2, c);
        }
        bool found = false;
        for (auto& pair1 : charCount1) {
            char c = pair1.first;
            int count1 = pair1.second;

            
            for (auto& pair2 : charCount2) {
                if (pair2.first == c && pair2.second == count1) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }

        return found; 
    }

private:
    void updateCharCount(std::list<std::pair<char, int>>& charCount, char c) {
        for (auto& pair : charCount) {
            if (pair.first == c) {
                pair.second++; // Increment count if character exists
                return;
            }
        }
        // Add new character with a count of 1 if it doesn't exist
        charCount.push_back(std::make_pair(c, 1));
    }
};

int main() {
    AnagramChecker checker;
    std::string str1, str2;

    std::cout << "Enter first string: ";
    std::getline(std::cin, str1);
    std::cout << "Enter second string: ";
    std::getline(std::cin, str2);

    if (checker.AreAnagrams(str1, str2)) {
        std::cout << "The strings are anagrams." << std::endl;
    }
    else {
        std::cout << "The strings are not anagrams." << std::endl;
    }

    return 0;
}
