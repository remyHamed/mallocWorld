#ifndef Player_h
#define Player_h

struct Player {
    int x;
    int y;
    int beforePosition[2];
    enum orientation {
        top = 1,
        down = 2, 
        left = 3, 
        right = 4
    };
};
typedef struct  Player Player;

#endif