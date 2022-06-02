/// 我确认本程序完全由本人独立完成。
/// 姓名：周懿
/// 学号：2021013053
/// 时间：2022年6月1日


#include "player.h"

void players_init(Players &players){
    int i;
    for(i = 0; i < player_num; i++){
        players.push_back(Player());
    }
}
