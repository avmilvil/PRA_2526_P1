#include "Square.h"
#include <cmath>
#include <iostream>

bool Square::check(Point2D* vertices) {
	double d01 = Point2D::distance(vertices[0], vertices[1]);
    	double d12 = Point2D::distance(vertices[1], vertices[2]);
    	double d23 = Point2D::distance(vertices[2], vertices[3]);
    	double d30 = Point2D::distance(vertices[3], vertices[0]);

    	return (d01 == d12) && (d12 == d23) && (d23 == d30);
}

Square::Square() : Rectangle() {
    	Point2D vertices[Rectangle::N_VERTICES] = {
        	Point2D(-1,1),
        	Point2D(1,1),
        	Point2D(1,-1),
        	Point2D(-1,-1)
    	};

    	this->set_vertices(vertices);
}

Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices) {
    	if (!check(vertices)) {
        	throw std::invalid_argument("Los vertices no forman un cuadrado válido.");
    	}

    	this->set_vertices(vertices);
}

void Square::set_vertices(Point2D* vertices) {
    	if (!check(vertices)) {
        	throw std::invalid_argument("Los vertices no forman un cuadrado válido.");
    	}

    	for (int i = 0; i < Rectangle::N_VERTICES; i++) {
        	this->vs[i] = vertices[i];
    	}
}

void Square::print() {
    	std::cout << *this;
}

std::ostream& operator<<(std::ostream &out, const Square &s) {
    	out << "[Square: color = " << s.color << "; ";
    	for (int i = 0; i < Rectangle::N_VERTICES; i++) {
        	out << "v" << i << " = " << s.vs[i];
        	if (i != Rectangle::N_VERTICES - 1){
		       	out << "; ";
		}
    	}

    	out << "]";
    	return out;
}

