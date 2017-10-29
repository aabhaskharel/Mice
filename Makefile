CXXFLAGS += --std=c++11

all: div main
rebuild: div clean main

debug: CXXFLAGS += -g
debug: rebuild

main:
	$(CXX) $(CXXFLAGS) -o mice main.cpp items.cpp controller.cpp main_window.cpp manager.cpp dialogs.cpp help.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
	./mice
main.o: main.cpp 
	$(CXX) $(CXXFLAGS) -c main.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
items.o: items.cpp *.h
	$(CXX) $(CXXFLAGS) -c items.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
manager.o: manager.cpp *.h
	$(CXX) $(CXXFLAGS) -c manager.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs` 
dialogs.o: dialogs.cpp *.h
	$(CXX) $(CXXFLAGS) -c dialogs.o `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs` 
controller.o: controller.cpp *.h
	$(CXX) $(CXXFLAGS) -c controller.o `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs` 
help.o: help.cpp
	$(CXX) $(CXXFLAGS) -c help.o `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs` 
main_window.o:	main_window.cpp *.h
	$(CXX) $(CXXFLAGS) -c main_window.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs` 
clean:
	-rm -f *.o *~ mice
	
div:
	@echo
	@echo 'X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-'
	@echo '-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X'
	@echo 'X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-'
	@echo '-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X'
	@echo

	

