#include "deck.h"

Deck::Deck() {
  shuffle_deck();
}

Deck::~Deck() {
}

void Deck::print_deck() {
  for (int i = 0; i < 52; i++) {
    std::cout << card[i].suit << " : " << card[i].face_value << " : " 
      << card[i].value << " : " << card[i].removed << '\n';
  }
}

void Deck::shuffle_deck() {
  int counter = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 13; j++) {
      card[counter].suit = suits[i];
      card[counter].face_value = face_values[j];
      card[counter].value = values[j];
      card[counter].removed = false;
      counter += 1;
    }
  }
}

Card Deck::remove_card(int rem_card) {
  Card return_card;
  for (int i = 0; i < 52; i++) {
    if (card[i].value == rem_card) {
      card[i].removed = true;
      return_card = card[i];
      break;
    }
  }
  return return_card;
}

int Deck::size() {
  int count = 0;
  for (int i = 0; i < 52; i++) {
    if (card[i].removed == false) {
      count += 1;
    }
  }
  return count;
}
