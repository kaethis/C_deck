#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* AUTHOR:	Matt W. Martin
 *		kaethis@tasmantis.net
 *
 * MODIFIED:	05-May-2015, @kaethis
 */

typedef int RANK;
typedef int SUIT;

class Card{
// This CLASS represents a French playing card.

	RANK  rank;
	SUIT  suit;

  private:
	const static RANK  A =	 1;
	const static RANK  J =	11;
	const static RANK  Q = 	12;
	const static RANK  K = 	13;

	const static SUIT  CLUBS =	0;
	const static SUIT  DIAMONDS =	1;
	const static SUIT  HEARTS =	2;
	const static SUIT  SPADES =	3;

  public:
	Card(RANK r, SUIT s) : rank(r), suit(s){}		// CONSTRUCTOR.

	void print(void);					/* Displays Card in
								 * console window. */
};

void Card::print(){
// This METHOD ... 

	switch (rank){

		case A:
				cout << "ACE\n";
				break;
		case 2:
				cout << "TWO\n";
				break;
		case 3:
				cout << "THREE\n";
				break;
		case 4:
				cout << "FOUR\n";
				break;
		case 5:
				cout << "FIVE\n";
				break;
		case 6:
				cout << "SIX\n";
				break;
		case 7:
				cout << "SEVEN\n";
				break;
		case 8:
				cout << "EIGHT\n";
				break;
		case 9:
				cout << "NINE\n";
				break;
		case 10:
				cout << "TEN\n";
				break;
		case J:
				cout << "JACK\n";
				break;
		case Q:
				cout << "QUEEN\n";
				break;
		case K:
				cout << "KING\n";
				break;
	}

	switch(suit){

		case CLUBS:
				cout << "\u2663\n";
				break;
		case DIAMONDS:
				cout << "\u2666\n";
				break;
		case HEARTS:
				cout << "\u2665\n";
				break;
		case SPADES:
				cout << "\u2660\n";
				break;
	}
}
