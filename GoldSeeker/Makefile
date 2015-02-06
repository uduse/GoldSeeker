GoldSeeker.out: GoldSeeker.o Cave.o Player.o
	g++ -Wall -g -o GoldSeeker.out -std=c++11 GoldSeeker.o Cave.o Player.o

GoldSeeker.o: GoldSeeker.cpp GoldSeeker.h Player.h Cave.h Constants.h
	g++ -Wall -g -c -std=c++11 GoldSeeker.cpp
	
Cave.o: Cave.cpp Cave.h GoldSeeker.h Player.h Constants.h
	g++ -Wall -g -c -std=c++11 Cave.cpp

Player.o: Player.cpp Cave.h GoldSeeker.h Player.h  Constants.h
	g++ -Wall -g -c -std=c++11 Player.cpp 
	
clean:
	rm -f GoldSeeker.out GoldSeeker.o Cave.o Player.o core
