connectn.put: main.o board.o gamePlay.o player.o
		gcc -g -Wall -Werror -Wextra -o connectn.out main.o board.o gamePlay.o player.o

main.o: board.h gamePlay.h player.h main.c
		gcc -g -Wall -Werror -Wextra -c main.c

board.o: board.c board.h
		gcc -g -Wall -Werror -Wextra -c board.c

gamePlay.o: gamePlay.c gamePlay.h
		gcc -g -Wall -Werror -Wextra -c gamePlay.c

player.o: player.c player.h
		gcc -g -Wall -Werror -Wextra -c player.c

clean:
		rm -f *.o *.out