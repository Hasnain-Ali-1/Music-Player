//Title: Playlist.h
//Author: Jeremy Dixon
//Date: 10/5/2022
//Description: This is part of the project 3 in CMSC 202 @ UMBC
//This is a linked list class used to store songs for a playlist

//There should not be any cout statements in this class

#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <fstream>
#include <iostream>
#include "Song.h"
using namespace std;

//This class refers to a playlist of songs
//In this case, the playlist is a linked list of songs

class Playlist {
public:
  // Name: Playlist() - Default Constructor
  // Desc - Creates a new empty playlist
  // Preconditions - None
  // Postconditions - Sets everything to either nullptr or 0
  Playlist();
  // Name: ~Playlist - Destructor
  // Desc - Removes all of the songs from the playlist
  // Preconditions - Playlist must have songs
  // Postconditions - Playlist will be empty and m_head and m_tail will be nullptr. Size will be 0
  ~Playlist();
  // Name: AddSong(string, string, int, int)
  // Desc - Dynamically allocates new song using title, artist, year, and rank
  // Preconditions - Playlist allocated
  // Postconditions - New song inserted in end of list
  void AddSong(string, string, int, int);
  // Name: GetPlaylistDetails()
  // Desc - Returns a song object from a specific location
  // Preconditions - Playlist populated
  // Postconditions - Returns the data (does not output it)
  Song* GetPlaylistDetails(int location);
  // Name: Size
  // Desc - Returns the m_size
  // Preconditions - Playlist starts at size 0
  // Postconditions - Returns the size
  int Size();
  // Name: PlayAt
  // Desc - Passed the song that is to be played from the playlist
  //       "Plays" a song by removing it from the playlist at a specific location
  // Recommendations - Code this function last (dead last)
  // Preconditions - Playlist has been populated
  // Hint: Do not forget about removing from the front, middle, or end of the list
  //       Could also remove the only node
  // Postconditions - Playlist is reduced in size by one based on which song is played
  void PlayAt(int location);
private:
  Song* m_head; //Head of the playlist
  Song* m_tail; //End of the playlist
  int m_size; //Total songs on the playlist (size of linked list)
};

#endif /* PLAYLIST_H */
