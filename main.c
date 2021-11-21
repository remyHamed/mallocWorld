#include "headers/Battle.h"
#include "headers/Save.h"
int main() {
    Monster ** tabmonster = initMonster();
    Weapons ** tabweapon = initWeapons();
    Armors ** tabarmor = initArmors();
    Player * player = initPlayer();

    player = ResumePlayer();
    printf("%d\n",player->currentHp);
    Battle(player,tabmonster,tabweapon,tabarmor);
    SavePlayer(player);
    
    free (tabweapon);
    free (tabmonster);
    free (tabarmor);
    free (player);
    return 0;
}