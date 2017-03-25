#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

#include "var.h"
#include "decode.h"

using namespace std;

void Decode()
{
    /* R-type Instruction */
    if (opcode == "add")
    {
        op = 0x00;
        inst >> rd;
        inst >> rs;
        inst >> rt;
        shamt=0;
        funct=0x20;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + (rd<<11) + (shamt<<6) + funct;

    }
    if (opcode == "addu")
    {
        op = 0x00;
        inst >> rd;
        inst >> rs;
        inst >> rt;
        shamt=0;
        funct=0x21;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + (rd<<11) + (shamt<<6) + funct;

    }
    if (opcode == "sub")
    {
        op = 0x00;
        inst >> rd;
        inst >> rs;
        inst >> rt;
        shamt=0;
        funct=0x22;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + (rd<<11) + (shamt<<6) + funct;

    }
    if (opcode == "and")
    {
        op = 0x00;
        inst >> rd;
        inst >> rs;
        inst >> rt;
        shamt=0;
        funct=0x24;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + (rd<<11) + (shamt<<6) + funct;

    }
    if (opcode == "or")
    {
        op = 0x00;
        inst >> rd;
        inst >> rs;
        inst >> rt;
        shamt=0;
        funct=0x25;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + (rd<<11) + (shamt<<6) + funct;

    }
    if(opcode == "xor")
    {
        op = 0x00;
        inst >> rd;
        inst >> rs;
        inst >> rt;
        shamt=0;
        funct=0x26;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + (rd<<11) + (shamt<<6) + funct;

    }
    if (opcode == "nor")
    {
        op = 0x00;
        inst >> rd;
        inst >> rs;
        inst >> rt;
        shamt=0;
        funct=0x27;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + (rd<<11) + (shamt<<6) + funct;

    }
    if (opcode == "nand")
    {
        op = 0x00;
        inst >> rd;
        inst >> rs;
        inst >> rt;
        shamt=0;
        funct=0x28;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + (rd<<11) + (shamt<<6) + funct;

    }
    if (opcode == "slt")
    {
        op = 0x00;
        inst >> rd;
        inst >> rs;
        inst >> rt;
        shamt=0;
        funct=0x2a;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + (rd<<11) + (shamt<<6) + funct;

    }
    if (opcode == "sll")
    {
        op = 0x00;
        inst >> rd;
        rs = 0;
        inst >> rt;
        inst >> shamt;
        shamt = shamt & 0x0000001f;
        funct=0x00;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + (rd<<11) + (shamt<<6) + funct;

    }
    if (opcode == "srl")
    {
        op = 0x00;
        inst >> rd;
        rs = 0;
        inst >> rt;
        inst >> shamt;
        shamt = shamt & 0x0000001f;
        funct=0x02;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + (rd<<11) + (shamt<<6) + funct;

    }
    if (opcode == "sra")
    {
        op = 0x00;
        inst >> rd;
        rs = 0;
        inst >> rt;
        inst >> shamt;
        shamt = shamt & 0x0000001f;
        funct=0x03;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + (rd<<11) + (shamt<<6) + funct;

    }
    if( opcode == "jr")
    {
        op = 0x00;
        rd = 0;
        inst >> rs;
        rt = 0;
        shamt = 0;
        funct=0x08;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + (rd<<11) + (shamt<<6) + funct;

    }
    if(opcode == "mult")
    {
        op = 0x00;
        rd = 0;
        inst >> rs;
        inst >> rt;
        shamt = 0;
        funct=0x18;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + (rd<<11) + (shamt<<6) + funct;

    }
    if(opcode == "multu")
    {
        op = 0x00;
        rd = 0;
        inst >> rs;
        inst >> rt;
        shamt = 0;
        funct=0x19;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + (rd<<11) + (shamt<<6) + funct;

    }
    if( opcode == "mfhi")
    {
        op = 0x00;
        inst >> rd;
        rs = 0;
        rt = 0;
        shamt = 0;
        funct=0x10;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + (rd<<11) + (shamt<<6) + funct;

    }
    if ( opcode == "mflo")
    {
        op = 0x00;
        inst >> rd;
        rs = 0;
        rt = 0;
        shamt = 0;
        funct=0x12;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + (rd<<11) + (shamt<<6) + funct;

    }
    /* R-type Instruction */

    /* I-type Instruction */
    if ( opcode =="addi")
    {
        op = 0x08;
        inst >> rt;
        inst >> rs;
        inst >> immediate;
        immediate = immediate & 0x0000ffff;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + immediate;

    }
    if ( opcode =="addiu")
    {
        op = 0x09;
        inst >> rt;
        inst >> rs;
        inst >> immediate;
        immediate = immediate & 0x0000ffff;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + immediate;

    }
    if( opcode == "lw")
    {
        op = 0x23;
        inst >> rt;
        inst >> immediate;
        inst >> rs;
        immediate = immediate & 0x0000ffff;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + immediate;

    }
    if( opcode =="lh")
    {
        op = 0x21;
        inst >> rt;
        inst >> immediate;
        inst >> rs;
        immediate = immediate & 0x0000ffff;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + immediate;

    }
    if( opcode =="lhu")
    {
        op = 0x25;
        inst >> rt;
        inst >> immediate;
        inst >> rs;
        immediate = immediate & 0x0000ffff;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + immediate;

    }
    if( opcode =="lb")
    {
        op = 0x20;
        inst >> rt;
        inst >> immediate;
        inst >> rs;
        immediate = immediate & 0x0000ffff;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + immediate;

    }
    if( opcode == "lbu")
    {
        op = 0x24;
        inst >> rt;
        inst >> immediate;
        inst >> rs;
        immediate = immediate & 0x0000ffff;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + immediate;

    }
    if(opcode == "sw")
    {
        op = 0x2b;
        inst >> rt;
        inst >> immediate;
        inst >> rs;
        immediate = immediate & 0x0000ffff;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + immediate;

    }
    if(opcode == "sh")
    {
        op = 0x29;
        inst >> rt;
        inst >> immediate;
        inst >> rs;
        immediate = immediate & 0x0000ffff;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + immediate;

    }
    if(opcode == "sb")
    {
        op = 0x28;
        inst >> rt;
        inst >> immediate;
        inst >> rs;
        immediate = immediate & 0x0000ffff;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + immediate;

    }
    if(opcode =="lui")
    {
        op = 0x0f;
        rs = 0;
        inst >> rt;
        inst >> immediate;
        immediate = immediate & 0x0000ffff;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + immediate;

    }
    if(opcode =="andi")
    {
        op = 0x0c;
        inst >> rt;
        inst >> rs;
        inst >> immediate;
        immediate = immediate & 0x0000ffff;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + immediate;

    }
    if (opcode =="ori")
    {
        op = 0x0d;
        inst >> rt;
        inst >> rs;
        inst >> immediate;
        immediate = immediate & 0x0000ffff;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + immediate;

    }
    if (opcode =="nori")
    {
        op = 0x0e;
        inst >> rt;
        inst >> rs;
        inst >> immediate;
        immediate = immediate & 0x0000ffff;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + immediate;

    }
    if (opcode =="slti")
    {
        op = 0x0a;
        inst >> rt;
        inst >> rs;
        inst >> immediate;
        immediate = immediate & 0x0000ffff;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + immediate;

    }
    if (opcode =="beq")
    {
        op = 0x04;
        inst >> rs;
        inst >> rt;
        inst >> immediate;
        immediate = immediate & 0x0000ffff;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + immediate;

    }
    if (opcode =="bne")
    {
        op = 0x05;
        inst >> rs;
        inst >> rt;
        inst >> immediate;
        immediate = immediate & 0x0000ffff;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + immediate;

    }
    if (opcode =="bgtz")
    {
        op = 0x07;
        rt = 0;
        inst >> rs;
        inst >> immediate;
        immediate = immediate & 0x0000ffff;
        instruction = (op<<26) + (rs<<21) + (rt<<16) + immediate;

    }
    /* I-type Instruction */

    /* J-type Instruction */
    if (opcode =="j")
    {
        op = 0x02;
        inst >> address;
        address = address & 0x03ffffff;
        instruction = (op<<26) + address;

    }
    if (opcode =="jal")
    {
        op = 0x03;
        inst >> address;
        address = address & 0x03ffffff;
        instruction = (op<<26) + address;

    }
    /* J-type Instruction */

    /* S-type Instruction */
    if (opcode =="halt")
    {
        op = 0x3f;
        address = 0x03ffffff;
        instruction = (op<<26) + address;

    }
    /* S-type Instruction */

}
