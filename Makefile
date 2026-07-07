.PHONY: all build run clean # even if build/ exists, still runs

all: build

build:
	mkdir -p build && \
	cd build && \
	cmake .. && \
	cmake --build . && \
	cp ./make_project ../mp

clean:
	rm -rf build/ mp test/*
