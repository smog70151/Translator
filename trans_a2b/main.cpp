#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// file
file iimage, dimage;
file iidata, didata;
string inst, mem;
int a, b, c; //load inst rest part
int opcode, rs, rt, rd, immediate, shumt, funct; 

void trans_inst(int no);
void decord();
void rest_r();
void rest_w();


int main()
{
    // var
    char pc[8];
    char sp[8];
    unsigned int h_pc,no_i; // ii part
    unsigned int h_sp,no_d; // di part

    //write part
    iimage.open("iimage.bin",ios::out|ios::binary);
    dimage.open("dimage.bin",ios::out|ios::binary);

    //open part
    iidata.open("iidata.txt",ios::in);
    didata.open("didata.txt",iox::in);

    //iipart
    cout << "Please Init PC address : 0x" ;
    cin >> pc ;
    h_pc=0; //init pc
    for(int i=0; i<8 ;i++)
        h_pc+=pc[i]<<(8-i);
    iidata << h_pc;

    cout << "Please enter the # of Inst : "
    cin >> no_i;
    iidata << no_i;

    //dipart
    cout << "Please Init $SP(reg-29) address : 0x" ;
    cin >> sp ;
    h_sp=0; //init pc
    for(int i=0; i<8 ;i++)
        h_sp+=sp[i]<<(8-i);
    iidata << h_sp;

    cout << "Please enter the # of Mem : "
    cin >> no_d;
    iidata << no_d;

    //trans inst
    trans_inst(no_i);



    return 0;
}

void trans_inst(int no)
{
	opcode = 0; //init opcode
    while(iidata>>inst)
    {
		stringstream ss;
		ss << inst; 
		ss >> opcode;
		opcode = 
        decord();
    }
    iidata.close();
    iimage.close();
}

void rest()
{
    iidata>>a; //destination
    iidata>>b; //source
    iidata>>c; //source
}

void decord()
{
    switch(inst)
    {
    //R-type
    case "add" :
        rest();
        break;
    case "addu" :
        break;
    case "sub" :
        break;
    case "and" :
        break;
    case "or" :
        break;
    case "xor" :
        break;
    case "nor" :
        break;
    case "nand" :
        break;
    case "slt" :
        break;
    case "sll" :
        break;
    case "srl" :
        break;
    case "sra" :
        break;
    case "jr" :
        break;
    case "mult" :
        break;
    case "multu" :
        break;
    case "mfhi" :
        break;
    case "mflo" :
        break;
    //I-type
    case "addi" :
        break;
    case "addiu" :
        break;
    case "lw" :
        break;
    case "lh" :
        break;
    case "lhu" :
        break;
    case "lb" :
        break;
    case "lbu" :
        break;
    case "sw" :
        break;
    case "sh" :
        break;
    case "sb" :
        break;
    case "lui" :
        break;
    case "andi" :
        break;
    case "ori" :
        break;
    case "nori" :
        break;
    case "slti" :
        break;
    case "beq" :
        break;
    case "bne" :
        break;
    case "bgtz" :
        break;
    //J-type
    case "j" :
        break;
    case "jal" :
        break;
    //S-type
    case "halt" :
        break;
    }
}
