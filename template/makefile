

build: template.o List.o
	g++ template.o List.o -o a.out

template.o:
	g++ -c template.cpp -o template.o

List.o:
	g++ -c List.cpp -o List.o

run:
	./a.out

clean:
	rm -rf *.o a.out
