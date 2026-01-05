#include <iostream>
#include <string>
#include "song.hpp"
class SongRepository{
    private:
        Song* head;
        Song* tail;
    
    public:
        SongRepository() : head(nullptr), tail(nullptr) {}

        void addSong(std::string name, std::string artist,
            unsigned int year, std::string id, unsigned int duration = 0){
                Song* newSong = new Song(name, artist, year, id, duration);

                if(head == nullptr){
                    head = newSong;
                    tail = newSong;
                }
                else{
                    tail->nextSong = newSong;
                    newSong->previousSong = tail;
                    tail = newSong;
                }
        }

        Song* getHead() const { return head; }

        void deleteSong(const std::string& keyword) {
            for (Song* cur = head; cur; cur = cur->nextSong) {
                if (cur->id == keyword || cur->name == keyword) {

                    if (cur == head)
                        head = cur->nextSong;
                    else
                        cur->previousSong->nextSong = cur->nextSong;

                    if (cur == tail)
                        tail = cur->previousSong;
                    else
                        cur->nextSong->previousSong = cur->previousSong;

                    if (head) head->previousSong = nullptr;
                    if (tail) tail->nextSong = nullptr;

                    delete cur;
                    std::cout << "Song deleted successfully\n";
                    return;
                }
            }
            std::cout << "Song not found\n";
        }

        Song* searchSong(const std::string& keyword){
            for(Song* currentSong = head; currentSong != nullptr; currentSong = currentSong->nextSong){
                if((currentSong->artist == keyword)|| (currentSong->name == keyword)){
                    std::cout<<"Title: "<<currentSong->name<<", Artist: "<<currentSong->artist<<std::endl;
                    return currentSong;
                }
            }

            std::cout<<"No song/artist found with similar keyword: "<<keyword<<std::endl;
            return nullptr;
        }

        void showPlaylist() {
            if (!head) {
                std::cout << "Playlist is empty.\n";
                return;
            }

            std::cout << "\n=== Playlist ===\n";
            int i = 1;
            for (Song* cur = head; cur; cur = cur->nextSong) {
                std::cout << i++ << ". Name: " << cur->name << "\n"
                        << "   Artist: " << cur->artist << "\n"
                        << "   Year: " << cur->year << "\n"
                        << "   Duration: " << cur->duration << " seconds\n"
                        << "   ID: " << cur->id << "\n";
            }
            std::cout << "================\n\n";
        }

        ~SongRepository() {
            while (head) {
                Song* temp = head;
                head = head->nextSong;
                delete temp;
            }
            tail = nullptr;
        }
};