//Name:    Song.h
//Project: CMSC 202 Project 3, Fall 2022
//Author:  Jeremy Dixon
//Date:    10/5/2022
//Desc: This file contains the header details for the Song Class
//      A song has data about the song and acts as a node in a Playlist

// There should not be any cout statements in this class

#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>
using namespace std;

class Song{
 public:
  //Name: Song - Default Constructor
  //Precondition: None
  //Postcondition: Creates a default song using "New Title", "New Artist", 0 , 0 and sets m_next = nullptr;
  Song();
  //Name: Song - Overloaded Constructor
  //Precondition: Requires title, artist, year, and rank
  //Postcondition: Creates a song based on passed parameters and sets m_next = nullptr;
  Song(string title, string artist, int year, int rank );
  //Name: Mutators and Accessors
  //May or may not be used specifically but implement all
  //Precondition: None
  //Postcondition: Sets and Gets private member variables
  string GetTitle(); // return title
  string GetArtist(); // return artist
  int GetYear(); // return year
  int GetRank(); // return rank (1-100 from that year) 
  void SetTitle(string title); // sets title
  void SetArtist(string artist); //sets artist
  void SetYear(int year); //sets year
  void SetRank(int rank); //sets rank
  // Linked List specific getters and setters
  // Name: GetNext()
  // Desc: Returns the pointer to the next song
  // Preconditions: None (may return either song or nullptr)
  // Postconditions: Returns m_next;
  Song* GetNext();
  // Name: SetNext()
  // Desc: Updates the pointer to a new target (either a song or nullptr)
  // Preconditions: None
  // Postconditions: Sets the next song
  void SetNext(Song*);
  
  // Name: operator<<
  // Desc: Overloaded << operator to return ostream from a Song
  // Preconditions: Requires a populated song
  // Postconditions: Returns ostream populated with Song's name, artist, year, and rank
  // **PROVIDED** Do not edit
  friend ostream &operator<< (ostream &output, Song &mySong){
    output << "\"" << mySong.m_title << "\" by " << mySong.m_artist << " "
	   << mySong.m_rank << "/" << "100 from " << mySong.m_year;
    return output;
  }
 private:
  string m_title; //Title of song
  string m_artist; //Artist of song
  int m_year; //Year of release
  int m_rank; //Rank 1-100 from that year
  Song *m_next; //Pointer to next song (or nullptr)
};

#endif
