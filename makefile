all: clean build run

build:
	cd test && python3 build_tests.py

clean:
	rm -rf ./bin

run:
	cd bin && ./la_test.bin