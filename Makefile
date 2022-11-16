all:
	g++ -I src/deps -I src/deps/include -L src/deps/lib -o main src/*.cpp -lmingw32 -lSDL2Main -lSDL2