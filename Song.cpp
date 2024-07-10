#include "Song.h"

/********************
File: Song.cpp
Project: CMSC 202 Project 3, Fall 2022
Author: Hasnain Ali
Date: 10/18/22
Section: 10/15
Email: hali6@umbc.edu

Contains code for the song class, where each song object populates a vector and
chosen songs act as a node for the playlist
********************/

// Song - Default Constructor
// Creates a default song using "New Title", "New Artist", 0 , 0 and sets m_next = nullptr;
Song::Song() {
  string title = "New Title";                                                                                  // A string with a default value for title
  string artist = "New Artist";                                                                                // A string with a default value for artist
  int year = 0;                                                                                                // An int with default value for year
  int rank = 0;                                                                                                // An int with default value for rank
  Song* next = nullptr;                                                                                        // A pointer to song that sets next as nullptr
  SetTitle(title);
  SetArtist(artist);
  SetYear(year);
  SetRank(rank);
  SetNext(next);
}

// Song - Overloaded Constructor
// Creates a song based on passed parameters and sets m_next = nullptr;
Song::Song(string title, string artist, int year, int rank ) {
  Song* next = nullptr;                                                                                        // A pointer to song that sets next as nullptr
  SetTitle(title);
  SetArtist(artist);
  SetYear(year);
  SetRank(rank);
  SetNext(next);
}

// GetTitle
// return title
string Song::GetTitle() {
  return m_title;
}

// GetArtist
// return artist
string Song::GetArtist() {
  return m_artist;
}

// GetYear
// return year
int Song::GetYear() {
  return m_year;
}

// GetRank
// return rank (1-100) from that year
int Song::GetRank() {
  return m_rank;
}

// SetTitle
// sets title
void Song::SetTitle(string title) {
  m_title = title;
}

// SetArtists
// sets artist
void Song::SetArtist(string artist) {
  m_artist = artist;
}

// SetYear
// sets Year
void Song::SetYear(int year) {
  m_year = year;
}

// SetRank
// sets Rank
void Song::SetRank(int rank) {
  m_rank = rank;
}

// GetNext
// returns m_next;
Song* Song::GetNext() {
  return m_next;
}

// SetNext
// Sets the next song
void Song::SetNext(Song* next) {
  m_next = next;
}
