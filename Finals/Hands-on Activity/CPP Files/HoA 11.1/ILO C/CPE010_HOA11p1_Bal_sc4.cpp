#include <iostream> 
#include <chrono> 
 
// Algorithm rpower(int x, int n) 
int rpower(int x, int n) { 
    // if n == 0 return 1 
    if (n == 0) 
        return 1; 
    // else return x * rpower(x, n-1) 
    else 
        return x * rpower(x, n - 1); 
} 
 
// Algorithm brpower(int x, int n) 
int brpower(int x, int n) { 
    // if n == 0 return 1 
    if (n == 0) 
        return 1; 
    // if n is odd 
    if (n % 2 != 0) { 
        // y = brpower(x, (n-1)/2) 
        int y = brpower(x, (n - 1) / 2); 
        // return x * y * y 
        return x * y * y; 
    } 
    // if n is even 
    if (n % 2 == 0) { 
        // y = brpower(x, n/2) 
        int y = brpower(x, n / 2); 
        // return y * y 
        return y * y; 
    } 
    return 1; 
} 
 
int main() { 
    int x = 2; 
    int bestN = 2; 
    int worstN = 25; 
    int repetitions = 1000000;

    int rBestResult, rWorstResult;
    int brBestResult, brWorstResult;
 
    // Measure rpower best-case runtime 
    auto startRBest = std::chrono::steady_clock::now(); 
    for (int i = 0; i < repetitions; i++) {
        rBestResult = rpower(x, bestN);
    }
    auto endRBest = std::chrono::steady_clock::now(); 
    auto rBestTime = std::chrono::duration_cast<std::chrono::microseconds>(endRBest - startRBest).count(); 
 
    // Measure rpower worst-case runtime 
    auto startRWorst = std::chrono::steady_clock::now(); 
    for (int i = 0; i < repetitions; i++) {
        rWorstResult = rpower(x, worstN);
    }
    auto endRWorst = std::chrono::steady_clock::now(); 
    auto rWorstTime = std::chrono::duration_cast<std::chrono::microseconds>(endRWorst - startRWorst).count(); 
 
    // Measure brpower best-case runtime 
    auto startBRBest = std::chrono::steady_clock::now(); 
    for (int i = 0; i < repetitions; i++) {
        brBestResult = brpower(x, bestN);
    }
    auto endBRBest = std::chrono::steady_clock::now(); 
    auto brBestTime = std::chrono::duration_cast<std::chrono::microseconds>(endBRBest - startBRBest).count(); 
 
    // Measure brpower worst-case runtime 
    auto startBRWorst = std::chrono::steady_clock::now(); 
    for (int i = 0; i < repetitions; i++) {
        brWorstResult = brpower(x, worstN);
    }
    auto endBRWorst = std::chrono::steady_clock::now(); 
    auto brWorstTime = std::chrono::duration_cast<std::chrono::microseconds>(endBRWorst - startBRWorst).count(); 
 
    // Display rpower results 
    std::cout << "| RPOWER |" << std::endl; 
    std::cout << "\nBEST CASE" << std::endl; 
    std::cout << "Exponent: " << bestN << std::endl; 
    std::cout << "Result: " << rBestResult << std::endl; 
    std::cout << "Runtime: " << rBestTime << " microseconds" << std::endl; 
 
    std::cout << "\nWORST CASE" << std::endl; 
    std::cout << "Exponent: " << worstN << std::endl; 
    std::cout << "Result: " << rWorstResult << std::endl; 
    std::cout << "Runtime: " << rWorstTime << " microseconds" << std::endl; 
 
    // Display brpower results 
    std::cout << "\n| BRPOWER |" << std::endl; 
 
    std::cout << "\nBEST CASE" << std::endl; 
    std::cout << "Exponent: " << bestN << std::endl; 
    std::cout << "Result: " << brBestResult << std::endl; 
    std::cout << "Runtime: " << brBestTime << " microseconds" << std::endl; 
 
    std::cout << "\nWORST CASE" << std::endl; 
    std::cout << "Exponent: " << worstN << std::endl; 
    std::cout << "Result: " << brWorstResult << std::endl; 
    std::cout << "Runtime: " << brWorstTime << " microseconds" << std::endl; 
 
    return 0; 
}

