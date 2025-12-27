#include <iostream>
#include <string>

class Song{
    private:
        std::string name, artist;
        unsigned int year;
        std::string id;
        unsigned int duration;
        Song* nextSong;
        Song* previousSong;
    
    public:
        Song(std::string name, std::string artist,
            unsigned int year, std::string id = "", unsigned int duration = 0) : 
                name(name), artist(artist), year(year), id(id), duration(duration) {}

        void setSong(std::string name, std::string artist,
            unsigned int year, std::string id = "", unsigned int duration = 0){
                this->name = name;
                this->artist = artist;
                this->year = year;
                this->id = id;
                this->duration = duration;
                nextSong = nullptr;
                previousSong = nullptr;
            }
};