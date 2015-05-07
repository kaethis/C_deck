#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string>
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

	/*  C A R D   D I A G R A M   (small)
	 * -----------------------------------
	 *                        1
	 * -------------01234567890123456-----
	 *    ascii[0]  ,---------------,
	 *    ascii[1]  | ##            |
	 *    ascii[2]  |               |
	 *    ascii[3]  |   *       *   |
	 *    ascii[4]  |   '   *   '   |
	 *    ascii[5]  |   *       *   |
	 *    ascii[6]  |   '   '   '   |
	 *    ascii[7]  |   *       *   |
	 *    ascii[8]  |   '   *   '   |
	 *    ascii[9]  |   *       *   |
	 *    ascii[10] |               |
	 *    ascii[11] |            ## |
	 *    ascii[12] '---------------'    */

	string  s;

	string ascii[13] =	{",---------------,\n",
				 "|               |\n",
				 "|               |\n",
				 "|               |\n",
				 "|               |\n",
				 "|               |\n",
				 "|               |\n",
				 "|               |\n",
				 "|               |\n",
				 "|               |\n",
				 "|               |\n",
				 "|               |\n",
				 "'---------------'\n"};

	switch(suit){

		case CLUBS:
				s = "\u2663";
				break;
		case DIAMONDS:
				s = "\u2666";
				break;
		case HEARTS:
				s = "\u2665";
				break;
		case SPADES:
				s = "\u2660";
				break;
	}

	switch (rank){

		case A:
				ascii[1].replace(2, 2, "A ");
				ascii[11].replace(13, 13, " A |\n");
				ascii[6].replace(8, 8, s+"       ");
				break;
		case 2:
				ascii[1].replace(2, 2, "2 ");
				ascii[11].replace(13, 13, " 2 |\n");
				ascii[4].replace(8, 8, s+"       ");
				ascii[8].replace(8, 8, s+"       ");
				break;
		case 3:
				ascii[1].replace(2, 2, "3 ");
				ascii[11].replace(13, 13, " 3 |\n");
				ascii[3].replace(8, 8, s+"       ");
				ascii[6].replace(8, 8, s+"       ");
				ascii[9].replace(8, 8, s+"       ");
				break;
		case 4:
				ascii[1].replace(2, 2, "4 ");
				ascii[11].replace(13, 13, " 4 |\n");
				ascii[3].replace(4, 9, s+"       "+s);
				ascii[9].replace(4, 9, s+"       "+s);
	
				break;
		case 5:
				ascii[1].replace(2, 2, "5 ");
				ascii[11].replace(13, 13, " 5 |\n");
				ascii[3].replace(4, 9, s+"       "+s);
				ascii[6].replace(8, 8, s+"       ");
				ascii[9].replace(4, 9, s+"       "+s);
				break;
		case 6:
				ascii[1].replace(2, 2, "6 ");
				ascii[11].replace(13, 13, " 6 |\n");
				ascii[3].replace(4, 9, s+"       "+s);
				ascii[6].replace(4, 9, s+"       "+s);
				ascii[9].replace(4, 9, s+"       "+s);
	
				break;
		case 7:
				ascii[1].replace(2, 2, "7 ");
				ascii[11].replace(13, 13, " 7 |\n");
				ascii[3].replace(4, 9, s+"       "+s);
				ascii[4].replace(8, 8, s+"       ");
				ascii[6].replace(4, 9, s+"       "+s);
				ascii[9].replace(4, 9, s+"       "+s);
				break;
		case 8:
				ascii[1].replace(2, 2, "8 ");
				ascii[11].replace(13, 13, " 8 |\n");
				ascii[3].replace(4, 9, s+"       "+s);
				ascii[4].replace(8, 8, s+"       ");
				ascii[6].replace(4, 9, s+"       "+s);
				ascii[8].replace(8, 8, s+"       ");
				ascii[9].replace(4, 9, s+"       "+s);
				break;
		case 9:
				ascii[1].replace(2, 2, "9 ");
				ascii[11].replace(13, 13, " 9 |\n");
				ascii[3].replace(4, 9, s+"       "+s);
				ascii[5].replace(4, 9, s+"       "+s);
				ascii[6].replace(8, 8, s+"       ");
				ascii[7].replace(4, 9, s+"       "+s);
				ascii[9].replace(4, 9, s+"       "+s);
				break;
		case 10:
				ascii[1].replace(2, 2, "10");
				ascii[11].replace(13, 13, "10 |\n");
				ascii[3].replace(4, 9, s+"       "+s);
				ascii[4].replace(8, 8, s+"       ");
				ascii[5].replace(4, 9, s+"       "+s);
				ascii[7].replace(4, 9, s+"       "+s);
				ascii[8].replace(8, 8, s+"       ");
				ascii[9].replace(4, 9, s+"       "+s);
				break;
		case J:
				ascii[1].replace(2, 2, "J ");
				ascii[11].replace(13, 13, " J |\n");
				break;
		case Q:
				ascii[1].replace(2, 2, "Q ");
				ascii[11].replace(13, 13, " Q |\n");
				break;
		case K:
				ascii[1].replace(2, 2, "K ");
				ascii[11].replace(13, 13, " K |\n");
				break;
	}

	cout << '\n';

	for(int i = 0; i <= 12; i++)
		cout << ascii[i];
}
