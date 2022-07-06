#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card {
public:
	int card;
	bool isShuffled;
	Card(int num) { card = num; isShuffled = false; }
};

inline std::ostream& operator<<(std::ostream& out, const Card c)
{
	return out << c << std::endl;
}
#endif