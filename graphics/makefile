all: libbgi.a libconio2.a

libbgi.a: drawing.o misc.o mouse.o palette.o text.o winbgi.o winthread.o file.o dibutil.o image.o winbgim.h graphics.h
	ar -rv libbgi.a drawing.o misc.o mouse.o palette.o text.o winthread.o winbgi.o file.o image.o dibutil.o 

libconio2.a: conio.o conio2.h
	ar -rv libconio2.a conio.o

clean:
	rm *.o  
	rm libbgi.a
	rm libconio2.a

CPPFLAGS = -c -O3 -fno-rtti -fno-exceptions

drawing.o: drawing.cpp winbgim.h winbgitypes.h
	g++ $(CPPFLAGS) drawing.cpp

misc.o: misc.cpp winbgim.h winbgitypes.h
	g++ $(CPPFLAGS) misc.cpp

conio.o: conio.c conio2.h
	gcc -O3 -c conio.c

mouse.o: mouse.cpp winbgim.h winbgitypes.h
	g++ $(CPPFLAGS) mouse.cpp

palette.o: palette.cpp winbgim.h winbgitypes.h
	g++ $(CPPFLAGS) palette.cpp

text.o: text.cpp winbgim.h winbgitypes.h
	g++ $(CPPFLAGS) text.cpp

winbgi.o: winbgi.cpp winbgim.h winbgitypes.h
	g++ $(CPPFLAGS) winbgi.cpp

winthread.o: winthread.cpp winbgim.h winbgitypes.h
	g++ $(CPPFLAGS) winthread.cpp

image.o: image.cpp winbgim.h winbgitypes.h
	g++ $(CPPFLAGS) image.cpp

dibutil.o: dibutil.cpp dibutil.h dibapi.h
	g++ $(CPPFLAGS) dibutil.cpp

file.o: file.cpp dibutil.h dibapi.h winbgitypes.h
	g++ $(CPPFLAGS) -c file.cpp

