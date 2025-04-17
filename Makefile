debug: build
	echo "Start debugging proccess..."
	gdb ./target/btree
	
run: build
	./target/btree

build:
	echo "Building..."
	mkdir -p target/
	gcc -std=c99 -Werror -Wall -g src/btree.c -o target/btree

clean:
	rm -rf target/

