#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

/* Output file */
extern fstream iimage, dimage;
/* Input file */
extern fstream inst, data;

/* PC, $SP Init */
extern unsigned int pc, sp, num;
extern string opcode;

extern stringstream temp;

/* Inst var */
extern int rs, rt, rd, shamt; //5-bits
extern int op, funct; //6-bits
extern int immediate; //16-bits
extern int address; //26-bits
extern int instruction;

