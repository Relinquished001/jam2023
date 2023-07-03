#pragma once


#include <cstdio>
#include <cstdint>
#include <libdragon.h>
#include <memory>
#include <stdexcept>


class TestClass {

private:
	uint32_t d;

public:
	TestClass();
	int f1();
	void exc1();
	int exc();
	void crash(void);
};
