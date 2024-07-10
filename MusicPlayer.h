//Title: MusicPlayer.h
//Author: Jeremy Dixon
//Date: 10/5/2022
//Description: This is part of the project 3 in CMSC 202 @ UMBC
//This is the music player that holds a music catalog and allows the user to build a playlist
//Do not edit this header file

#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "Song.h"
#include "Playlist.h"

using namespace std;

//Constants
const int LOW_YEAR = 2010; //First year of music catalog
const int HIGH_YEAR = 2021; //Last year of music catalog
const string FILE_NAME = "proj3_music.txt"; //Default input file
const char DELIMITER = '|'; //Default delimiter for the input file

class MusicPlayer{
 public:
  //Name: MusicPlayer - Default Constructor
  //Precondition: None
  //Postcondition: Dynamically creates a new MusicPlayer and populates m_filename FILE_NAME
  MusicPlayer();
  //Name: ~MusicPlayer - Destructor
  //Precondition: None
  //Postcondition: Destructs all songs in the catalog and all songs in the playlist
  ~MusicPlayer();
  //Name: LoadCatalog(string filename)
  //Precondition: Requires filename
  //Postcondition: Loads the file of songs into the m_songCatalog (as song objects) using the DELIMITER
  void LoadCatalog(string filename);
  //Name: MainMenu
  //Precondition: None
  //Postcondition: Manages the application and the menu. Calls until user chooses to quit.
  void MainMenu();
  //Name: DisplaySongs
  //Precondition: User enters year using constants above (2010-2021)
  //Postcondition: Lists all songs (numbered) for that year by ranking
  void DisplaySongs();
  //Name: AddSong
  //Precondition: m_songCatalog is populated and m_playList exists
  //Postcondition: Displays the songs for a specific year. Adds a song to the m_playList by dynamically allocating a new song based on the song in the catalog
  //               and inserting it in the end.
  //               May have duplicate songs on a playlist.
  //               If the user chooses 2010, the user does not have to choose something from 2010 but it does need to be valid (between 1 - 1200)
  void AddSong();
  //Name: DisplayPlaylist
  //Precondition: None (can be empty)
  //Postcondition: Displays the playlist or tells the user it is empty
  void DisplayPlaylist();
  //Name: PlaySong
  //Precondition: Playlist should be populated
  //Postcondition: Allows the user to choose a song from the playlist to play.
  //               Removes chosen song from playlist after "played"
  void PlaySong();
  
 private:
  vector<Song*> m_songCatalog; //Holds all songs in input file as songs
  Playlist* m_playList; //Holds all songs in play list
};


#endif
