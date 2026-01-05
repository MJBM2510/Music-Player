#include <iostream>
#include "Library's/history_stack.hpp"
#include "Library's/song_repository.hpp"
#include "Library's/play_queue.hpp"

using namespace std;

struct MusicPlayer{
    HistoryStack history;
    PlayQueue queue;
    SongRepository playlist;
};