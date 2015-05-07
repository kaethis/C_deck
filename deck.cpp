#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <deque>
#include "card.cpp"
using namespace std;

/* AUTHOR:	Matt W. Martin
 *		kaethis@tasmantis.net
 *
 * MODIFIED:	05-May-2015, @kaethis
 */

class Deck{
// This CLASS represents a standard deck of 52 French playing cards.

	deque<Card>* cards;

  private:
	const static bool  EMPTY = false;

  public:
	Deck(void){ Deck(!EMPTY); }				// CONSTRUCTOR.
	Deck(bool);						// "  "  "  " .
	void free(void){ delete cards; }			// DESTRUCTOR.

	int getSize(void){ return cards -> size(); }		/* Return number of
								 * Card elements.  */

	bool isEmpty(void){ return cards -> empty(); }		/* Test if container
								 * is EMPTY. 	   */

	Card& peek(void){ return cards -> front(); }		// Access top Card.

	void deal(Card card){ cards -> push_front(card); }	/* Add Card to top of
								 * Deck. 	   */

	Card draw(void);					// Return top Card.

	void shuffle(void);					/* Shuffle elements
								 * in Deck.        */
};

Deck::Deck(bool build){
/* If argument passed is TRUE, this CONSTRUCTOR  builds 52 instances of a Card and
 * assigns each of them to the Deck.  If FALSE (or EMPTY), the Deck contains no
 * elements.*/

	cards = new deque<Card>;

	if(isEmpty())
		cout << "DEBUG: THIS DECK IS CURRENTLY EMPTY!\n";

	if(build)
	// If TRUE (i.e., not EMPTY), construct Deck of Cards:

		for(SUIT s = 0; s <= 3; s++)
		// (i.e., CLUBS, DIAMONDS, HEARTS, and SPADES.)

			for(RANK r = 1; r <= 13; r++){
			// (i.e., ascending from ACE to KING.)

				Card  card = Card(r, s);

				deal(card);

				peek().print();	// DEBUG: Print Card just dealt.
			}

	if(!isEmpty())
		cout << "DEBUG: THIS DECK NOW CONTAINS " << getSize() << " CARDS!\n";
}

Card Deck::draw(){

	Card  card = cards -> front();

	cards -> pop_front();

	return card;
}

void Deck::shuffle(){

}

int main(){

	Deck  deck;

	cout << "\nDEBUG: NOW DRAWING CARDS FROM TOP OF DECK:\n";

	while(!deck.isEmpty()){
	// While there still remain Card elements in Deck...

		cout << deck.getSize();		// Get current size of Deck.

		Card  card = deck.draw();	// Draw top Card.

		cout << '\n';

		card.print();			// Display Card in console.

		cout << '\n';
	}

	deck.free();

	return 0;
}
