#include <iostream>
#include "Simpletron.h"

void main(int argc, char **argv)
{
	Simpletron *machine = new Simpletron();
	machine->load(argv[1]);
	machine->run();
}