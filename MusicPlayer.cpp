
0;136;0c#include "Song.h"
#include "Playlist.h"
#include "MusicPlayer.h"

/********************
File: MusicPlayer.cpp
Project: CMSC 202 Project 3, Fall 2022
Author: Hasnain Ali
Date: 10/19/22
Section: 10/15
Email: hali6@umbc.edu

Contains code for managing the playlist, as well as the
main menu.
********************/


// MusicPlayer - Default Constructor
// Dynamically creates a new MusicPlayer and populates m_filename FILE_NAME
MusicPlayer::MusicPlayer() {
}

// ~MusicPlayer - Destructor
// Postcondition: Destructs all songs in the catalog and all songs in the playlist
MusicPlayer::~MusicPlayer() {
}

// LoadCatalog
// Loads the file of songs into the m_songCatalog (as song objects) using the DELIMITER
void MusicPlayer::LoadCatalog(string filename) {
  Song* newSong;                                                                                      // Creates a pointer to a song
  string line;                                                                                        // A string used to represent the lines in the text file
  int numOfSongs = 0;                                                                                 // An integer used to keep track of the number of songs loaded
  ifstream songFile;                                                                                  // An ifstream used to open the text file
  string songTitle = "placeholder";                                                                   // A string that will be used as the song's name
  string songArtist = "placeholder";                                                                  // A string that will be used as the artist's name
  int songYear = 0;                                                                                   // An int that will be used as the song's year
  int songRank = 0;                                                                                   // An int that will be used as the song's rank
  char newLine = '\n';                                                                                // A char that represents the newline character
  int newLineCount = 0;                                                                               // An int that keeps track of how many items need to be deleted from line
  m_playList = new Playlist();                                                                        // Dynamically allocates a new playlist
  songFile.open(filename);
  if (songFile.is_open()) {
    while (getline (songFile, line, DELIMITER)) {
      // If title has the placeholder value
      if (songTitle == "placeholder") {
	songTitle = line;
      }
      // If artist has the placeholder value
      else if (songArtist == "placeholder") {
	songArtist = line;
      }
      // If year has the placeholder value
      else if (songYear == 0) {
	songYear = stoi(line);
      }
      // If everything but rank doesn't have a placeholder value
      else {
	songRank = stoi(line);
      }
      // If title, artist, year, and rank all don't have the placeholder value
      if ((songTitle != "placeholder") && (songArtist != "placeholder") &&
	  (songYear != 0) && (songRank != 0)) {
	// Connects the pointer to a new song object
	newSong = new Song(songTitle, songArtist, songYear, songRank);
	m_songCatalog.push_back(newSong);
	numOfSongs++;
	// Since the final line has a format of 12\nSongName, with 12 being the rank
	// of the current song and SongName being the name of the next song, this part
	// keeps count of how many characters there are until the iterator gets to the
	// SongName part. So in the case of 12\nSongName, until the iterator iterates
	// over 1, 2, and \n.
	for (unsigned int i = 0; i < line.size(); i++) {
	  if ((i == 0) || (i == 1)) {
	    if ((line[i] == '0') || (line[i] == '1') || (line[i] == '2') || (line[i] == '3') ||
		(line[i] == '4') || (line[i] == '5') || (line[i] == '6') || (line[i] == '7') ||
		(line[i] == '8') || (line[i] == '9') || (line[i] == newLine)) {
	      newLineCount++;
	    }
	  }
	  if (i == 2) {
	    if ((line[i] == '0') || (line[i] == newLine)) {
	      newLineCount++;
	    }
	  }
	  if (i == 3) {
	    if (line[i] == newLine) {
	      newLineCount++;
	    }
	  }
	}
	line.erase(0, newLineCount);
	// songTitle gets it's value for the next song in the file and everything else
	// is reset to it's default values before values were assigned
	songTitle = line;
	songArtist = "placeholder";
	songYear = 0;
	songRank = 0;
	newLineCount = 0;
      }
    }
    songFile.close();
    cout << "The number of songs loaded is " << numOfSongs << "\n";
  }
  // If the file the user entered couldn't be loaded
  else {
    cout << "The file couldn't be loaded \n";
  }
}
 
// MainMenu
// Manages the application and the menu. Calls until user chooses to quit.
void MusicPlayer::MainMenu() {
  int userChoice = 0;                                                                                 // An integer that represents the user's choice
  bool validChoice = false;                                                                           // A boolean used to determine if the user entered a valid command
  while (validChoice == false) {
    cout << "What would you like to do? \n";
    cout << "1. Display songs by year \n";
    cout << "2. Add Song \n";
    cout << "3. Display Playlist \n";
    cout << "4. Play Song \n";
    cout << "5. Quit \n";
    cin >> userChoice;
    // Input validation for the main menu
    if ((userChoice >= 1) && (userChoice <=5)) {
      validChoice = true;
    }
    else {
      cout << "Please enter a valid number (1-5) \n";
      validChoice = false;
    }
  }
  // Displays songs from the chosen year
  if (userChoice == 1) {
    DisplaySongs();
    MainMenu();
  }
  // Adds a song to the playlist
  else if (userChoice == 2) {
    AddSong();
  }
  // Displays the playlist
  else if (userChoice == 3) {
    DisplayPlaylist();
    MainMenu();
  }
  // Plays a song from the playlist
  else if (userChoice == 4) {
    PlaySong();
  }
  // Deletes every item that was dynamically allocated
  else if (userChoice == 5) {
    // Deletes every item in m_songCatalog
    for (unsigned int i = 0; i < m_songCatalog.size(); i++ ) {
      delete m_songCatalog.at(i);
    }
    // If the playlist is empty
    delete m_playList;
    cout << "Thank you for using the UMBC Music Player \n";
  }
}
  
