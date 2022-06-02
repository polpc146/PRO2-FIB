OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o AreaDeAlmacenaje.o AreaDeEspera.o Contenedor.o Segmento.o TerminalDeContenedoresDeCarga.o Ubicacion.o
	g++ -o program.exe program.o AreaDeAlmacenaje.o AreaDeEspera.o Contenedor.o Segmento.o TerminalDeContenedoresDeCarga.o Ubicacion.o
	rm *.o

program.o: program.cc AreaDeAlmacenaje.hh AreaDeEspera.hh Contenedor.hh Segmento.hh TerminalDeContenedoresDeCarga.hh Ubicacion.hh
	g++ -c program.cc $(OPCIONS)

Contenedor.o: Contenedor.cc Contenedor.hh
	g++ -c Contenedor.cc $(OPCIONS)

Ubicacion.o: Ubicacion.cc Ubicacion.hh
	g++ -c Ubicacion.cc $(OPCIONS)

Segmento.o: Segmento.cc Segmento.hh Ubicacion.hh
	g++ -c Segmento.cc $(OPCIONS)

AreaDeEspera.o: AreaDeEspera.cc AreaDeEspera.hh Contenedor.hh Segmento.hh Ubicacion.hh
	g++ -c AreaDeEspera.cc $(OPCIONS)

AreaDeAlmacenaje.o: AreaDeAlmacenaje.cc AreaDeAlmacenaje.hh Contenedor.hh Segmento.hh Ubicacion.hh
	g++ -c AreaDeAlmacenaje.cc $(OPCIONS)

TerminalDeContenedoresDeCarga.o: TerminalDeContenedoresDeCarga.cc TerminalDeContenedoresDeCarga.hh AreaDeEspera.hh AreaDeAlmacenaje.hh Contenedor.hh Segmento.hh Ubicacion.hh
	g++ -c TerminalDeContenedoresDeCarga.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch
