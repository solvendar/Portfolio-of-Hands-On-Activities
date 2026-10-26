#include <iostream>
#include <string>

class Fruit
{

private:
    std::string fruitName;
    int price;
    int quantity;

public:
    // setter
    void setFruitName(std::string newFruitName)
    {
        fruitName = std::move(newFruitName);
    }
    void setPrice(int newPrice)
    {
        price = newPrice;
    }
    void setQuantity(int newQuantity)
    {
        quantity = newQuantity;
    }
    // getter
    std::string getFruitName() const
    {
        return (fruitName);
    }
    int getPrice() const
    {
        return price;
    }
    int getQuantity() const
    {
        return quantity;
    }

    // constructor
    Fruit(std::string newFruitName = "", int newPrice = 0, int newQuantity = 0)
    {
        fruitName = std::move(newFruitName);
        price = newPrice;
        quantity = newQuantity;
        std::cout << "Constructor Called." << std::endl;
    };
    // deconstructor
    ~Fruit()
    {
        std::cout << "Destructor Called." << std::endl;
    }
    // copy constructor
    Fruit(const Fruit &copyFruit)
    {
        std::cout << "Copy Constructor Called" << std::endl;
        fruitName = copyFruit.fruitName;
        price = copyFruit.price;
        quantity = copyFruit.quantity;
    }
    // display attributes
    void printDetails()
    {
        std::cout << "Fruit Name: " << fruitName << std::endl;
        std::cout << "Price: " << price << std::endl;
        std::cout << "Quantity: " << quantity << std::endl;
        std::cout << "Total :" << sum() << std::endl;

        std::cout << this->fruitName << " " << this->price << " " << this->quantity << std::endl;
    }
    // compute the sum of the price and quantity of the fruit
    int sum()
    {
        return price * quantity;
    }
    // copy assignment operator
    Fruit &operator=(const Fruit &copyFruit)
    {
        if (this == &copyFruit)
        {
            std::cout << "Copy Assignment has been called";
            return *this;
        };
        fruitName = copyFruit.fruitName;
        price = copyFruit.price;
        quantity = copyFruit.quantity;
        return *this;
    };
};

class Vegetable
{

private:
    std::string vegName;
    int price;
    int quantity;

public:
    // setter
    void setVegName(std::string newVegName)
    {
        vegName = std::move(newVegName);
    }
    void setPrice(int newPrice)
    {
        price = newPrice;
    }
    void setQuantity(int newQuantity)
    {
        quantity = newQuantity;
    }
    // getter
    std::string getVegName() const
    {
        return (vegName);
    }
    int getPrice() const
    {
        return price;
    }
    int getQuantity() const
    {
        return quantity;
    }

    // constructor
    Vegetable(std::string newVegName = "", int newPrice = 0, int newQuantity = 0)
    {
        vegName = std::move(newVegName);
        price = newPrice;
        quantity = newQuantity;
        std::cout << "Constructor Called." << std::endl;
    };
    // deconstructor
    ~Vegetable()
    {
        std::cout << "Destructor Called." << std::endl;
    }
    // Copy Constructor
    Vegetable(const Vegetable &copyVegetable)
    {
        std::cout << "Copy Constructor Called" << std::endl;
        vegName = copyVegetable.vegName;
        price = copyVegetable.price;
        quantity = copyVegetable.quantity;
    }
    // Display Attributes
    void printDetails()
    {
        std::cout << "Vegetable Name: " << vegName << std::endl;
        std::cout << "Price: " << price << std::endl;
        std::cout << "Quantity: " << quantity << std::endl;
        std::cout << "Total :" << sum() << std::endl;

        std::cout << this->vegName << " " << this->price << " " << this->quantity << std::endl;
    }

    // compute the sum of the price and quantity of the fruit
    int sum()
    {
        return price * quantity;
    }

    // copy assignment operator
    Vegetable &operator=(const Vegetable &copyVegetable)
    {
        if (this == &copyVegetable)
        {
            std::cout << "Copy Assignment has been called";
            return *this;
        };
        vegName = copyVegetable.vegName;
        price = copyVegetable.price;
        quantity = copyVegetable.quantity;
        return *this;
    }
};

int totalsumprice(Fruit fruits[], int countFruit, Vegetable vegetable[], int countVeg)
{
    int wholesum = 0;

    for (int i = 0; i < countFruit; i++)
    {
        wholesum += fruits[i].sum();
    }
    for (int i = 0; i < countVeg; i++)
    {
        wholesum += vegetable[i].sum();
    }
    return wholesum;
}
int main()
{

    const size_t k = 2;
    const size_t v = 2;

    // direct initialization
    Fruit fruitList1[k] = {
        Fruit("Apple", 10, 7),
        Fruit("Banana", 10, 8)};

    Vegetable vegList2[v] = {
        Vegetable("Brocolli", 60, 12),
        Vegetable("Lettuce", 50, 10)};

    // header
    std::cout << "Jenna's Grocery List\n";
    std::cout << std::endl;

    // display for the fruits
    for (int i = 0; i < k; i++)
    {
        fruitList1[i].printDetails();
    }

    // display for the vegetables
    for (int i = 0; i < v; i++)
    {
        vegList2[i].printDetails();
    }

    // displaying the total amount
    int whole_total = totalsumprice(fruitList1, k, vegList2, v);
    std::cout << "\n Total Amount to Pay: PHP " << whole_total << std::endl;

    // calling the destructor manually for index 1 of vegetables (Lettuce)
    vegList2[1].~Vegetable();

    // for redisplaying the items
    for (int i = 0; i < k; i++)
    {
        fruitList1[i].printDetails();
    }

    // to see that the broccoli was still inside even the lettuce was deleted
    // and showing it was still untouched even one item is deleted
    vegList2[0].printDetails();

    // empty slot message for the index 3 this is the lettuce
    std::cout << "Empty Slot. The Element at the index 3 was deleted." << std::endl;

    return 0;
}