#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

#include "var.h"
#include "decode.h"

using namespace std;

void Big_Endian(unsigned int word, bool mode);

int main()
{
    /* var */
    int count = 0;
    /* Output file */
    iimage.open("iimage.bin",ios::out | ios::binary);
    dimage.open("dimage.bin",ios::out | ios::binary);

    /* Input file */
    inst.open("inst.txt",ios::in);
    data.open("data.txt",ios::in);

    /* Init the PC value */
    cout << "Set Initial PC Number (Hex) : 0x";
    cin >> hex >> pc ;
    Big_Endian(pc, true);
    /* Init the PC value */

    /* Init the Number of instructions */
    cout << "Set the Instruction Number (Dec) : ";
    cin >> dec >> num ;
    Big_Endian(num, true);
    /* Init the Number of instructions */

    /* Read the Instruction */

    opcode.clear();
    while(inst>>opcode)
    {
        cout << "opcode " << dec << count << " : "<< opcode << endl;
        Decode(); //Decode
        opcode.clear(); // Reset
        Big_Endian((unsigned int)instruction, true);
        count++;
    }

    iimage.close();
    /* Read the Instruction */

    /* Init the $SP value */
    cout << "Set Initial SP Number (Hex) : 0x";
    cin >> hex >> sp ;
    Big_Endian(sp, false);
    /* Init the PC value */

    /* Init the Number of data */
    cout << "Set the Memory Number (Dec) : ";
    cin >> dec >> num ;
    Big_Endian(num, false);
    /* Init the Number of data */

    /* Write data into Memory */

    while(data >> hex >> num)
    {
        Big_Endian(num, false);
    }

    dimage.close();
    /* Write data into Memory */

    return 0;
}

void Big_Endian(unsigned int word, bool mode)
{
    if(mode == true)
    {
        char c;
        c = (word & 0xff000000) >> 24;
        iimage.write((char *) &c, sizeof(c));
        c = (word & 0x00ff0000) >> 16;
        iimage.write((char *) &c, sizeof(c));
        c = (word & 0x0000ff00) >>  8;
        iimage.write((char *) &c, sizeof(c));
        c = word & 0x000000ff;
        iimage.write((char *) &c, sizeof(c));
    }
    else
    {
        char c;
        c = (word & 0xff000000) >> 24;
        dimage.write((char *) &c, sizeof(c));
        c = (word & 0x00ff0000) >> 16;
        dimage.write((char *) &c, sizeof(c));
        c = (word & 0x0000ff00) >>  8;
        dimage.write((char *) &c, sizeof(c));
        c = word & 0x000000ff;
        dimage.write((char *) &c, sizeof(c));
    }
}
