#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <numeric>
#include "students_vacc.h"

int main()
{
    // Generate a Student to search
    auto p = generate_random_Student(1000);
    search_test(1000, p);
    search_test(10000, p);
    search_test(100000, p);
    return 0;
}

/*
//supplementary #1

bool Unique(const std::vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] == A[j]) return false;
        }
    }
    return true;
}

void test_unique(int size) {
    std::vector<int> A(size);
    for(int i = 0; i < size; i++) A[i] = i;

    auto begin = std::chrono::steady_clock::now();
    Unique(A);
    auto end = std::chrono::steady_clock::now();

    std::cout << "N = " << size << " | Time: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()
              << " microseconds\n";
}

//Supplementary #2

long long rpower(long long x, int n) {
    if (n == 0) return 1;
    return x * rpower(x, n - 1);
}

long long brpower(long long x, int n) {
    if (n == 0) return 1;
    if (n % 2 != 0) { // odd
        long long y = brpower(x, (n - 1) / 2);
        return x * y * y;
    } else { // even
        long long y = brpower(x, n / 2);
        return y * y;
    }
}

void test_powers(int n) {
    long long x = 1; // Base 1 to avoid integer overflow, focusing purely on call stack time

    auto begin1 = std::chrono::steady_clock::now();
    rpower(x, n);
    auto end1 = std::chrono::steady_clock::now();

    auto begin2 = std::chrono::steady_clock::now();
    brpower(x, n);
    auto end2 = std::chrono::steady_clock::now();

    std::cout << "N = " << n << "\n";
    std::cout << "rpower time:  " << std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1).count() << " ns\n";
    std::cout << "brpower time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2).count() << " ns\n\n";
}

int main() {
    test_unique(1000);
    test_unique(2000);
    test_unique(4000);

    test_powers(67);
    test_powers(420);
    test_powers(1000);
    return 0;
}
*/