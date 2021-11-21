#include "headers/Battle.h"
int main() {
    Monster ** tabmonster = initMonster();
    Weapons ** tabweapon = initWeapons();
    Armors ** tabarmor = initArmors();
    Player * player = initPlayer();

    while (player->currentHp != 0) {
        Battle(player,tabmonster,tabweapon,tabarmor);
    }
    
    return 0;
}