
# Automatically generated Makefile
# Makefile-generator programmed by Hans de Nivelle, 2002


Flags = -Wpedantic -pedantic-errors -std=c++20
CPP = g++


main : Makefile   main.o frame.o uncheckedframe.o search.o 
	$(CPP) $(Flags) -o main   main.o frame.o uncheckedframe.o search.o 

main.o : Makefile   main.cpp   search.h frame.h move.h position.h uncheckedframe.h 
	$(CPP) -c $(Flags) main.cpp -o  main.o


frame.o : Makefile   frame.cpp   frame.h move.h position.h 
	$(CPP) -c $(Flags) frame.cpp -o  frame.o


uncheckedframe.o : Makefile   uncheckedframe.cpp   uncheckedframe.h move.h frame.h position.h 
	$(CPP) -c $(Flags) uncheckedframe.cpp -o  uncheckedframe.o


search.o : Makefile   search.cpp   search.h frame.h move.h position.h uncheckedframe.h 
	$(CPP) -c $(Flags) search.cpp -o  search.o


