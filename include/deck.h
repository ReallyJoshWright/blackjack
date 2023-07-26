#pragma once

#include <iostream>
#include <string>

struct Card {
  std::string suit;
  std::string face_value;
  int value;
  bool removed;
};

class Deck {
  public:
    Deck();
    ~Deck();
    void print_deck();
    void shuffle_deck();
    Card remove_card(int);
    int size();

  private:
    Card card[52];
    std::string suits[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};
    std::string face_values[13] = {"1", "2", "3", "4", "5", "6", "7", "8", \
      "9", "10", "Jack", "Queen", "King"};
    int values[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
};
