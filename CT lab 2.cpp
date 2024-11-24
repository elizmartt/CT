#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cassert>
#include <string>
#include <unordered_map>

class SameNumbers {
private:
    std::vector<std::string> vec;
    int n;
    int duplicateCount = 0;

public:
    SameNumbers(int size) : n(size) {
        vec.resize(n);
        std::srand(static_cast<unsigned>(std::time(0)));
    }

    void generateNumbers() {
        for (int i = 0; i < n; i++) {
            vec[i] = std::to_string(std::rand() % 10);
        }
    }

    void printNumbers() const {
        std::cout << "Random numbers in the vector: ";
        for (const auto& num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    void assertHasDuplicates() const {
        std::unordered_map<std::string, int> freqMap;

        for (const auto& num : vec) {
            freqMap[num]++;
        }

        bool hasDuplicates = true;
        for (const auto& pair : freqMap) {
            if (pair.second > 1) {
                hasDuplicates = false;
                break;
            }
        }

        assert(hasDuplicates && "The vector does not contain duplicates.");
    }
    void findAndReplaceDuplicates() {
        std::unordered_map<std::string, int> freqMap;
        std::sort(vec.begin(), vec.end());

        for (const auto& num : vec) {
            freqMap[num]++;
        }

        std::cout << "Sorted numbers in the vector: ";
        for (const auto& num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        for (int i = 0; i < n; i++) {
            if (freqMap[vec[i]] > 1) {
                freqMap[vec[i]]--;
                if (freqMap[vec[i]] >= 1) {
                    vec[i] = "_";
                    duplicateCount++;
                }
            }
        }

        std::stable_sort(vec.begin(), vec.end(), [](const std::string& a, const std::string& b) {
            return a != "_" && b == "_";
            });

        std::cout << "Final vector: ";
        for (const auto& num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        std::cout << "Number of duplicates: " << duplicateCount << std::endl;

        assert(n == vec.size() && "The size should be the same");
    }
};

int main() {
    int n;

    std::cout << "Input number n: ";
    std::cin >> n;

    assert(n > 0 && "Input size n should be greater than 0.");

    SameNumbers myVec(n);

    myVec.generateNumbers();
    myVec.printNumbers();


    myVec.assertHasDuplicates();

    myVec.findAndReplaceDuplicates();

    return 0;
}

