#include <iostream>
#include "Library's/history_stack.hpp"
#include "Library's/song_repository.hpp"
#include "Library's/play_queue.hpp"
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct MusicPlayer{
    HistoryStack history;
    PlayQueue queue;
    SongRepository playlist;
    Song* currentSong = nullptr;
};

vector<string> datas(const string& input){
    vector<string> tokens;
    stringstream ss(input);
    string item;

    while(getline(ss, item, ','))
        tokens.push_back(item);
    
    return tokens;
}

void playNext(MusicPlayer& mp) {
    Song next;
    if (mp.queue.dequeue(next)) {
    }else {
        if (!mp.currentSong)
            mp.currentSong = mp.playlist.getHead();
        else
            mp.currentSong = mp.currentSong->nextSong;

        if (!mp.currentSong) {
            std::cout << "No more songs\n";
            return;
        }
        next = *mp.currentSong;
    }

    next.playCount++;
    mp.history.push(next);
}

void playPrevious(MusicPlayer& mp) {
    Song previous;

    if (!mp.history.pop(previous)) {
        std::cout << "No previous song to play\n";
        return;
    }

    previous.playCount++;

    std::cout << "Playing previous: "
              << previous.name << " by "
              << previous.artist << "\n";

    Song* cur = mp.playlist.getHead();
    while (cur) {
        if (cur->id == previous.id) {
            mp.currentSong = cur;
            break;
        }
        cur = cur->nextSong;
    }
}

int main(){
    MusicPlayer mp;
    string command, input;

    while(true){
        cin>>command;

        if(command == "addsong"){
            cin.ignore();
            getline(cin, input);
            auto parts = datas(input);
            if(parts.size() == 5)
                mp.playlist.addSong(parts[0], parts[1], stoi(parts[2]), parts[3], stoi(parts[4]));
            else if(parts.size() == 4)
                mp.playlist.addSong(parts[0], parts[1], stoi(parts[2]), parts[3]);
        }

        if(command == "deletesong"){
            cin>>input;
            mp.playlist.deleteSong(input);
        }

        if(command == "searchsong"){
            cin>>input;
            mp.playlist.searchSong(input);
        }
        
        if(command == "showplaylist")   mp.playlist.showPlaylist();

        if(command == "addtoqueue"){
            cin>>input;
            auto song = mp.playlist.searchSong(input);
            if(song != nullptr) mp.queue.enqueue(*song);
        }

        if(command == "playnext") playNext(mp);

        if(command == "playprevious") playPrevious(mp);

        if(command == "showhistory")   mp.history.showHistory();

        if(command == "showqueue")   mp.queue.showQueue();
    }

    return 0;
}