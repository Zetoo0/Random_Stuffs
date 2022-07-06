#ifndef DECK_H
#define DECK_H

#include <iostream>

#include "Card.h"
#include "MathfStuffs.h"

class Deck {
public:
	Card deck[10];
	Deck(Card c1, Card c2, Card c3, Card c4, Card c5, Card c6, Card c7, Card c8, Card c9, Card c10) : deck{ c1, c2, c3, c4, c5, c6, c7, c8, c9, c10 } {}

	Card operator[](int i) { return deck[i]; }

	inline Deck Shuffle()
	{
		int nowPlace;
		int nowN;
		for (int i = 0; i < 10; i++) {
			nowPlace = rand(0, 9);
			nowN = deck[i].card;
			if (!deck[i].isShuffled && deck[nowPlace].card != deck[i].card) {
				deck[i].card = deck[nowPlace].card;
				deck[nowPlace].card = nowN;
				deck[i].isShuffled = true;
			}
		}
		return *this;
	}
};

inline std::ostream& operator<<(std::ostream& out, const Deck d)
{
	return out << d.deck[0] << ' ' << d.deck[1] << ' ' << d.deck[2] << ' ' << d.deck[3] << ' ' << d.deck[4] << ' ' << d.deck[5] << ' ' << d.deck[6] << ' ' << d.deck[7] << ' ' << d.deck[8] << ' ' << d.deck[10] << std::endl;
}
#endif