OBJECTS = person.o dequeue.o main.o
HEADERS = person.h dequeue.h
Project1: $(OBJECTS)
	g++ $^ -o $@

%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@

clean:
	rm -i *.o Project1

run:
	./Project1
