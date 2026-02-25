win-mingw-dev:
	gcc -o main src/*.c -Iinclude -lcsfml-audio -lcsfml-graphics -lcsfml-window -lcsfml-system -w -g

dummy:
