#include <iostream>
#include <vector>
#include <cstdlib>  
#include <ctime>    
#include <algorithm>  // For std::find

int main() {
    int n, m;

    // Input n
    std::cout << "Input number n: ";
    std::cin >> n;

    // Initialize the vector and a boolean vector for tracking used elements
    std::vector<int> vec(n);
    std::vector<bool> used(n, false);  // To track which elements have been used
    std::vector<int> vec2;  // To store the indices of the pairs

    // Seed the random number generator
    std::srand(std::time(0));

    // Fill the vector with random numbers
    for (int i = 0; i < n; i++) {
        vec[i] = std::rand() % 20 - 10;  // Random numbers between -10 and 9
    }

    // Output the random numbers
    std::cout << "Random numbers in the vector: ";
    for (int i = 0; i < n; ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // Input the target sum m
    std::cout << "Input number m: ";
    std::cin >> m;

    // Find pairs of numbers whose sum is m
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;  // Skip if the current element is already used

        int K = m - vec[i];

        // Search for K in the vector and ensure it hasn't been used
        auto it = std::find(vec.begin(), vec.end(), K);
        if (it != vec.end()) {
            int j = std::distance(vec.begin(), it);
            if (i != j && !used[j]) {  // Ensure i and j are different and j is not used
                vec2.push_back(i);  // Store the index of the first element
                vec2.push_back(j);  // Store the index of the second element

                // Mark both elements as used
                used[i] = true;
                used[j] = true;
            }
        }
    }

    // Output the indices of the pairs
    if (!vec2.empty()) {
        std::cout << "Indices of pairs that sum to " << m << ": ";
        for (size_t i = 0; i < vec2.size(); i += 2) {
            std::cout << "(" << vec2[i] << ", " << vec2[i + 1] << ") ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "No pairs found with the given sum." << std::endl;
    }

    return 0;
}
