/* analyze only
#include <iostream>

int main()
{

    bool diff(int *x, int *y)
    {
        for (int i = 0; i < y.length; i++)
        {
            if (search(x, y[i]) != -1)
            {
                return false;
            }
        }
        return true;
    }
    return 0;
}
*/