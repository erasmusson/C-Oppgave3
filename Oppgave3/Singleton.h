// file: Singleton.h
#ifndef SINGLETON_H
#define SINGLETON_H
#include <iostream>
using namespace std;
class Singleton
{
public:
	static Singleton& Instance() {  // Definition could instead be in cpp file.
		static Singleton singleton;
		return singleton;
	}
	void hello();

private:
	Singleton() {}			      // Constructor is hidden (& inline).
	Singleton(const Singleton&) = delete;	// Copy constructor is deleted.
	Singleton& operator=(const Singleton&) = delete;  // Assign operator is deleted.
	~Singleton();
};

#endif
