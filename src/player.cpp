#include "player.h"

Player::Player() {
  buyin = 1000;
  bet = 0;
  action = "";
  for (int i = 0; i < 10; i++) {
    hand[i].suit = "";
    hand[i].face_value = "";
    hand[i].value = -1;
    hand[i].removed = true;
  }
}

Player::Player(int buyin) {
  this->buyin = buyin;
  bet = 0;
  action = "";
  for (int i = 0; i < 10; i++) {
    hand[i].suit = "";
    hand[i].face_value = "";
    hand[i].value = -1;
    hand[i].removed = true;
  }
}

Player::~Player() {
}

int Player::get_buyin() {
  return buyin;
}

void Player::set_buyin(int buyin) {
  this->buyin = buyin;
}

void Player::place_bet(int bet) {
  this->bet = bet;
}

int Player::get_bet() {
  return bet;
}

Card* Player::get_hand() {
  return hand;
}

void Player::set_hand(Card hand) {
  for (int i = 0; i < 10; i++) {
    if (this->hand[i].value == -1) {
      this->hand[i] = hand;
      break;
    }
  }
}

std::string Player::get_action() {
  return action;
}

void Player::set_action(std::string action) {
  this->action = action;
}
