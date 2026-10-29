#include <iostream>
#include <string>
#include "queueArrsupp.h"

int main()
{

    Printer printer(10);
    int choice;
    Job tail; // declaring the "tail" so it can be used in case in switch

    do
    {

        std::cout << "\n============================\n";
        std::cout << "          PRINTER\n";
        std::cout << "============================\n";
        std::cout << "1. Add Print for Job\n";
        std::cout << "2. Process all Job\n";
        std::cout << "3. Remove Print Job\n";
        std::cout << "4. Display Print Job\n";
        std::cout << "5. Clear All\n";
        std::cout << "6. Exit\n"
                  << std::endl;
        std::cout << " Input your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Job ID:";
            std::cin >> tail.ID;
            std::cout << "Username: ";
            std::cin >> tail.username;
            std::cout << "Pages: ";
            std::cin >> tail.number_of_pages;

            printer.addJob(tail);
            break;

        case 2:
            printer.JobProcess();
            break;

        case 3:
            tail = printer.RemoveJob();
            break;

        case 4:
            printer.DisplayJob();
            break;

        case 5:
            printer.Clear();
            std::cout << "All print Jobs got cleared";
            break;

        case 6:
            std::cout << "Exiting printer system.";
            break;

        default:
            std::cout << "Invalid Choice. Please Try Again.\n";
            break;
        }
    } while (choice != 6);

    return 0;
}
