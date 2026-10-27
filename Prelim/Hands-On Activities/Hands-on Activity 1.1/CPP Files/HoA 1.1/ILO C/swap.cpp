#include <iostream>

int main()
{

    int k = 867;
    int v = 101408;
    int swap;

    std::cout << "The data inside of the variable K is " << k << ", and in variable V is " << v << std::endl;

    // swapping the values of the two variables
    swap = k;
    k = v;
    v = swap;

    std::cout << "They've been swapped. The data of variable K now is " << k << ", and the data of variable V is " << v << std::endl;

    return 0;
}
