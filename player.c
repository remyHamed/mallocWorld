#include "player.h"

player* creatPlayer() {
    player * babyPlayer = malloc(sizeof(player));
    babyPlayer->currentHp = 100;
    return babyPlayer;
}