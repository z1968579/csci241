//********************************************************************
//
// simplesim.cpp
// CSCI 241 Assignment 4
//
// Created by Jacob Kurbis (z1945650)
// 
// Purpose: Is to write a program that simulates a computer, one that 
//          is capable of executing machine language programs.
//
//********************************************************************

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
    //Initializing Simplesim's Registers
    accumulator = 0;
    instruction_counter = 0;
    instruction_register = 0;
    operation_code = 0;
    operand = 0;

    //Adding Simplesim's Memory
    for(int i = 0; i < 100; i++)
    {
        memory[i] = {7777};
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
        if(instruction <= -9999 || instruction >= 9999)
        {
            cout << "*** ABEND: pgm load: invalid word *** " << endl;
            return false;
        }

        // Check for too large program.
        if(count >= 100)
        {
            cout << "*** ABEND: pgm load: pgm too large *** " << endl;
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
    bool done = false;

    while (!done)
    {
        // Check for addressability error.
        if(instruction_counter < 0 || instruction_counter > 99)
        {
            cout << "*** ABEND: addressibility error *** " << endl;
            return;
        }

        // Fetch instruction.
        instruction_register = memory[instruction_counter];
		operation_code = instruction_register / 100;
		operand = instruction_register % 100;

		
       // Execute instruction.
		switch (operation_code)
		{
        //READ instruction
        case READ:

            int read;
            cin >> read;

            //If the READ is too long or too short
            if(read <= -9999 || read >= 9999)
            {
                cout << "*** ABEND: illegal input ***" << endl;
                return;
            }

            //Print out the READ value
            memory[operand] = read;
            cout << "READ: " << internal << showpos << setfill('0') << setw(5) << read << noshowpos << setfill(' ') << endl;

            break;
        
        //WRITE instruction
        case WRITE:
            
            int write;

            //Have WRITE be saved to Simplesim's memory at position operand and print out value
            write = memory[operand];
            cout << internal << showpos << setfill('0') << setw(5) << write << noshowpos << setfill(' ') << endl;

            break;
        

        //LOAD instruction
        case LOAD:
           
            //Have the LOAD instruction load Simplesim's memory at position operand in the accumulator
            accumulator = memory[operand];

            break;
        

        //STORE instruction
        case STORE:
            
            //Have STORE instruction store the value of accumulator to Simplesim's memory at position operand
            memory[operand] = accumulator;

            break;
        
        
        //ADD instruction
        case ADD:
            
            //Add the accumulator and Simplesim's memory at position operand
            int sum;
            sum = accumulator + memory[operand];

            //If the sum is less than the mininum value, output underflow error
            if(sum < -9999)
            {
                cout << "*** ABEND: underflow ***" << endl;
                return;
            }

            //If the sum is greater than the maximum value, output overflow error
            if(sum > 9999)
            {
                cout << "*** ABEND: overflow ***" << endl;
                return;
            }

            //Have the sum be stored in the accumulator
            accumulator = sum;

            break;
        
        
        //SUBTRACT instruction
        case SUBTRACT:
            
            //Subtract the accumulator and Simplesim's memory at position operand
            int difference;
            difference = accumulator - memory[operand];

            //If the difference is less than the minimum value, output underflow error
            if(difference < -9999)
            {
                cout << "*** ABEND: underflow ***" << endl;
                return;
            }

            //If the difference is greater than the maximum value, output overflow error
            if(difference > 9999)
            {
                cout << "*** ABEND: overflow ***" << endl;
                return;
            }

            //Have the difference be stored in the accumulator
            accumulator = difference;
            
            break;
        

        //MULTIPLY instruction
        case MULTIPLY:
            
            //Multiply the accumulator and Simplesim's memory at position operand
            int product;
            product = accumulator * memory[operand];

            //If the product is less than the minimum value, output underflow error
            if(product < -9999)
            {
                cout << "*** ABEND: underflow ***" << endl;
                return;
            }

            //If the product is greater than the maximum value, output overflow error
            if(product > 9999)
            {
                cout << "*** ABEND: overflow ***" << endl;
                return;
            }
            
            //Have the product be stored in the accumulator
            accumulator = product;
            
            break;
        

        //DIVIDE instruction
        case DIVIDE:
            
            //Checking the memory at psoition operand is equal to zero, if so, then output division by zero error
            if(memory[operand] == 0)
            {
                cout << "*** ABEND: attempted division by 0 ***" << endl;
                return;
            }
            
            //Add the accumulator and Simplesim's memory at position operand
            int quotient;
            quotient = accumulator / memory[operand];

            //If the quotient is less than the minimum value, output underflow error
            if(quotient < -9999)
            {
                cout << "*** ABEND: underflow ***" << endl;
                return;
            }

            //If the quotient is greater than the maximum value, output overflow error
            if(quotient > 9999)
            {
                cout << "*** ABEND: overflow ***" << endl;
                return;
            }

            //Have the quoient be stored in the accumulator
            accumulator = quotient;
            
            break;

        
        //BRANCH instruction
        case BRANCH:
            
            //Branching to a specific spot in memory
            instruction_counter = operand;
            
            break;
        

        //BRANCHNEG instruction
        case BRANCHNEG:
            
            //Branching to a specific spot in memory if the accumulator is less than 0
            if( accumulator < 0)
            {
                instruction_counter = operand;
            }

            //Increment the instruction_counter if accumulator is not less than 0
            else
            {
                instruction_counter++;
            }
            
            break;
        

        //BRANCHZERO instruction
        case BRANCHZERO:
            
            //Branching to a specific spot in memory if the accumulator is equal to 0
            if(accumulator == 0)
            {
                instruction_counter = operand;
            }

            //Increment the instruction_counter if accumulator is not equal to 0
            else
            {
                instruction_counter++;
            }
            
            break;
        
        //HALT instruction
        case HALT:
            
            done = true;
            break;
        
        
        //If no instructions were chosen
        default:
            cout << "*** ABEND: invalid opcode ***\n";
            return;
        }

		// Increment instruction counter if needed.
        if((operation_code != BRANCH && operation_code != BRANCHZERO && operation_code != BRANCHNEG && operation_code != HALT) && (operation_code = !done))
        {
             instruction_counter++;
        }
        
    }

    // Print successful termination message.
	cout << "*** Simplesim execution terminated ***\n";
    
}

/**
 * Prints the contents of the Simplesim's registers and memory.
 */
void simplesim::dump() const
{
    // Print registers.
    cout << endl << left << "REGISTERS: " << setw(24) << endl;
    cout << left << setw(24) << "accumulator: ";
    cout << showpos << setfill('0') << internal << setw(5) << accumulator << noshowpos << setfill(' ') << endl;
    cout << left << setw(24) << "instruction_counter: ";
    cout << setfill('0') << right << setw(2) << instruction_counter << setfill(' ') << endl;
    cout << left << setw(24) << "instruction_register: ";
    cout << showpos << setfill('0') << internal << setw(5) << instruction_register << noshowpos << setfill(' ') << endl;
    cout << left << setw(24) << "operation_code: ";
    cout << setfill('0') << right << setw(2) << operation_code << setfill(' ') << endl;
    cout << left << setw(24) << "operand: ";
    cout << setfill('0') << right << setw(2) << operand << setfill(' ') << endl << endl;
        

    // Print memory.
    cout << left << setw(24) << "MEMORY: " << endl; 
    cout << right << setw(8) << 0;

    //Loop to print out columns 0 - 9
    for(int i = 1; i < 10; i++)
    {
        cout << right << setw(6) << i;
    }


    int i = 0,//An integer to hold the element location for the memory array
        j = 0,//An integer to hold the value for which array tens place the output is currently on
        k = 1;//An integer to hold how many array elements are printed per line
    
    //Adding a space in front of first row
    cout << endl << " " << j;

    //Printing out each array value
    while(i < 100 )
    {
        cout << " " << internal << showpos << setfill('0') << setw(5) << memory[i] << noshowpos << setfill(' ');

        //Check to print a newline
        if( k % 10 == 0)
        {
            //Check to see if last line of array elements has been printed
            if(j == 90)
            {
                cout << endl;
                break;
            }

            //Print out the row number
            j += 10;
            cout << endl << j;
        }

        //Increment counters
        i++;
        k++;
        
    }
}