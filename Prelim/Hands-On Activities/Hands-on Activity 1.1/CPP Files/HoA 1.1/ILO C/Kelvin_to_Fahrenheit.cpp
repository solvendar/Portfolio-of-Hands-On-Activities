#include <iostream>

float Fahrenheit(float kelv);
float Kelvin(float far);

int main()
{

    float conv;
    int choice;

    do
    {
        std::cout << std::endl;
        std::cout << "   Temperature Converter   " << std::endl;
        std::cout << std::endl;
        std::cout << "1. Kelvin to Fahrenheit" << std::endl;
        std::cout << "2. Fahrenheit to Kelvin" << std::endl;
        std::cout << std::endl;
        std::cout << "Input your choice: ";
        std::cin >> choice;

        switch (choice)
        {

        case 1:

            std::cout << "Enter the temperature in Kelvin:";
            std::cin >> conv;
            std::cout << "The temperature in Fahrenheit is: " << Fahrenheit(conv) << " " << std::endl;
            std::cout << std::endl;
            break;

        case 2:

            std::cout << "Enter the temperature in Fahrenheit: ";
            std::cin >> conv;
            std::cout << "The temperature in Kelvin is: " << Kelvin(conv) << std::endl;
            break;

        default:
            std::cout << "Invalid input. Input a valid number." << std::endl;
            break;
        }

    } while (choice);
    return 0;
}

float Fahrenheit(float kelv)
{
    return (kelv - 32) * 0.5 + 273.15;
}
float Kelvin(float far)
{
    return (far - 273.15) * 1.8 + 32;
}