EXEC=a.out
OBJS=main.o multiThread.o


build: $(OBJS)
	g++ -o $(EXEC) $(OBJS) -lpthread

main.o: main.cpp multiThread.h
	g++ -c main.cpp -std=c++11 -lpthread

multiThread.o: multiThread.cpp multiThread.h
	g++ -c multiThread.cpp -std=c++11 -lpthread

clean:
	del $(OBJS)

run:
	./$(EXEC)
