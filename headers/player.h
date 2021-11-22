#ifndef Player_h
#define Player_h

struct Player {
    int level;
    int value;
    int x;
    int y;
    int orientation;// ANCHOR 
                    // 1 haut
                    // 2 gauche
                    // 3 droite
                    // 4 bas
};
typedef struct  Player Player;

#endif