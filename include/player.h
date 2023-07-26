#pragma once

#include "deck.h"

class Player {
  public:
    Player();
    Player(int);
    ~Player();
    int get_buyin();
    void set_buyin(int);
    void place_bet(int);
    int get_bet();
    Card* get_hand();
    void set_hand(Card);
    std::string get_action();
    void set_action(std::string);

  private:
    int buyin;
    int bet;
    Card hand[10];
    std::string action;
};