// DisplaySongs
// Lists all songs (numbered) for that year by ranking
void MusicPlayer::DisplaySongs() {
  int songYear;                                                                                      // An integer used to determine the year the user entered
  bool validSongYear = false;                                                                        // A booelan used to determine if the user entered a valid year
  int count = 0;                                                                                     // An integer used to keep track of the current song count when numbering
  while (validSongYear == false) {
    cout << "Which year would you like to display? (2010-2021) \n";
    cin >> songYear;
    // Input validation for year
    if ((songYear >= LOW_YEAR) && (songYear <= HIGH_YEAR)) {
      validSongYear = true;
    }
    else {
      cout << "Please enter a year from 2010-2021 \n";
      validSongYear = false;
    }
  }
  cout << "******" << songYear << "****** \n";
  // Prints out a numbered list of the songs with a matching year
  for (unsigned int i = 0; i < m_songCatalog.size(); i++) {
    count ++;
    if (m_songCatalog.at(i)->GetYear() == songYear) {
      cout << count << ". " << *m_songCatalog.at(i) << "\n";
    }
  }
}

// AddSong
// Displays the songs for a specific year and adds a song to the m_playList at the end
void MusicPlayer::AddSong() {
  bool validSongNumber = false;                                                                      // A boolean used to determine if the user entered a valid song number
  int songNumber;                                                                                    // An integer that represents the song the user wishes to add to the playlist
  int count = 0;                                                                                     // An integer used to keep track of the current song count when iterating
  string title;                                                                                      // A string to represent the title of the song
  string artist;                                                                                     // A string to represent the artist of the song
  int year;                                                                                          // An int used to represent the year the song came out
  int rank;                                                                                          // An int used to represent the rank of the song                                      
  int numOfSongs = 0;                                                                                // An int used to keep track of the total number of songs in the vector
  // Gets the number of songs in the vector
  for (unsigned int i = 0; i < m_songCatalog.size(); i++) {
    numOfSongs++;
  }
  cout << "Choose the songs you would like to add to the playlist. \n";
  DisplaySongs();
  // Checks to see if the number the user entered is between 1 and the number of
  // songs in the vector
  while (validSongNumber == false) {
    cout << "Enter the number of the song you would like to add: \n";
    cin >> songNumber;
    if ((songNumber >= 1) && (songNumber <= numOfSongs)) {
      validSongNumber = true;
    }
    else {
      cout << "Please enter a valid song number (1-" << numOfSongs << ")" << "\n";
      validSongNumber = false;
    }
  }
  // Iterates through the vector and increments count each time
  for (unsigned int i = 0; i < m_songCatalog.size(); i++) {
    count ++;
    // If count equals the number of the song number the user picked to be added to the
    // playlist
    if (count == songNumber) {
      title = m_songCatalog.at(i)->GetTitle();
      artist = m_songCatalog.at(i)->GetArtist();
      year = m_songCatalog.at(i)->GetYear();
      rank = m_songCatalog.at(i)->GetRank();
      // Adds the song to the playlist
      m_playList->AddSong(title, artist, year, rank);
      cout << "Added: " << *m_songCatalog.at(i) << "\n";
    }
  }
  MainMenu();
}


// DisplayPlaylist
// Displays the playlist or tells the user it is empty
void MusicPlayer::DisplayPlaylist() {
  if (m_playList->Size() == 0) {
    cout << "***Current Playlist is Empty*** \n";
  }
  else {
    int playlistSize;                                                                                // An int that represents the playlist size
    Song* currentSong;                                                                               // A pointer to song that represents the current song
    playlistSize = 1;
    cout << "Your Playlist \n";
    // Prints out the song information for each song in the playlist
    for (int i = 0; i < m_playList->Size(); i++) {
      currentSong = m_playList->GetPlaylistDetails(playlistSize);
      cout << playlistSize << ". " << *currentSong << "\n";
      playlistSize++;
    }
  }
}

// PlaySong
// Allows the user to choose a song from the playlist to play and removes song from playlist
void MusicPlayer::PlaySong() {
  int playSong;                                                                                     // An int that represents the song from the playlist the user wants to play
  Song* playedSong;                                                                                 // A pointer to song that represents the song being played
  bool validSong = false;                                                                           // A boolean to determine if a valid number from the playlist was selected
  DisplayPlaylist();
  // If the playlist is empty, return to the main menu
  if (m_playList->Size() == 0) {
    MainMenu();
  }
  else {
    // Input validation for selecting a song to play from the playlist
    while (validSong == false) {
      cout << "Which song would you like to play? \n";
      cin >> playSong;
      if ((playSong < 1) || (playSong > m_playList->Size())) {
	cout << "Enter a valid number (1-" << m_playList->Size() << ") \n";
	validSong = false;
      }
      else {
	validSong = true;
      }
    }
    // Gets information for the song being played
    playedSong = m_playList->GetPlaylistDetails(playSong);
    cout << "Played: " << *playedSong << "\n";
    // Removes the chosen song from the playlist
    m_playList->PlayAt(playSong);
    MainMenu();
  }
}
