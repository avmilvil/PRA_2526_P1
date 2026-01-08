all: bin/testListArray bin/testNode bin/testListLinked Point2D.o bin/testPoint2D Shape.o Circle.o Rectangle.o Square.o Drawing.o bin/testCircle bin/testRectangle bin/testSquare bin/testDrawing

bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp ListArray.h

bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp Node.h

bin/testListLinked: testListLinked.cpp ListLinked.h List.h
	mkdir -p bin
	g++ -o bin/testListLinked testListLinked.cpp ListLinked.h

Point2D.o: Point2D.h Point2D.cpp
	g++ -c Point2D.cpp

bin/testPoint2D: testPoint2D.cpp Point2D.o
	g++ -c testPoint2D.cpp
	mkdir -p bin
	g++ -o bin/testPoint2D testPoint2D.o Point2D.o

Shape.o: Shape.cpp Shape.h
	g++ -c Shape.cpp

Circle.o: Circle.cpp Circle.h
	g++ -c Circle.cpp

Rectangle.o: Rectangle.cpp Rectangle.h
	g++ -c Rectangle.cpp

Square.o: Square.cpp Square.h
	g++ -c Square.cpp

Drawing.o: Drawing.cpp Drawing.h
	g++ -c Drawing.cpp

bin/testCircle: testCircle.cpp Circle.o Shape.o Point2D.o
	g++ -c testCircle.cpp
	mkdir -p bin
	g++ -o bin/testCircle testCircle.o Circle.o Shape.o Point2D.o

bin/testRectangle: testRectangle.cpp Rectangle.o Shape.o Point2D.o
	g++ -c testRectangle.cpp
	mkdir -p bin
	g++ -o bin/testRectangle testRectangle.o Rectangle.o Shape.o Point2D.o

bin/testSquare: testSquare.cpp Rectangle.o Square.o Point2D.o Shape.o
	g++ -c testSquare.cpp
	mkdir -p bin
	g++ -o bin/testSquare testSquare.o Rectangle.o Square.o Point2D.o Shape.o

bin/testDrawing: testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o
	mkdir -p bin
	g++ -o bin/testDrawing testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o
clean:
	rm -r *.o *.gch bin

test: all
	./bin/testListArray
	./bin/testNode
	./bin/testListLinked
	./bin/testPoint2D
	./bin/testCircle
	./bin/testRectangle
	./bin/testSquare
	./bin/testDrawing
