#ifndef D_RHOMBUS_H_
#define D_RHOMBUS_H_ 1

#include <algorithm>
#include <iostream>

#include "vertex.h"
#include "vector.h"

template<class T>
struct rhombus {
	vertex<T>  vertices[4];

	rhombus(std::istream& is);

	vertex<double>  center() const;

	double area() const;
	void print() const;

};

template<class T>
rhombus<T>::rhombus(std::istream& is) {
	for(int i = 0; i < 4; ++i){
		is >> vertices[i];
	}

	if (Vector< vertex<T> >(vertices[0], vertices[1]).length() == Vector< vertex<T> >(vertices[1], vertices[2]).length() && Vector< vertex<T> >(vertices[1], vertices[2]).length() == Vector< vertex<T> >(vertices[2], vertices[3]).length()
	 && Vector< vertex<T> >(vertices[0], vertices[1]).length() == Vector< vertex<T> >(vertices[0], vertices[3]).length()) {

	} else if (Vector< vertex<T> >(vertices[0], vertices[1]).length() == Vector< vertex<T> >(vertices[1], vertices[3]).length() && Vector< vertex<T> >(vertices[1], vertices[3]).length() == Vector< vertex<T> >(vertices[2], vertices[3]).length()
	 && Vector< vertex<T> >(vertices[0], vertices[1]).length() == Vector< vertex<T> >(vertices[0], vertices[2]).length()) {
		vertex<T> tmp = vertices[3];
		vertices[3] = vertices[2];
		vertices[2] = tmp;
	} else if (Vector< vertex<T> >(vertices[0], vertices[2]).length() == Vector< vertex<T> >(vertices[3], vertices[2]).length() && Vector< vertex<T> >(vertices[3], vertices[2]).length() == Vector< vertex<T> >(vertices[1], vertices[3]).length()
	 && Vector< vertex<T> >(vertices[0], vertices[1]).length() == Vector< vertex<T> >(vertices[0], vertices[2]).length()) {
		vertex<T> tmp = vertices[3];
		vertices[3] = vertices[2];
		vertices[2] = tmp;
	} else if (vertices[0] == vertices[1] || vertices[0] == vertices[2] || vertices[0] == vertices[3] || vertices[1] == vertices[2] || vertices[1] == vertices[3] || vertices[2] == vertices[3]) {
		throw std::logic_error("No points are able to be equal");
	} else {
		throw std::logic_error("This is not a Rhombus, sides are not equal");
	}

	
	Vector< vertex<T> > v1(vertices[0], vertices[1]);
	Vector< vertex<T> > v2(vertices[1], vertices[2]);
	Vector< vertex<T> > v3(vertices[2], vertices[3]);
	Vector< vertex<T> > v4(vertices[3], vertices[0]);

	double cos1 = v1 * v2 / (v1.length() * v2.length());
	double cos2 = v2 * v3 / (v2.length() * v3.length());
	double cos3 = v3 * v4 / (v3.length() * v4.length());
	double cos4 = v1 * v4 / (v1.length() * v4.length());

	if (cos1 != cos3 || cos2 != cos4) {
		throw std::logic_error("This is not a Rhombus, opposite angles are not equal");
	}
}

template<class T>
double rhombus<T>::area() const {
	return Vector< vertex<T> >(vertices[0], vertices[2]).length() * Vector< vertex<T> >(vertices[1], vertices[3]).length() / 2;
}

template<class T>
void rhombus<T>::print() const {
	
	std::cout << vertices[0] << vertices[1] << vertices[2] << vertices[3] << '\n';
}

template<class T>
vertex<double> rhombus<T>::center() const {
	vertex<double> p;
	p.x = (vertices[0].x + vertices[1].x + vertices[2].x + vertices[3].x) / 4;
	p.y = (vertices[0].y + vertices[1].y + vertices[2].y + vertices[3].y) / 4;
	return p;
}

#endif // D_TRIANGLE_H_
