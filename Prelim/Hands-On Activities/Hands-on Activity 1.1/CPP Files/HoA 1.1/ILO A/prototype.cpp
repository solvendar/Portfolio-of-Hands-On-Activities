#include <iostream>
// Create a function that will take two numbers and display the sum.
int SumofTwoNum(int kNum, int vNum);

// Create a function that will return whether variable A is greater than variable B.
int greater(int varK, int varV);

// Create a function that will take two Boolean values and display the result of all logical operations then
// return true if it was a success.
bool logic(bool valK, bool valV);

int main()
{

    std::cout << "The sum of num is: " << SumofTwoNum(140, 858) << std::endl;

    if (greater(140, 858) == 1)
    {
        std::cout << "Variable A is greater than Variable B" << std::endl;
    }
    else
    {
        std::cout << "Variable B is greater than Variable A" << std::endl;
    }

    if (logic(true, true) == true)
    {
        std::cout << "Successful!";
        return true;
    }
    return 0;
}

int SumofTwoNum(int kNum, int vNum)
{
    int sum = SumofTwoNum(kNum, vNum);
    return kNum + vNum;
}

int greater(int varK, int varV)
{

    if (varK > varV)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool logic(bool valK, bool valV)
{

    std::cout << "Logical Operators" << std::endl;
    std::cout << "valK AND valV = " << (valK && valV);
    std::cout << std::endl;
    std::cout << "valK OR valV = " << (valK || valV);
    std::cout << std::endl;
    std::cout << "NOT valK = " << (!valK);
    std::cout << std::endl;
    std::cout << "NOT valV = " << (!valV);
    std::cout << std::endl;
    return true;
}