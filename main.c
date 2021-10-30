#include <stdio.h>
#include "Battle.h"

int main() {
    Player * player = initPlayer();
    Battle(100,player);
    Battle(100,player);
    return 0;
}