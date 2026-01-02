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

        void deleteSong(const std::string& id){
            for(auto* currentSong = head; currentSong != nullptr; currentSong = currentSong->nextSong){
                if(currentSong->id == id){
                    if(currentSong == head) head = currentSong->nextSong;
                    else currentSong->previousSong->nextSong = currentSong->nextSong;

                    if(currentSong == tail) tail = currentSong->previousSong;
                    else currentSong->nextSong->previousSong = currentSong->previousSong;

                    auto name   = currentSong->name;
                    auto artist = currentSong->artist;
                    auto sid    = currentSong->id;

                    delete currentSong;

                    std::cout<<"Song "<<name<<" by "<<artist<<", id: "<<sid<<" has deleted successfully\n";

                    return;
                }
            }

            std::cout<<"NO song find with id: "<<id<<std::endl;
        }

        void searchSong(const std::string& keyword){
            for(auto* currentSong = head; currentSong != nullptr; currentSong = currentSong->nextSong){
                if((currentSong->artist == keyword)|| (currentSong->name == keyword)){
                    std::cout<<"Title: "<<currentSong->name<<", Artist: "<<currentSong->artist<<std::endl;
                    return;
                }
            }

            std::cout<<"No song/artist fine with similar keyword: "<<keyword<<std::endl;
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