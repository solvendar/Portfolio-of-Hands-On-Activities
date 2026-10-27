#include <iostream>
int main()
{

    int choice;
    bool run = true;

    do
    {
        std::cout << "1. Compute total and Average Grade on Quiz " << std::endl;
        std::cout << "2. Exit" << std::endl;
        std::cout << std::endl;
        std::cout << "Input your choice: ";
        std::cin >> choice;

        switch (choice)
        {

        case 1:
        {

            int q1, q2, q3;

            std::cout << "Type your score on Quiz 1 here: ";
            std::cin >> q1;
            std::cout << std::endl;

            std::cout << "Type your score on Quiz 2 here: ";
            std::cin >> q2;
            std::cout << std::endl;

            std::cout << "Type your score on Quiz 3 here: ";
            std::cin >> q3;
            std::cout << std::endl;

            int sum = q1 + q2 + q3;
            float average = sum / 3.0;

            std::cout << "Your total grade to your each Quiz are: " << sum << std::endl;
            std::cout << std::endl;
            std::cout << "Your total average is " << average << "% " << "Well done." << std::endl;
            std::cout << std::endl;
        }
        break;

        case 2:
            std::cout << "Thank you! Come back next time. Exiting...";
            run = false;
            break;

        default:
            std::cout << "Error, Please choose again." << std::endl;
            std::cout << std::endl;
            break;
        }
    } while (run);
    return 0;
}