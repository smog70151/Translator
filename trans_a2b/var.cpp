#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

#include "var.h"

using namespace std;

/* Output file */
fstream iimage, dimage;
/* Input file */
fstream inst, data;

/* PC, $SP Init */
unsigned int pc, sp, num;
string opcode;

/* Inst var */
int rs, rt, rd, shamt; //5-bits
int op, funct; //6-bits
int immediate; //16-bits
int address; //26-bits
int instruction;


