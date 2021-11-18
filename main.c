#include "headers/Monster.h"
#include "headers/Battle.h"
int main() {
    Monster ** tabmonster = initMonster();
    Player * player = initPlayer();

    while (player->currentHp != 0) {
        Battle(player,tabmonster);
    }
    
    return 0;
}