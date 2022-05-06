#include "player.h"

 void Players_Init(Players& players){
     for(int i = 0;i < player_num; i++) players.push_back(Player());
 }









std::shared_ptr<Players> Players_Init(){
    std::shared_ptr<Players> ps = std::make_shared<Players>();
    for(int i = 0; i < player_num; i++)
        ps->push_back(Player());
    return ps;
}
