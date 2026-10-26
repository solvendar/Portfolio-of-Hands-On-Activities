#include <iostream>
#include <cstdlib> // for generating random integers
#include <string>
#include "supp.h"

const int MAX_SIZE = 100;

void displayArr(int arr[]);
void countVotes(int arr[], int votes[]);

int main()
{
    int unsortedArr[MAX_SIZE];
    std::string candidates[5] = {
        "Candidate 1: Bo Dalton Capistrano",
        "Candidate 2: Cornelius Raymon Agustin",
        "Candidate 3: Deja Jayla Bañaga",
        "Candidate 4: Laila Brielle Yabut",
        "Candidate 5: Franklin Relano Castro"};

    // predetermined seed to make random numbers
    srand(1024);

    // generate a random votes with the range of 1 to 5
    for (int i = 0; i < MAX_SIZE; i++)
    {
        unsortedArr[i] = rand() % 5 + 1;
    }

    std::cout << "unsortedArr: \n";
    displayArr(unsortedArr);

    std::cout << "\nSelection sort: \n";
    selectionSort(unsortedArr, MAX_SIZE);
    displayArr(unsortedArr);

    int votes[5] = {};
    countVotes(unsortedArr, votes); // to count how many votes of each the candidate got

    std::cout << "\nVote Results: \n";
    for (int i = 0; i < 5; i++)
    {
        std::cout << candidates[i] << ": " << votes[i] << " votes\n";
    }

    int winner = 0;
    for (int i = 1; i < 5; i++)
    {
        if (votes[i] > votes[winner])
        {
            winner = i; // update the winner index if another candidate has more votes
        }
    }

    std::cout << "\nWinner: " << candidates[winner] << ", with: " << votes[winner] << " votes\n";
    return 0;
}

void displayArr(int arr[])
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void countVotes(int arr[], int votes[])
{
    for (int i = 0; i < 5; i++)
    {
        votes[i] = 0; // to clear the vote counts and reset it to zero
    }
    for (int i = 0; i < MAX_SIZE; i++)
    {
        votes[arr[i] - 1]++; // increment a vote to the chosen candidate
    }
}