#ifndef QUEUEARR_H
#define QUEUEARR_H
#include <iostream>
#include <string>

class Job
{

public:
    int ID;
    std::string username;
    int number_of_pages;
};

class Printer
{

private:
    // pointer to the dynamically allocated array
    Job *q_array;
    size_t q_capacity;
    size_t q_size;
    int q_front;
    int q_back;

public:
    // constructor
    Printer(size_t capacity = 10);

    // functions / methods that will be called out below
    bool isEmpty() const;
    void Clear();
    bool isFull() const;

    void addJob(Job value);
    Job RemoveJob();
    void DisplayJob();
    void JobProcess();

    // destructor
    ~Printer();
};

// creating class queue & importing the printer class to the constructor above
//  constructor
Printer::Printer(size_t capacity)
{
    q_capacity = capacity;
    q_size = 0;
    q_front = 0;
    q_back = -1;
    q_array = new Job[q_capacity];
}

bool Printer::isFull() const
{
    return q_size == q_capacity;
}

bool Printer::isEmpty() const
{
    return q_size == 0;
}

void Printer::Clear()
{
    q_size = 0;
    q_front = 0;
    q_back = -1;
}

void Printer::addJob(Job value)
{

    // check if the Job is full
    if (isFull())
    {
        std::cout << "The Queue of the Printer is full.\n";
        return;
    }
    // else, use circular to compute the add for job
    // compute for the q_back for circular
    q_back = (q_back + 1) % q_capacity;

    // assign the q_array with the updated q_back to the value
    q_array[q_back] = value;

    // increment the q_size
    q_size++;

    std::cout << "Job had been added.\n";
}

Job Printer::RemoveJob()
{

    // check if the Job is empty
    if (isEmpty())
    {
        std::cout << "No Job to print\n";
        return Job();
    }

    Job tail = q_array[q_front];
    // move q_front circularly
    q_front = (q_front + 1) % q_capacity;

    // decrement the q_size
    q_size--;

    // reset index when Job is empty
    if (isEmpty())
    {
        Clear();
    }
    return tail;
}

void Printer::DisplayJob()
{
    if (isEmpty())
    {
        std::cout << "There are no pending to print for jobs.\n";
        return;
    }
    // else, for loop to display the jobs
    int size = q_front;
    // displaying jobs using loop
    for (size_t i = 0; i < q_size; i++)
    {
        std::cout << " | ID: " << q_array[size].ID << " | Username: "
                  << q_array[size].username << " | Pages: " << q_array[size].number_of_pages << "|" << std::endl;

        size = (size + 1) % q_capacity;
    }
}
// destructor / delete
Printer::~Printer()
{
    delete[] q_array;
}

void Printer::JobProcess()
{
    if (isEmpty())
    {
        std::cout << "No Job to process for now.\n";
        return;
    }
    // else, processing all jobs
    while (!isEmpty())
    {
        // to actively fetch jobs out of the array and to stop infinite loop freeze by reducing the queue size on every iteration
        Job tail = RemoveJob();
        std::cout << "| Printing Job ID: " << tail.ID << " | Username: " << tail.username << " | Pages: "
                  << tail.number_of_pages << " |" << std::endl;
    }
    std::cout << "The print for the job/s are done.\n";
}
#endif