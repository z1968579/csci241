/**
 * @file simplesim.cpp
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 9
 * @date 11-09-2022
 */

#include <iostream>
#include <iomanip>
#include "simplesim.h"
#include "sml.h"

using std::cin;
using std::cout;
using std::endl;
using std::internal;
using std::left;
using std::noshowpos;
using std::right;
using std::setfill;
using std::setw;
using std::showpos;

/**
 * Constructor: Initializes the Simplesim's memory to default values.
 */
simplesim::simplesim()
{
    for (int i = 0; i < 100; i++)
    {
        memory[i] = DEFAULT;
    }
}

/**
 * Loads an SML program into the Simplesim's memory.
 *
 * @return Returns true if a valid program is successfully loaded into 
 *         memory; otherwise, false.
 */
bool simplesim::load_program()
{
    int count = 0;
    int instruction = 0;

    while (cin >> instruction && instruction != -99999)
    {
        // Check for invalid word.
        if (instruction < -9999 || instruction > 9999)
        {
            cout << "*** ABEND: pgm load: invalid word ***\n\n";
            return false;
        }

        // Check for too large program.
        if (count > 99)
        {
            cout << "*** ABEND: pgm load: pgm too large ***\n\n";
            return false;
        }
        // Add instruction to memory.
        memory[count] = instruction;
        // Increment instruction count.
        count++;
	}
    return true;
}

/**
 * Executes an SML program loaded into the Simplesim's memory.
 */
void simplesim::execute_program()
{
    int temp;

    
    bool done = false;

    while (!done)
    {
        // Check for addressability error.
        if(instruction_counter < 0 or instruction_counter > 99)
        {
            cout << "*** ABEND: addressability error ***\n\n";
            return;
        }

        // Fetch instruction.
        instruction_register = memory[instruction_counter];
		operation_code = instruction_register / 100;
		operand = instruction_register % 100;
		
        // Execute instruction.
		switch (operation_code)
		{
        case READ:
            cin >> temp;
            if (temp >= -9999 and temp <= 9999)
            {
                memory[operand] = temp;
            }
            else
            {
                cout << "*** ABEND: illegal input ***\n\n";
                return;
            }

            cout << left << setw(6) << "READ:" << internal << setw(5) << showpos << setfill('0') << memory[operand] << setfill(' ') << endl;
            break;

        case WRITE:
            temp = memory[operand];
            cout << internal << setw(5) << showpos << setfill('0')  << temp << setfill(' ')<< endl;
            break;

        case STORE:
            memory[operand] = accumulator;
            break;

        case LOAD:
            accumulator = memory[operand];
            break;

        case ADD:
            temp = accumulator + memory[operand] ;
            if (temp <= -9999)
            {
                cout << "*** ABEND: underflow ***\n\n";
                accumulator--;
                return;
            }
            else if (temp >= 9999)
            {
                cout << "*** ABEND: overflow ***\n\n";
                accumulator++;
                return;
            }
            accumulator = temp;
            break;

        case SUBTRACT:
            temp = accumulator - memory[operand];
            if (temp <= -9999)
            {
                cout << "*** ABEND: underflow ***\n\n";
                accumulator--;
                return;
            }
            else if (temp >= 9999)
            {
                cout << "*** ABEND: overflow ***\n\n";
                accumulator++;
                return;
            }
            else
            {
                accumulator = temp;
            }
            break;   

        case MULTIPLY:
            temp = memory[operand] * accumulator;
            
            if (temp <= -9999)
            {
                cout << "*** ABEND: underflow ***\n\n";
                return;
            }
            else if (temp >= 9999)
            {
                cout << "*** ABEND: overflow ***\n\n";
                return;
            }
            else
            {
                accumulator = temp;
            }
            break;

        case DIVIDE:
            if (memory[operand] == 0)
            {
                cout << "*** ABEND: attempted division by 0 ***\n\n";
                return;
            }
            else
            {
                temp = accumulator/memory[operand] ;
            }
            accumulator = temp;
            break;

        case BRANCH:
            instruction_counter = operand;
            break;

        case BRANCHZERO:
            if (accumulator == 0)
            {
                instruction_counter = operand;
            }
            else
                instruction_counter++;
            break;

        case BRANCHNEG:
            if (accumulator < 0)
            {
                instruction_counter = operand;
            }
            else
                instruction_counter++;
            break;

        case HALT:
            done = true;
            break;

        default:
            cout << "*** ABEND: invalid opcode ***\n\n";
            return;
        }

		// Increment instruction counter if needed.
        // if (not done && this instruction was not a branch: intstruction_counter++)
        if (done == false && operation_code < BRANCH)
           instruction_counter++;
    }

    // Print successful termination message.
	cout << "*** Simplesim execution terminated ***\n" << endl;
}

/**
 * Prints the contents of the Simplesim's registers and memory.
 */
void simplesim::dump() const
{
    // Print registers.
    cout << setfill(' ');
    cout << left << "REGISTERS:" << endl;
    cout << left << setw(24) << "accumulator:" << internal << setw(5) << showpos << setfill('0') << accumulator << setfill(' ') << endl;
    cout << left << setw(24) << "instruction_counter:" << right << setw(2) << noshowpos << setfill('0') << instruction_counter << setfill(' ') << endl; //
    cout << left << setw(24) << "instruction_register:" << internal << setw(5) << showpos << setfill('0') << instruction_register << setfill(' ') << endl;
    cout << left << setw(24) << "operation_code:" << right << setw(2) << noshowpos << setfill('0') << operation_code << setfill(' ') << endl; //
    cout << left << setw(24) << "operand:" << right << setw(2) << noshowpos << setfill('0') << operand << endl << setfill(' ') << endl;//
    
    // Print memory.

    cout << left << "MEMORY:" << endl;

    for (int i = 0; i <= 9; i++)
    {
        if (i == 0 )
            cout << right << setw(8) << i;
        if (i > 0)
            cout << right << setw(6) << i;
        if (i == 9)
            cout << endl;
    }

    for (int i = 0; i <= 99; i++)
    {
        if (i == 0)
            cout << right << noshowpos << setw(2) << i;
        if ((i % 10) == 0 and i <= 90 and i != 0)
            cout << endl << right << noshowpos << setw(2) << i;

        cout << " " << internal << setw(5) << showpos << setfill('0') << memory[i] << setfill(' ');

        if (i == 99)
            cout << endl;
    }

}