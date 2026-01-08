#include "Drawing.h"
#include "Circle.h"
#include "Square.h"
#include <iostream>
#include <typeinfo>

Drawing::Drawing() {
	shapes = new ListArray<Shape*>();
}

Drawing::~Drawing() {
    	for (int i = 0; i < shapes->size(); i++) {
        	delete shapes->get(i); 
    	}

    	delete shapes;
}

void Drawing::add_front(Shape* shape) {
    	shapes->prepend(shape);
}

void Drawing::add_back(Shape* shape) {
    	shapes->append(shape);
}

void Drawing::print_all() const {
	std::cout << "Drawing contents:" << std::endl;
    	for (int i = 0; i < shapes->size(); i++) {
        	shapes->get(i)->print(); 
        	std::cout << std::endl;
    	}
}

// Área de todos los círculos
double Drawing::get_area_all_circles() const {
    	double total = 0.0;
    	for (int i = 0; i < shapes->size(); i++) {
        	Circle* c = dynamic_cast<Circle*>(shapes->get(i));
        	if (c != nullptr) {
            		total += c->area();
        	}
    	}
    	return total;
}

// Mover todos los cuadrados
void Drawing::move_squares(double incX, double incY) {
    	for (int i = 0; i < shapes->size(); i++) {
        	Square* s = dynamic_cast<Square*>(shapes->get(i));
        	if (s != nullptr) {
            		s->translate(incX, incY);
        	}
    	}
}

