EXEC=a.out
OBJS=main.o help.o
GPP11=g++ -std=c++11

build: $(OBJS)
	$(GPP11) -o $(EXEC) $(OBJS)

main.o: src/main.cpp src/help.h
	$(GPP11) -c src/main.cpp

help.o: src/help.cpp src/help.h
	$(GPP11) -c src/help.cpp

clean:
	rm $(OBJS) $(EXEC)

run:
	./$(EXEC)
