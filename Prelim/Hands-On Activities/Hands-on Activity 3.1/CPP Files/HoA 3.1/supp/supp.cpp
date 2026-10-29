#include <iostream>
#include <string>
#include "song.h"

int main()
{

    int choice = 0;

    // moved outside the loop so they will not reset to null on every iteration
    SongList<std::string> *head = nullptr;
    SongList<std::string> *currentSong = nullptr;

    while (choice != 6)
    {

        std::cout << "\n=== MUSIC PLAYER MENU ===\n";
        std::cout << "1. Add Song\n";
        std::cout << "2. Remove Song\n";
        std::cout << "3. Next Song\n";
        std::cout << "4. Previous Song\n";
        std::cout << "5. Display All Songs\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore(); // clears the trailing newline character from cin

        switch (choice)
        {

        case 1:
        {

            std::string title;
            std::cout << "Enter song title: ";
            std::getline(std::cin, title); // using the getline to allow spaces in titles

            addSong(&head, title);

            // if nothing is playing yet, it make this new song to the current track
            if (currentSong == nullptr)
            {
                currentSong = head;
            }
            break;
        }

        case 2:
        {

            std::string title;
            std::cout << "Enter song title to remove: ";
            std::getline(std::cin, title);

            // pass &currentSong directly into removeSong so it syncs when a song is deleted
            removeSong(&head, title, &currentSong);
            break;
        }

        case 3:
        {
            nextSong(&currentSong);
            break;
        }
        case 4:
        {
            prevSong(&currentSong);
            break;
        }
        case 5:
        {
            displayPlaylist(head);
            break;
        }
        case 6:
            std::cout << "Exiting Music Player...\n";
            break;

        default:
            std::cout << "Invalid option!\n";
        }
    }

    return 0;
}
