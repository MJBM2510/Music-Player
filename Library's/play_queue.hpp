#include <iostream>
#include <vector>
#include <string>
#include "song.hpp"

  

class  PlayQueue{
private:
    std::vector<Song> queue;  

public:
  
    PlayQueue() : queue() {}

    ~PlayQueue() = default;  

    
    void enqueue(const Song& song) {
        Song copy = song;
        copy.resetLinks();
        queue.push_back(copy);
    }

    void enqueueAtFront(const Song& song) {
        Song copy = song;
        copy.resetLinks();
        queue.insert(queue.begin(), copy);
    }
    
    bool dequeue(Song& nextSong) {
        if (queue.empty()) {
            std::cout << "Queue is empty\n";
            return false;
        }
        nextSong = queue.front();
        queue.erase(queue.begin());

        std::cout << "Now playing: "
                << nextSong.name << " by "
                << nextSong.artist << "\n";
        return true;
    }



    bool peek(Song& nextSong) const {
        if (queue.empty()) {
            return false;
        }
        nextSong = queue.front();
        return true;
    }

    
    int size() const {
        return static_cast<int>(queue.size());
    }

    
    void showQueue() const {
        if (queue.empty()) {
            std::cout << "Queue is empty.\n";
            return;
        }

        std::cout << "\n=== Play Queue (" << queue.size() << " songs) ===\n";
        for (size_t i = 0; i < queue.size(); ++i) {
            const Song& s = queue[i];
            std::cout << i + 1 << ". Name: " << s.name << "\n"
                    << "   Artist: " << s.artist << "\n"
                    << "   Year: " << s.year << "\n"
                    << "   Duration: " << s.duration << " seconds\n"
                    << "   ID: " << s.id << "\n";
        }
        std::cout << "=========================\n\n";
    }


    
    void searchInQueue(const std::string& keyword) const {
        bool found = false;
        std::cout << "Search results in queue for \"" << keyword << "\":\n";

        for (const Song& s : queue) {
            if (s.name.find(keyword) != std::string::npos ||
                s.artist.find(keyword) != std::string::npos) {
                std::cout << "   • " << s.name << " - " << s.artist
                          << " (ID: " << s.id << ")\n";
                found = true;
                break;
            }
        }

        if (!found) {
            std::cout << "   No matching songs found in queue.\n";
        }
    }


    void clear() {
        queue.clear();
        std::cout << "Queue cleared.\n";
    }

   
    PlayQueue(const PlayQueue&) = delete;
    PlayQueue& operator=(const PlayQueue&) = delete;
};
