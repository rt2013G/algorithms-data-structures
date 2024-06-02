build:
	@g++ -O3 src/*.cpp -o bin/out
run: build
	@./bin/out