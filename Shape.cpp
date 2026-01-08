#include "Shape.h"
bool Shape::isValidColor(const std::string& color){
	return color == "red" || color == "blue" || color == "green";
}

Shape::Shape() : color("red"){}
Shape::Shape(std::string color){
	if (!isValidColor(color)){	
		throw std::invalid_argument("El color no es válido.");
	}

	this->color = color;
}

std::string Shape::get_color() const {
	return color;
}

void Shape::set_color(std::string c){
	if(!isValidColor(c)){
		throw std::invalid_argument("El color no es válido.");
	}

	this->color = c;
}
