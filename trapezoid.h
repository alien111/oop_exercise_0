#ifndef D_TRIANGLE_H_
#define D_TRIANGLE_H_ 1

#include <algorithm>
#include <iostream>

#include "vertex.h"
#include "vector.h"

template<class T>
struct trapezoid {
	vertex<T> vertices[4];

	trapezoid(std::istream& is);

	vertex<double>  center() const;

	double area() const;
	void print(std::ostream& os) const;

};

template<class T>
trapezoid<T>::trapezoid(std::istream& is) {
	for(int i = 0; i < 4; ++i){
		is >> vertices[i];
	}

	if (isParallel(Vector< vertex<T> >(vertices[0], vertices[3]), Vector< vertex<T> >(vertices[1], vertices[2]))) {

	} else if (isParallel(Vector< vertex<T> >(vertices[0], vertices[2]), Vector< vertex<T> >(vertices[3], vertices[1]))) {

		vertex<T>  tmp;
		tmp = vertices[1];
		vertices[1] = vertices[3];
		vertices[3] = tmp;
		tmp = vertices[2];
		vertices[2] = vertices[3];
		vertices[3] = tmp;

	} else if (isParallel(Vector< vertex<T> >(vertices[0], vertices[2]), Vector< vertex<T> >(vertices[1], vertices[3]))) {

		vertex<T>  tmp;
		tmp = vertices[2];
		vertices[2] = vertices[3];
		vertices[3] = tmp;

	} else if (vertices[0] == vertices[1] || vertices[0] == vertices[2] || vertices[0] == vertices[3] || vertices[1] == vertices[2] || vertices[1] == vertices[3] || vertices[2] == vertices[3]) {
		throw std::logic_error("No points are able to be equal");
	} else {
		throw std::logic_error("At least 2 sides of trapeze must be parallel");
	}
}

template<class T>
double trapezoid<T>::area() const {

	double a = vertices[1].y - vertices[2].y;
    double b = vertices[2].x - vertices[1].x;
    double c = vertices[1].x * vertices[2].y - vertices[2].x * vertices[1].y;
    double height = (std::abs(a * vertices[0].x + b * vertices[0].y + c) / sqrt(a * a + b * b));
    return (Vector(vertices[0], vertices[1]).length() + Vector(vertices[2], vertices[3]).length()) * height / 2;
	
}

template<class T>
void trapezoid<T>::print(std::ostream& os) const {
	for(int i = 0; i < 4; ++i) {
		os << '[' << vertices[i] << ']';
		if(i + 1 != 4){
			os << ' ';
		}
	}
}


template<class T>
vertex<double> trapezoid<T>::center() const {
	vertex<double>  p;
	p.x = (vertices[0].x + vertices[1].x + vertices[2].x + vertices[3].x) / 4;
	p.y = (vertices[0].y + vertices[1].y + vertices[2].y + vertices[3].y) / 4;
	return p;
}


#endif // D_TRIANGLE_H_
