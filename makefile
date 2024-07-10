CXX = g++
CXXFLAGS = -Wall -g

proj3: MusicPlayer.o Song.o proj3.cpp Playlist.o
	$(CXX) $(CXXFLAGS) MusicPlayer.o Song.o Playlist.o proj3.cpp -o proj3

MusicPlayer.o: MusicPlayer.cpp  MusicPlayer.h Playlist.o Song.o
	$(CXX) $(CXXFLAGS) -c MusicPlayer.cpp

Playlist.o: Playlist.h Playlist.cpp
	$(CXX) $(CXXFLAGS) -c Playlist.cpp

Song.o: Song.cpp Song.h
	$(CXX) $(CXXFLAGS) -c Song.cpp

run:
	./proj3

run1:
	./proj3 proj3_music.txt

val1:
	valgrind ./proj3 proj3_music.txt

clean: 
	rm *~
	rm *.o
