#include <iostream>
int main()
{

    std::string item1, item2, item3;
    float price1 = 0;
    float price2 = 0;
    float price3 = 0;
    int choice;
    float balance;
    bool run = true;
    char confirm;
    float sum_price;
    float change;

    std::cout << "\n ---CASHIER SYSTEM--- \n";
    std::cout << std::endl;
    std::cout << "Please insert your balance: ";
    std::cin >> balance;
    std::cout << std::endl;

    do
    {
        std::cout << "1. Select and Pay Item" << std::endl;
        std::cout << "2. Exit" << std::endl;
        std::cout << std::endl;
        std::cout << "Input your choice: ";
        std::cin >> choice;
        std::cout << std::endl;

        switch (choice)
        {

        case 1:

            std::cout << "Enter the name of your first item you picked: ";
            std::cin >> item1;
            std::cout << "Enter the price: ";
            std::cin >> price1;
            std::cout << std::endl;

            std::cout << "Enter the name of your second item you picked: ";
            std::cin >> item2;
            std::cout << "Enter the price: ";
            std::cin >> price2;
            std::cout << std::endl;

            std::cout << "Enter the name of your third item you picked: ";
            std::cin >> item3;
            std::cout << "Enter the price: ";
            std::cin >> price3;
            std::cout << std::endl;

            sum_price = price1 + price2 + price3;
            change = balance - sum_price;

            if (balance >= sum_price)
            {

                std::cout << "Great! The total price of your item is: " << sum_price << std::endl;
                std::cout << "The total change you'll receive is: " << change;
                std::cout << std::endl;
                balance -= sum_price;
                std::cout << "Your total balance now is: " << balance << std::endl;
                std::cout << std::endl;
            }
            else
            {

                std::cout << "Oops, We think you don't have a sufficient balance. Add your balance first." << std::endl;
                std::cout << "Are you gonna add some balance to your account? (y/n)? ";
                std::cin >> confirm;
                std::cout << std::endl;

                if (confirm == 'y')
                {

                    float add_balance;
                    std::cout << "Add balance to your account: ";
                    std::cin >> add_balance;
                    balance += add_balance;
                    std::cout << "Your balance now is: " << balance;
                    std::cout << std::endl;
                }
            }
            break;

        case 2:
            std::cout << "Exiting to the system..." << std::endl;
            run = false;
            break;

        default:
            std::cout << "Invalid selection. Please try again.\n"
                      << std::endl;
            std::cout << std::endl;
            break;
        }

    } while (run);
    return 0;
}