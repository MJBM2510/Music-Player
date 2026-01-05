#pragma once
#include <string>

class Song {
    public:
        std::string name, artist;
        unsigned int year{};
        std::string id;
        unsigned int duration{};
        unsigned int playCount{0};

        Song* nextSong{nullptr};
        Song* previousSong{nullptr};

        Song() = default;

        Song(std::string name, std::string artist,
            unsigned int year, std::string id, unsigned int duration = 0)
            : name(name), artist(artist),
            year(year), id(id), duration(duration) {}

        void resetLinks() {
            nextSong = nullptr;
            previousSong = nullptr;
        }
};
