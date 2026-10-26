#include <iostream>
#include <cstring>

const int M = 4;
const int N = 4;
const int maxC = 100;

int matrix[M][N] = {
    {4, 7, 1, 6},
    {6, 7, 3, 9},
    {3, 8, 1, 2},
    {7, 1, 7, 3}
};

int memo[M][N][maxC + 1];

int countPaths(int i, int j, int cost)
{
    if (i >= M || j >= N) return 0; // outside the matrix
    if (cost < matrix[i][j]) return 0; // cost exceeded
    if (memo[i][j][cost] != -1)
        return memo[i][j][cost]; // we have solved it already
    cost -= matrix[i][j]; // subtract current cell cost
    if (i == M - 1 && j == N - 1)
        return (cost == 0) ? 1 : 0; // destination cell
    int r = countPaths(i + 1, j, cost); // move down
    r += countPaths(i, j + 1, cost); // move right
    memo[i][j][cost + matrix[i][j]] = r; // saving the result

    return r;
}

int main()
{
    std::memset(memo, -1, sizeof(memo));

    int cost = 27;

    std::cout << "Given Cost: " << cost << '\n';
    std::cout << "Number of Paths: "<< countPaths(0, 0, cost) << '\n';

    return 0;
}