#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>

template <typename T>
class SongList
{

public:
    T data;
    SongList<T> *next = nullptr;
    SongList<T> *prev = nullptr;
};

// create node function
template <typename T>
SongList<T> *createNode(T newData)
{
    SongList<T> *newNode = new SongList<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// to close the circular loop
template <typename T>
void addSong(SongList<T> **head, T newData)
{
    SongList<T> *newNode = createNode(newData);

    // if playlist is totally empty
    if (*head == nullptr)
    {
        *head = newNode;
        newNode->next = newNode; // points to itself to start the circle
        newNode->prev = newNode; // points to itself backward too
    }
    // playlist already has songs
    else
    {
        SongList<T> *tail = (*head)->prev; // tail is always the node right behind head

        tail->next = newNode;    // old tail points forward to new node
        newNode->prev = tail;    // new node points backward to old tail
        newNode->next = *head;   // new node points forward to close the circle at head
        (*head)->prev = newNode; // head points backward to the new node (new tail)
    }
}

// added "SongList<std::string> **currentSong" to the parameters to safely update the pointer
void removeSong(SongList<std::string> **head, std::string songTitle, SongList<std::string> **currentSong)
{
    if (*head == nullptr)
    {
        std::cout << "No songs in the playlist." << std::endl;
        return;
    }

    SongList<std::string> *current = *head;

    do
    {
        if (current->data == songTitle)
        {
            // if deleting the song currently playing, step it forward safely
            if (*currentSong != nullptr && (*currentSong)->data == songTitle)
            {
                if ((*currentSong)->next == *currentSong)
                {
                    *currentSong = nullptr; // only one song left, player becomes empty
                }
                else
                {
                    *currentSong = (*currentSong)->next; // move player to the next track
                }
            }

            // case A: when it's the only song in the list
            if (current->next == current)
            {
                *head = nullptr;
            }
            // case B: if there are multiple songs left
            else
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;

                // if deleting the actual head, shift head to the next song
                if (current == *head)
                {
                    *head = current->next;
                }
            }

            delete current;
            std::cout << "Removed: " << songTitle << std::endl;
            return;
        }
        current = current->next;
    } while (current != *head);

    std::cout << "Song not found: " << songTitle << std::endl;
}

template <typename T>
void nextSong(SongList<T> **current)
{
    if (*current != nullptr)
    {
        *current = (*current)->next;
        std::cout << "Moved to next song: " << (*current)->data << std::endl;
    }
    else
    {
        std::cout << "Playlist is empty!" << std::endl;
    }
}

template <typename T>
void prevSong(SongList<T> **current)
{
    if (*current != nullptr)
    {
        *current = (*current)->prev;
        std::cout << "Moved to previous song: " << (*current)->data << std::endl;
    }
    else
    {
        std::cout << "Playlist is empty!" << std::endl;
    }
}

template <typename T>
void displayPlaylist(SongList<T> *head)
{
    if (head == nullptr)
    {
        std::cout << "No songs in the playlist." << std::endl;
        return;
    }
    SongList<T> *current = head;
    std::cout << " Playlist Layout " << std::endl;
    do
    {
        std::cout << "- " << current->data << std::endl;
        current = current->next;
    } while (current != head);
}

#endif