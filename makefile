win-mingw-dev:
	gcc -o main src/*.c -Iinclude -lcsfml-audio -lcsfml-graphics -lcsfml-window -lcsfml-system -w -g

mac-brew:
	gcc -o main src/*.c -Iinclude -I/opt/homebrew/include -L/opt/homebrew/lib -lcsfml-audio -lcsfml-graphics -lcsfml-window -lcsfml-system -w -g

dummy:
