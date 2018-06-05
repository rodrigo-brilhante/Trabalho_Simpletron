#pragma once
class Simpletron
{

public:
	Simpletron();
	int *memory;
	int accumulador;
	int counter;
	int instructionRegister;
	int operationCode;
	int operand;

	void run();
	void load(char *);

protected:
	bool validation(int);
};

