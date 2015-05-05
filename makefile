deck: deck.o
	g++ deck.o -g -o deck

deck.o: card.cpp deck.cpp
	g++ -g -c card.cpp deck.cpp

clean:
	rm *.o deck
