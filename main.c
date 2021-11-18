#include "Monster.h"
#include "Battle.h"
int main() {
    Monster ** tabmonster = initMonster();
    Player * player = initPlayer();
    Battle(1,player,tabmonster);
    return 0;
}