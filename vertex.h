#ifndef D_VERTEX_H
#define D_VERTEX_H 1

#include <iostream>

template<class T>
struct vertex {
	T x;
	T y;

};

template<class T>
std::istream& operator>> (std::istream& is, vertex<T>& p) {
	is >> p.x >> p.y;
	return is;
}

template<class T>
std::ostream& operator<< (std::ostream& os, vertex<T>& p) {
	os << p.x << ' ' << p.y;
	return os;
}

template<class T>
bool operator == (vertex<T> a, vertex<T> b) {
	return (a.x == b.x && a.y == b.y);
}

#endif // D_VERTEX_H