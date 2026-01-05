#include <iostream>
#include <string>
#pragma once

class Song{
    friend class SongRepository;
    friend class PlayQueue;
    friend class HistoryStack;

    private:
        std::string name, artist;
        unsigned int year;
        std::string id;
        unsigned int duration;
        Song* nextSong;
        Song* previousSong;
    
    public:
        Song(std::string name, std::string artist,
            unsigned int year, std::string id, unsigned int duration = 0) : 
                name(name), artist(artist), year(year), id(id), duration(duration), nextSong(nullptr), previousSong(nullptr) {}
};