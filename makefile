win-mingw-dev:
	gcc -o main.exe src/*.c -Iinclude -lcsfml-audio -lcsfml-graphics -lcsfml-window -lcsfml-system -w -g

mac-brew:
	gcc -o main.out src/*.c -Iinclude -I/opt/homebrew/include -L/opt/homebrew/lib -lcsfml-audio -lcsfml-graphics -lcsfml-window -lcsfml-system -w -g

dummy:
