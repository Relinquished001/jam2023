#include "test.hpp"


typedef TestClass Self;


int state = 1;


Self::TestClass() {
	d = 100;
}


int Self::f1() {
	d = d + 1;
	return d;
}


void Self::exc1() {
	if (state) throw (int)d;
}


int Self::exc() {
	try {
		exc1();
	} catch(int x) {
		return x;
	} catch(...) {
		assertf(0, "Exceptions not working");
		return -1;
	}
	return -1;
}


void Self::crash(void) {
	throw std::runtime_error("Crash!");
}
