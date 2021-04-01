networkSim : obj/main.o obj/debugger.o obj/client.o
	g++ -o networkSim obj/main.o obj/debugger.o obj/client.o -pthread

obj/main.o : 
	g++ -c src/main.cpp  -I headers -o obj/main.o

obj/debugger.o :
	g++ -c src/debugger.cpp  -I headers -o obj/debugger.o

obj/client.o:
	g++ -c src/client.cpp -I headers -o obj/client.o

clean:
	rm -frv obj
	mkdir obj
	rm -f drc

run: networkSim
	./networkSim