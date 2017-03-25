#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

#include "var.h"
#include "decode.h"

using namespace std;

int main()
{
    /* var */
    unsigned int tmp; //to save the string number
    /* Output file */
    iimage.open("iimage.bin",ios::out | ios::binary);
    dimage.open("dimage.bin",ios::out | ios::binary);

    /* Input file */
    inst.open("inst.txt",ios::in);
    data.open("data.txt",ios::in);

    /* Init the PC value */
    cout << "Set Initial PC Number (Hex) : 0x";
    cin >> hex >> pc ;
    iimage << pc;
    /* Init the PC value */

    /* Init the Number of instructions */
    cout << "Set the Instruction Number (Dec) : ";
    cin >> dec >> num ;
    iimage << num;
    /* Init the Number of instructions */

    /* Read the Instruction */
    opcode.clear();
    while(inst>>opcode)
    {
        Decode(); //Decode
        opcode.clear(); // Reset
    }
    iimage.close();
    /* Read the Instruction */

    /* Init the $SP value */
    cout << "Set Initial SP Number (Hex) : 0x";
    cin >> hex >> sp ;
    iimage << sp;
    /* Init the PC value */

    /* Init the Number of data */
    cout << "Set the Memory Number (Dec) : ";
    cin >> dec >> num ;
    iimage << num;
    /* Init the Number of data */

    /* Write data into Memory */
    while(data>>num)
    {
        data >> hex >> num;
        dimage << num;
    }
    dimage.close();
    /* Write data into Memory */

    return 0;
}
