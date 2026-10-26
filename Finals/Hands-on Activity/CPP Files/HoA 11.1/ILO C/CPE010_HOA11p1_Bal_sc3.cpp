#include <iostream>
#include <vector>
#include <chrono>

// Algorithm Unique(A)
bool Unique(const std::vector<int>& A) {
    int n = A.size();

    // for i = 0 to n-1 do
    for (int i = 0; i < n; i++) {
        // for j = i+1 to n-1 do
        for (int j = i + 1; j < n; j++) {
            // if A[i] equals to A[j] then
            if (A[i] == A[j]) {
                // return false
                return false;
            }
        }
    }

    // return true
    return true;
}

int main() {
    int n = 5000;
    int repetitions = 100;

    // Best case: Duplicate values are found in the first comparison
    std::vector<int> bestCase(n, 1);
    bestCase[0] = 5;
    bestCase[1] = 5;

    // Worst case: All elements are unique
    std::vector<int> worstCase(n);
    for (int i = 0; i < n; i++) {
        worstCase[i] = i;
    }

    // Measure the best-case runtime
    auto startBest = std::chrono::steady_clock::now();
    bool bestResult;
    for (int i = 0; i < repetitions; i++) {
        bestResult = Unique(bestCase);
    }
    auto endBest = std::chrono::steady_clock::now();

    auto bestTime = std::chrono::duration_cast<std::chrono::microseconds>(endBest - startBest).count();

    // Measure the worst-case runtime
    auto startWorst = std::chrono::steady_clock::now();
    bool worstResult;
    for (int i = 0; i < repetitions; i++) {
        worstResult = Unique(worstCase);
    }
    auto endWorst = std::chrono::steady_clock::now();

    auto worstTime = std::chrono::duration_cast<std::chrono::microseconds>(endWorst - startWorst).count();

    // Display the results
    std::cout << "BEST CASE" << std::endl;
    std::cout << "Array size: " << n << std::endl;
    std::cout << "All elements unique: " << std::boolalpha << bestResult << std::endl;
    std::cout << "Runtime: " << bestTime << " microseconds" << std::endl;

    std::cout << "\nWORST CASE" << std::endl;
    std::cout << "Array size: " << n << std::endl;
    std::cout << "All elements unique: " << std::boolalpha << worstResult << std::endl;
    std::cout << "Runtime: " << worstTime << " microseconds" << std::endl;

    return 0;
}
