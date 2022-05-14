#include "player.h"

void players_init(Players &players){
    int i;
    for(i = 0; i < player_num; i++){
        players.push_back(Player());
    }
}
