#include <iostream>
//#include "MathfStuffs.h"
#include "Card.h"
#include "Deck.h"




int main()
{
    std::cout << 'a' << std::endl;
    Card c1(1);
    Card c2(2);
    Card c3(3);
    Card c4(4);
    Card c5(5);
    Card c6(6);
    Card c7(7);
    Card c8(8);
    Card c9(9);
    Card c10(10);
	std::cout << 'b' << std::endl;
    Deck dick(c1, c2, c3, c4, c5, c6, c7, c8, c9, c10);
    dick.Shuffle();
	std::cout << 'c' << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << 'd';
        std::cout << dick[i].card << std::endl;
    }
    return 0;
}


