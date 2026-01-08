#include "Rectangle.h"
#include <cmath>
#include <iostream>

bool Rectangle::check(Point2D* vertices) {
	double d01 = Point2D::distance(vertices[0], vertices[1]);
	double d23 = Point2D::distance(vertices[2], vertices[3]);
	double d12 = Point2D::distance(vertices[1], vertices[2]);
	double d30 = Point2D::distance(vertices[3], vertices[0]);

    	return (d01 == d23) && (d12 == d30);
}

Rectangle::Rectangle() : Shape() {
    	vs = new Point2D[N_VERTICES]{
        	Point2D(-1, 0.5),
        	Point2D(1, 0.5),
        	Point2D(1, -0.5),
        	Point2D(-1, -0.5)
    	};
}

Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color) {
    	if (!check(vertices)){
        	throw std::invalid_argument("Los vertices no forman un rectángulo válido.");
    	}

    	vs = new Point2D[N_VERTICES];
    	for (int i = 0; i < N_VERTICES; i++){
        	vs[i] = vertices[i];
	}
}

Rectangle::Rectangle(const Rectangle &r) : Shape(r.get_color()) {
    	vs = new Point2D[N_VERTICES];
    	for (int i = 0; i < N_VERTICES; i++){
        	vs[i] = r.vs[i];
	}
}

Rectangle::~Rectangle() {
	delete[] vs;
}

Point2D Rectangle::get_vertex(int ind) const {
	if (ind < 0 || ind >= N_VERTICES){
        	throw std::out_of_range("Out of range!");
	}

    	return vs[ind];
}

Point2D Rectangle::operator[](int ind) const {
	return get_vertex(ind);
}

void Rectangle::set_vertices(Point2D* vertices) {
   	if (!check(vertices)){
        	throw std::invalid_argument("Provided vertices do not build a valid rectangle!");
	}

    	for (int i = 0; i < N_VERTICES; i++){
        	vs[i] = vertices[i];
	}
}

Rectangle& Rectangle::operator=(const Rectangle &r) {
    	if (this != &r) {
        	Shape::set_color(r.get_color());
        	for (int i = 0; i < N_VERTICES; i++){
            		vs[i] = r.vs[i];
		}
    	}

    	return *this;
}

double Rectangle::area() const {
    	double base = Point2D::distance(vs[0], vs[1]);
    	double altura = Point2D::distance(vs[0], vs[3]);
    	return base * altura;
}

double Rectangle::perimeter() const {
    	double base = Point2D::distance(vs[0], vs[1]);
    	double altura = Point2D::distance(vs[0], vs[3]);
    	return 2 * (base + altura);
}

void Rectangle::translate(double incX, double incY) {
    	for (int i = 0; i < N_VERTICES; i++) {
        	vs[i].x += incX;
        	vs[i].y += incY;
    	}
}

void Rectangle::print() {
    	std::cout << *this;
}

std::ostream& operator<<(std::ostream &out, const Rectangle &r) {
    	out << "[Rectangle: color = " << r.color << "; ";
    	for (int i = 0; i < Rectangle::N_VERTICES; i++) {
        	out << "v" << i << " = " << r.vs[i];
        	if (i != Rectangle::N_VERTICES - 1){
			out << "; ";
		}
    	}

	out << "]";
    	return out;
}

