#include <iostream>
#include <vector>
#include <string>
#include "song.hpp"

class HistoryStack {
private:
    std::vector<Song> stack;
    static const size_t MAX_HISTORY = 10; 
public:
    HistoryStack() : stack() {}

    ~HistoryStack() = default;

    
    void push(const Song& song) {
        if (stack.size() == MAX_HISTORY)
            stack.erase(stack.begin());

        Song copy = song;
        copy.resetLinks();
        stack.push_back(copy);
    }


    bool pop(Song& previousSong) {
        if (stack.empty()) {
            std::cout << "No previous song\n";
            return false;
        }
        previousSong = stack.back();
        stack.pop_back();
        return true;
    }


    
    bool top(Song& topSong) const {
        if (stack.empty()) {
            return false;
        }
        topSong = stack.back();
        return true;
    }

    int size() const {
        return static_cast<int>(stack.size());
    }

    
    void showHistory() const {
        if (stack.empty()) {
            std::cout << "History is empty. No songs played yet.\n";
            return;
        }

        std::cout << "\n=== Playback History (Last " << stack.size() << " songs) ===\n";
        for (size_t i = 0; i < stack.size(); ++i) {
            const Song& s = stack[stack.size() - 1 - i]; // آخرین آهنگ اول
            std::cout << i + 1 << ". Name: " << s.name << "\n"
                    << "   Artist: " << s.artist << "\n"
                    << "   Year: " << s.year << "\n"
                    << "   Duration: " << s.duration << " seconds\n"
                    << "   ID: " << s.id << "\n";
        }
        std::cout << "=========================\n\n";
    }

    void clear() {
        stack.clear();
        std::cout << "History cleared.\n";
    }

    
    HistoryStack(const HistoryStack&) = delete;
    HistoryStack& operator=(const HistoryStack&) = delete;
};

