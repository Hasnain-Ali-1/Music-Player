#include "Playlist.h"
#include "Song.h"

/********************
File: Playlist.cpp
Project: CMSC 202 Project 3, Fall 2022
Author: Hasnain Ali
Date: 10/19/22
Section: 10/15
Email: hali6@umbc.edu

Contains code for the playlist class, where a linked list is created
and chosen songs from the song class are added as nodes. Additionally,
chosen songs can be removed from the linked list
********************/

// Playlist() - Default Constructor
// Creates a new empty playlist
Playlist::Playlist() {
  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;
}

// ~Playlist - Destructor
// Removes all of the songs from the playlist
Playlist::~Playlist() {                                                                                      
  Song* curr;                                                                                               // A pointer to a song that represents the current song
  curr = m_head;
  while (curr != nullptr) {
    curr = curr->GetNext();
    delete m_head;
    m_head = curr;
  }
  delete m_head;
  m_head = nullptr;
}

// AddSong
// New song inserted in end of list
void Playlist::AddSong(string title, string artist, int year, int rank) {
  if (m_size == 0) {
    Song* newSong;                                                                                          // A pointer to song that represents a new node
    newSong = new Song(title, artist, year, rank);
    // The next of newSong becomes m_head
    newSong->SetNext(m_head);
    // m_head takes the value of  newSong
    m_head = newSong;
    m_size++;
  }
  else {
    Song* newSong;                                                                                          // A pointer to song that represents a new node
    Song* prevSong;                                                                                         // A pointer to song that represents the previous node
    newSong = new Song(title, artist, year, rank);
    prevSong = m_head;
    // The next of newSong takes the value of m_tail
    newSong->SetNext(m_tail);
    m_tail = nullptr;
    // While the next of lastSong isn't nullptr
    while (prevSong->GetNext() != nullptr) {
      prevSong = prevSong->GetNext();
    }
    // The next of lastSong becomes newSong
    prevSong->SetNext(newSong);
    m_size++;
  }
}

// GetPlaylistDetails()
// Returns a song object from a specific location (does not output it)
Song* Playlist::GetPlaylistDetails(int location) {
  Song* curr = nullptr;                                                                                     // A pointer to song that represents the current node
  int count = 0;                                                                                            // An int to keep track of the current count
  // Iterates through the linked list
  for (curr = m_head; curr != nullptr; curr = curr->GetNext()) {
    count++;
    if (count == location) {
      // Returns the current node
      return curr;
    }
  }
  return 0;
}

// Name: Size
// Returns the size
int Playlist::Size() {
  return m_size;
}

// PlayAt
// "Plays" a song by removing it from the playlist at a specific location
void Playlist::PlayAt(int location) {
  Song* curr = m_head;                                                                                      // A pointer of song that represents the current node
  Song* prev = m_head;                                                                                      // A pointer of song that represents the previous node
  int count = 1;                                                                                            // An int to keep track of the current count
  // If the user wishes to play the first song in the playlist
  if ((location == 1) && (m_size == 0)) {
    m_head = nullptr;
  }
  else if ((location == 1) && (m_size != 0)) {
    m_head = m_head->GetNext();
  }
  else {
    while (count != location) {
      prev = curr;
      // curr takes the value of the next node
      curr = curr->GetNext();
      count++;
    }
    // The next of the previous node takes the value of the next of the current node
    prev->SetNext(curr->GetNext());
  }
  delete curr;
  m_size--;
}
