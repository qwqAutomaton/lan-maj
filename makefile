compiler = "/usr/bin/g++"
asio = "/home/wzms/asio-1.18.2/include"
linker = "-lpthread"


src/bin/main: src/bin/main.o src/bin/data.o
	$(compiler) $^ -o $@ $(linker)

src/bin/data.o: src/data.cpp
	$(compiler) $^ -c -o $@

src/bin/main.o: src/main.cpp
	$(compiler) $^ -c -o $@ -I$(asio)

.PHONY: clear
clear:
	-rm -rf src/bin
	mkdir src/bin

.PHONY: run
run:
	-src/bin/main

