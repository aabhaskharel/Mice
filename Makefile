all:
	g++ --std=c++11 -o mice main.cpp controller.cpp main_window.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
	./mice
