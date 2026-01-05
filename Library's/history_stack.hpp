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
    
        if (stack.size() == MAX_HISTORY) {
            stack.erase(stack.begin());  
            
        }

        
        stack.push_back(song);

        std::cout << "Song \"" << song.name
                  << "\" by " << song.artist
                  << " added to history";
        if (stack.size() == MAX_HISTORY) {
            std::cout << " (oldest song removed to keep history at 10)";
        }
        std::cout << ".\n";
    }


    void pop(Song& previousSong) {
        if (stack.empty()) {
            std::cout << "No previous song in history.\n";
        }
        previousSong = std::move(stack.back());
        stack.pop_back();
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
            const Song& s = stack[stack.size() - 1 - i];  
            std::cout << (i + 1) << ". "
                      << s.name << " - "
                      << s.artist << " ("
                      << s.year << ") | "
                      << s.duration << " seconds | "
                      << "ID: " << s.id << "\n";
        }

        std::cout << "==============================================\n\n";
    }

    void clear() {
        stack.clear();
        std::cout << "History cleared.\n";
    }

    
    HistoryStack(const HistoryStack&) = delete;
    HistoryStack& operator=(const HistoryStack&) = delete;
};

