#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <iomanip>
#include "Simpletron.h"
#include <fstream>
#include <string>

using namespace std;

const int INC = 50;
const int DEC = 51;

const int READ = 10;
const int WRITE = 11;
const int LOAD = 20;
const int STORE = 21;
const int ADD = 30;
const int SUBTRACT = 31;
const int DIVIDE = 32;
const int MULTIPLY = 33;
const int FATORIAL = 34;
const int BRANCH = 40;
const int BRANCHNEG = 41;
const int BRANCHZERO = 42;
const int HALT = 43;

Simpletron::Simpletron()
{
	counter = 0;
	accumulador = 0;
	counter = 0;
	instructionRegister = 0;
	operationCode = 0;
	operand = 0;
	memory = new int[100];

	for (int i = 0; i < 100; i++)
	{
		memory[i] = +0000;
	}
}

void Simpletron::run()
{
	cout << endl;
	do
	{
		instructionRegister = memory[counter];
		operationCode = instructionRegister / 100;
		operand = instructionRegister % 100;
		counter++;


		switch (operationCode)
		{
		case INC:
			accumulador++;
			break;

		case DEC:
			accumulador--;
			break;

		case READ:
			cout << "Read-> ";
			cin >> memory[operand];
			break;

		case WRITE:
			cout << "Write-> " << memory[operand];
			break;

		case LOAD:
			accumulador = memory[operand];
			break;

		case STORE:
			memory[operand] = accumulador;
			break;

		case ADD:
			accumulador += memory[operand];
			break;

		case SUBTRACT:
			accumulador -= memory[operand];
			break;

		case DIVIDE:
			accumulador /= memory[operand];
			break;

		case MULTIPLY:
			accumulador *= memory[operand];
			break;

		case BRANCH:
			counter = operand;
			break;

		case BRANCHNEG:
			if (accumulador < 0)
				counter = operand;
			break;

		case BRANCHZERO:
			if (accumulador == 0)
				counter = operand;
			break;

		case HALT:
			cout << endl << endl << "Program completed the task!!!" << endl;
			break;

		default:
			break;
		}
	} while (instructionRegister != 4300);

	cout << endl << "Registers:" << endl;
	cout << "Accumulador:               " << showpos << setw(5) << setfill('0') << internal << accumulador << endl;
	cout << "Counter:                   " << showpos << setw(3) << setfill('0') << internal << counter << endl;
	cout << "InstructionRegister:       " << showpos << setw(5) << setfill('0') << internal << instructionRegister << endl;
	cout << "OperationCode:             " << showpos << setw(3) << setfill('0') << internal << operationCode << endl;
	cout << "Operand:                   " << showpos << setw(3) << setfill('0') << internal << operand << endl;
	cout << "" << endl;
	cout << "MEMORY:" << endl;
	cout << endl << "       0     1     2     3     4     5     6     7     8     9" << endl;

	cout << "00 ";
	for (int i = 0; i<10; i++)
	{
		cout << showpos << setw(5) << setfill('0') << internal << memory[i] << " ";
	}
	cout << endl;
	for (int j = 10; j<100; j = j + 10)
	{
		cout << noshowpos << j << " ";
		for (int i = 0; i<10; i++) {
			cout << showpos << setw(5) << setfill('0') << internal << memory[j + i] << " ";
		}
		cout << endl;
	}
}

void Simpletron::load(char *n)
{
	system("cls");
	FILE *arq;
	int i = 0;
	arq = fopen(n, "rt");
	if (arq == NULL)
	{
		cout << "Problems in open the file!!!" << endl;
		exit(0);
	}
	while (!feof(arq))
	{
		fscanf_s(arq, "%d", &memory[i]);
		if (!validation(memory[i]))
		{
			cout << "Compilation error line " << setw(2) << setfill('0') << i << " !!!" << endl;
			exit(0);
		}
		i++;
	}
	fclose(arq);
}

bool Simpletron::validation(int x)
{
	x = x / 100;
	switch (x)
	{
	case INC:
		return true;

	case DEC:
		return true;

	case READ:
		return true;

	case WRITE:
		return true;

	case LOAD:
		return true;

	case STORE:
		return true;

	case ADD:
		return true;

	case SUBTRACT:
		return true;

	case DIVIDE:
		return true;

	case MULTIPLY:
		return true;

	case FATORIAL:
		return true;

	case BRANCH:
		return true;

	case BRANCHNEG:
		return true;

	case BRANCHZERO:
		return true;

	case HALT:
		return true;

	default:
		return false;
	}
}
