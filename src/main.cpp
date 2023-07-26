/* # Rules of blackjack
 * There is a minimum bet: $5
 * There is a maximum bet: $100
 * Player decides bet before hand
 * # Events of hand
 * Lose: lose bet
 * Win: if bet $10, keep $10 + win $10
 * Blackjack (natural): win 1.5 times bet, if bet $10, keep $10 + win $15
 * Push: win nothing, lose nothing
 * # Objective
 * Score higher than dealer without going over 21
 * 2-10: face value
 * J,Q,K: 10
 * Ace: 1 or 11 (player's choice)
 * Two cards are dealt face up to the player
 * One card is dealt face down and one card is dealt face up to the dealer
 * Player goes first
 * If player goes over 21, they immediately lose
 * # Choices
 * Stand
 * Hit
 * When player is finished, it is the dealer's turn and the hole card is flipped over
 * Dealer must hit if hand is less than 17 (soft or hard), go with hard
 * # Side rules, only apply to the first deal
 * Ignoring insurance for this game and ignoring surrender option
 * Splitting two same value hand
 * Double down
 */

#include <climits>
#include <cstdlib>
#include <time.h>
#include "deck.h"
#include "player.h"

void deal_hand(Deck &deck, Player &player) {
  int rand_int = (rand() % 10) + 1;
  Card card = deck.remove_card(rand_int);
  player.set_hand(card);
}

void create_table() {
  int width = 80;
  int height = 20;
  for (int i = 0; i < width; i++) {
    std::cout << "-";
  }
  std::cout << "\n";

  for (int j = 0; j < height; j++) {
    for (int i = 0; i < width; i++) {
      if (i == 0 || i == width - 1) {
        std::cout << "|";
      }
      else {
        std::cout << " ";
      }
    }
  std::cout << "\n";
  }

  for (int i = 0; i < width; i++) {
    std::cout << "-";
  }
  std::cout << "\n";
}

int main() {
  srand(time(0));
  int min_bet = 5;
  int max_bet = 100;
  int bet = 0;
  Deck deck;
  Player player;
  Player dealer(0);

  // Welcome message
  create_table();
  std::cout << "Welcome to Blackjack!\n";
  std::cout << "The minimum bet is $5 and the maximum bet is $100.\n";
  std::cout << "You will start with an initial buyin of " << player.get_buyin() 
    << ".\n";

  // Get player bet
  do {
    std::cout << "Enter your bet: ";
    std::cin >> bet;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(INT_MAX, '\n');
    }
  } while (bet < 5 || bet > 100);

  player.place_bet(bet);
  std::cout << "You bet: " << player.get_bet() << '\n';

  // Deal hand
  deal_hand(deck, player);
  deal_hand(deck, player);
  deal_hand(deck, dealer);
  deal_hand(deck, dealer);

  // shuffle deck at the end of a round if necessary
}
