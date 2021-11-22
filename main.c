#include "headers/Battle.h"
#include "headers/Save.h"
int main() {
    Monster ** tabmonster = initMonster();
    Weapons ** tabweapon = initWeapons();
    Armors ** tabarmor = initArmors();
    Player * player = initPlayer();

    player = Resume();
    printf("%d\n",player->currentHp);
    printf("%d\n",player->maxHp);
    printf("%d\n",player->level);
    printf("%d\n",player->exp);
    printf("%d\n",player->maxExp);
    Battle(player,tabmonster,tabweapon,tabarmor);
    Save(player);
    
    free (tabweapon);
    free (tabmonster);
    free (tabarmor);
    free (player);
    return 0;
}