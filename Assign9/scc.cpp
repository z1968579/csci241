/**
 * @file scc.cpp
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 9
 * @date 11-09-2022
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>

#include "sml.h"
#include "inpost.h"

using namespace std;

/**
 *
 * Symbol table entry.
 *
 */

struct table_entry
{
    int symbol;
    char type;
    int location;
};

/**
 *
 * Simple compiler.
 *
 */
class scc
{
public:

    // Data members
    static const int MEMORY_SIZE = 100;
    static const int SYMBOL_TABLE_SIZE = 1000;

    // Member functions
    scc();
    void first_pass();
    void second_pass();
    void print_program() const;

private:

    // Data members
    int memory[MEMORY_SIZE];    // Program memory.
    int data[MEMORY_SIZE];      // Input data values.
    int ndata = 0;              // Number of input data values.

    table_entry symbol_table[SYMBOL_TABLE_SIZE];     // Symbol table.
    
    int flags[MEMORY_SIZE];     // Array of flags to mark partial
                                // instructions.

    int next_instruction_addr = 0;    // Address of next instruction.
    int next_const_or_var_addr = MEMORY_SIZE - 1;
    int next_symbol_table_idx = 0;

    // Member functions

    void memory_check() const;
    void data_check() const;
    void stack_space_check(int) const;

    int get_symbol_location(const string&);
    int search_symbol_table(int, char) const;

    void handle_input(istringstream&);
    void handle_data(istringstream&);
    void handle_end();
    void handle_let(istringstream &ss, const string& buffer);
    void handle_print(istringstream &ss);
    void handle_goto(istringstream &ss);
    void handle_if(istringstream &ss);
};

/**
 * Compiles a Simple program to SML and
 * prints it to standard output.
 */
int main()
{
    scc compiler;

    compiler.first_pass();

    compiler.second_pass();

    compiler.print_program();

    return 0;
}

/**
 * Constructor - initializes memory and flags arrays.
 */
scc::scc()
{
    for (int i = 0; i < MEMORY_SIZE; i++)
    {
        memory[i] = 7777;
        flags[i] = -1;
    }
}

/**
 * Performs first pass of compilation.
 */
void scc::first_pass()
{
    string buffer1, buffer2, command;
    int line_number;

    // While there are more program statements...
    while (getline(cin, buffer1))
    {
        buffer2 = buffer1;         // buffer2 used for 'let'
        istringstream ss(buffer1);

        // Read the line number of the program statement.
        ss >> line_number;

        // Add the line number to the symbol table with type 'L'.
        symbol_table[next_symbol_table_idx].symbol = line_number;
        symbol_table[next_symbol_table_idx].type = 'L';
        symbol_table[next_symbol_table_idx]. location = next_instruction_addr;
        next_symbol_table_idx++;

        // Read the command of the program statement.
        ss >> command;

        // Determine what kind of command this is and take
        // action accordingly.
        if (command == "input")
        {
            // ... code to process 'input' command ...
            handle_input(ss);
        }
        else if (command == "data")
        {
            // ... code to process 'data' command ...
            handle_data(ss);
        }
        else if (command == "let")
        {
            // ... code to process 'let' command ...
            handle_let(ss, buffer1);
        }
        else if (command == "goto")
        {
            // ... code to process 'goto' command ...
            handle_goto(ss);
        }
        else if (command == "if")
        {
            // ... code to process 'if' command ...
            handle_if(ss);
        }
        else if (command == "print")
        {
            // ... code to process 'print' command ...
            handle_print(ss);

        }
        else if (command == "rem")
        {
            // ... code to process 'rem' command ...
            // Nothing to do here.
        }
        else
        {
            // ... code to process 'end' command ...
            handle_end();
        }
    }
}

/**
 * Performs second pass of compilation.
 */
void scc::second_pass()
{
    //int index; -->Error message said this was not used
    
    // Compute the starting location of the stack, just
    // above the constants and variables.
    int stack_start = next_const_or_var_addr - 1;
    
    // Loop through the flags and memory arrays.
    for (int i = 0; i < next_instruction_addr; i++)
    {
        // If the instruction is marked incomplete in the flags array...
        if (flags[i] != -1)
        {
            if (flags[i] > 0)
            {
                // Line number for goto instruction.
                int idx = search_symbol_table(flags[i], 'L');
                memory[i] += symbol_table[idx].location;
            }
            else if (flags[i] == -2)
            {
                // Special right operand location.
                memory[i] += next_const_or_var_addr;
            }
            else if (flags[i] < -2)
            {
                // Stack location.
                int idx = -3 - flags[i];
                // location fo that stack elemet = stack start - idx;
                int location = stack_start - idx;
                stack_space_check(location);

                // check to see if location referenced by stack index is within the bounds of the space available for te stack
                // add location to instruction 
                memory[i] += location;
            }
        }
    }
}

/**
 * Prints memory and data for the compiled SML program.
 */
void scc::print_program() const
{
    cout << setfill('0') << internal << showpos;

    // Print the entire memory array.
    for (int i = 0; i < MEMORY_SIZE; i++)
        cout << setw(5) << memory[i] << endl;

    // Print the "end of instructions" sentinel value.
    cout << -99999 << endl;

    // Print the input data values.
    for (int i = 0; i < ndata; i++)
        cout << data[i] << endl;
}

/**
 * Checks whether there is room in the memory array to add
 * another instruction.
 */
void scc::memory_check() const
{
    if (next_instruction_addr >= MEMORY_SIZE || 
        next_instruction_addr > next_const_or_var_addr)
    {
        cout << "*** ERROR: ran out of Simplesim memory ***\n";
        exit(1);
    }
}

/**
 * Checks whether there is room in the data array to add
 * another data item.
 */
void scc::data_check() const
{
    if (ndata >= MEMORY_SIZE)
    {
        cout << "*** ERROR: too many data lines ***\n";
        exit(1);
    }
}

/**
 * Checks whether the top of the stack has crossed into
 * the region of the memory array that contains instructions.
 *
 * @param location Location of the top of the stack.
 */
void scc::stack_space_check(int location) const
{
    // If top of the stack has hit the instructions...
    if (location < next_instruction_addr)
    {
        cout << "*** ERROR: insufficient stack space ***\n";
        exit(1);
    }
}

/**
 * Gets the location of a constant or variable, adding it
 * to the symbol table and memory if necessary.
 *
 * @param token The symbol to locate.
 *
 * @return The symbol's location.
 */
int scc::get_symbol_location(const string& token)
{
    int location, symbol;
    char type;

    // Examine first character of the token string.
    
    if (islower(token[0]))
    {
        // This is a variable.
        symbol = token[0];
        type = 'V';
    }
    else
    {
        // This is an integer constant.
        symbol = stoi(token);
        type = 'C';
    }

    // Search for this symbol in the symbol table.
    int index = search_symbol_table(symbol, type);

    if (index == -1)
    {
        // This symbol is not in the symbol table yet.
        
        // Add this symbol to the symbol table and memory.
        location = next_const_or_var_addr;

        // Add symbol to symbol table.
        symbol_table[next_symbol_table_idx].symbol = symbol;
        symbol_table[next_symbol_table_idx].type = type;
        symbol_table[next_symbol_table_idx].location = location;
        next_symbol_table_idx++;

        // Add this constant or variable to memory.
        memory_check();
        if (type == 'V')
            memory[location] = 0;
        else
            memory[location] = symbol;

        next_const_or_var_addr--;
    }
    else
    {
        // This symbol is in the symbol table at element
        // index, so get its location in memory.
        location = symbol_table[index].location;
    }

    // Return the location in memory of the symbol.
    
    return location;
}

/**
 * Searches the symbol table for a symbol with a particular
 * type.
 *
 * @param symbol The symbol to search for.
 * @param type The type of the symbol to search for.
 *
 * @return The location of the symbol or -1 if the search
 *         failed.
 *
 * @note Uses the linear search algorithm.
 */
int scc::search_symbol_table(int symbol, char type) const
{
    for (int i = 0; i < next_symbol_table_idx; i++)
    {
        // If we find a match for the symbol, return the
        // table index.
        if (symbol == symbol_table[i].symbol && type ==
            symbol_table[i].type)
            return i;
    }

    // Search failed; return a failure signal.
    return -1;
}

/**
 * Generates code for a "input" instruction.
 *
 * @param ss Input string stream from which to read.
 */
void scc::handle_input(istringstream& ss)
{
    string token;

    // Read the variable name for this input command.
    
    ss >> token;

    // Get the memory location of that variable.
    
    int location = get_symbol_location(token);

    // Generate a READ instruction for that location.
    
    memory_check();
    memory[next_instruction_addr] = READ * 100 + location;
    next_instruction_addr++;
}

/**
 * Generates code for a "data" instruction.
 *
 * @param ss Input string stream from which to read.
 */
void scc::handle_data(istringstream& ss)
{
    int number;

    // Read the data value for this data command.
    
    ss >> number;
    
    // Add the value to the data array.
    
    data_check();
    data[ndata] = number;
    ndata++;
}

/**
 * Generates code for an "end" instruction.
 */
void scc::handle_end()
{
    // Generate a HALT instruction.
    
    memory_check();
    memory[next_instruction_addr] = HALT * 100;
    next_instruction_addr++;
}

/**
 * Generates code for an "if" instruction.
 *
 * @param ss Input string stream from which to read.
 *
 ********************************************************************/
void scc::handle_if(istringstream &ss)
{
    //25 if x <= -1 goto 60

    string lop, relop, rop, unused;
    int lop_location, rop_location, line_number;

    // Read left operand into lop
    ss >> lop;
    // Get location for the symbol lop (lop location) (I HAVE A FUNCTUION FOR THIS)
    lop_location = get_symbol_location(lop);
    // Read relational operator into relop
    ss >> relop;
    // REad right operand into rop
    ss >> rop;
    // Get location for the symbol rop (rop_location)
    rop_location = get_symbol_location(rop);
    // read the 'goto' into unused and ignore it
    ss >> unused;
    // read line number into linen
    ss >> line_number;
    // Search the symbol table for that line number. A failed search will require the generation of partial branch instructions until second pass
    int index = search_symbol_table(line_number, 'L');

    // Test relop and generate the appropriate complete or partial instructions for this relational operator
    if (relop == "==")
    {
        // Generate Load
        memory_check();
        memory[next_instruction_addr] = LOAD * 100 + lop_location;
        next_instruction_addr++;

        // Generate Subract
        memory_check();
        memory[next_instruction_addr] = SUBTRACT * 100 + rop_location;
        next_instruction_addr++;

        // Generate BRANCHNEG
        memory_check();
        if (index == -1)
        {
            memory[next_instruction_addr] = BRANCHZERO * 100;
            flags[next_instruction_addr] = line_number;
        }
        else
        {
            memory[next_instruction_addr] = BRANCHZERO * 100 + symbol_table[index].location;
        }
        next_instruction_addr++;
    }
    else if (relop == "!=")
    {
        // Generate Load
        memory_check();
        memory[next_instruction_addr] = LOAD * 100 + lop_location;
        next_instruction_addr++;

        // Generate Subract
        memory_check();
        memory[next_instruction_addr] = SUBTRACT * 100 + rop_location;
        next_instruction_addr++;

        memory_check();
        memory[next_instruction_addr] = BRANCHZERO * 100 + next_instruction_addr + 2;
        next_instruction_addr++;

       // Generate BRANCH
        memory_check();
        if (index == -1)
        {
            memory[next_instruction_addr] = BRANCH * 100;
            flags[next_instruction_addr] = line_number;
        }
        else
        {
            memory[next_instruction_addr] = BRANCH * 100 + symbol_table[index].location;
        }
        next_instruction_addr++;
    }
    else if (relop == "<")
    {
        // Generate Load
        memory_check();
        memory[next_instruction_addr] = LOAD * 100 + lop_location;
        next_instruction_addr++;

        // Generate Subract
        memory_check();
        memory[next_instruction_addr] = SUBTRACT * 100 + rop_location;
        next_instruction_addr++;

        // Generate BRANCHNEG
        memory_check();
        if (index == -1)
        {
            memory[next_instruction_addr] = BRANCHNEG * 100;
            flags[next_instruction_addr] = line_number;
        }
        else
        {
            memory[next_instruction_addr] = BRANCHNEG * 100 + symbol_table[index].location;
        }
        next_instruction_addr++;
    }
    else if (relop == "<=")
    {
        // Generate Load
        memory_check();
        memory[next_instruction_addr] = LOAD * 100 + lop_location;
        next_instruction_addr++;

        // Generate Subract
        memory_check();
        memory[next_instruction_addr] = SUBTRACT * 100 + rop_location;
        next_instruction_addr++;

        // Generate BRANCHNEG
        memory_check();
        if (index == -1)
        {
            memory[next_instruction_addr] = BRANCHNEG * 100;
            flags[next_instruction_addr] = line_number; 
            next_instruction_addr++;
            memory_check();
            memory[next_instruction_addr] = BRANCHZERO * 100;
            flags[next_instruction_addr] = line_number;

        }
        else
        {
            memory[next_instruction_addr] = BRANCHNEG * 100 + symbol_table[index].location;
            next_instruction_addr++;
            memory_check();
            memory[next_instruction_addr] = BRANCHZERO * 100 + symbol_table[index].location;
        }
        next_instruction_addr++;
    }
    else if (relop == ">")
    {
        // Generate Load
        memory_check();
        memory[next_instruction_addr] = LOAD * 100 + rop_location;
        next_instruction_addr++;

        // Generate Subract
        memory_check();
        memory[next_instruction_addr] = SUBTRACT * 100 + lop_location;
        next_instruction_addr++;

        // Generate BRANCHNEG
        memory_check();
        if (index == -1)
        {
            memory[next_instruction_addr] = BRANCHNEG * 100;
            flags[next_instruction_addr] = line_number;
        }
        else
        {
            memory[next_instruction_addr] = BRANCHNEG * 100 + symbol_table[index].location;
        }
        next_instruction_addr++;
    }
    else if (relop == ">=")
    {
        // Generate Load
        memory_check();
        memory[next_instruction_addr] = LOAD * 100 + rop_location;
        next_instruction_addr++;

        // Generate Subract
        memory_check();
        memory[next_instruction_addr] = SUBTRACT * 100 + lop_location;
        next_instruction_addr++;

        // Generate BRANCHNEG
        memory_check();
        if (index == -1)
        {
            memory[next_instruction_addr] = BRANCHNEG * 100;
            flags[next_instruction_addr] = line_number;
            next_instruction_addr++;
            memory_check();
            memory[next_instruction_addr] = BRANCHZERO * 100;
            flags[next_instruction_addr] = line_number;

        }
        else
        {
            memory[next_instruction_addr] = BRANCHNEG * 100 + symbol_table[index].location;
            next_instruction_addr++;
            memory_check();
            memory[next_instruction_addr] = BRANCHZERO * 100 + symbol_table[index].location;
        }
        next_instruction_addr++;
    }
}

/**
 * Generates code for an "goto" instruction.
 *
 * @param ss Input string stream from which to read.
 *
 ********************************************************************/
void scc::handle_goto(istringstream &ss)
{
    string token;

    ss >> token;

    // Search symbol table for the line number
    int idx = search_symbol_table(stoi(token), 'L');

    memory_check();
    if (idx == -1) // after goto line
    {
        memory[next_instruction_addr] = BRANCH * 100;
        flags[next_instruction_addr] = stoi(token);
    }
    else // before goto line
    {
        memory[next_instruction_addr] = BRANCH * 100 + symbol_table[idx].location;
    }
    next_instruction_addr++;
}

/**
 * Generates code for an "print" instruction.
 *
 * @param ss Input string stream from which to read.
 *
 ********************************************************************/
void scc::handle_print(istringstream &ss)
{
    string token;

    ss >> token;

    // Get the location of the symbol
    int location = get_symbol_location(token);

    // Generate WRITE 
    memory_check();
    memory[next_instruction_addr] = WRITE * 100 + location;
    next_instruction_addr++;
}

/**
 * Generates code for an "let" instruction.
 *
 * @param ss Input string stream from which to read.
 * @param buffer rest of the string buffer
 ********************************************************************/
void scc::handle_let(istringstream &ss, const string& buffer)
{
    // 85 let x (y + 10) * (z - 3)

    string lvar; // variabvle on left of statement
    int lvar_location;
    string token, postfix;

    // Read the variable on the left side of the '=' into lvar
    ss >> lvar;
    // Get the location of the symbol lvar (lvar_location)
    lvar_location = get_symbol_location(lvar);
    // Locate the '=' in buffer. Infix string starts after that
    // call your convert funciton, passing it the infix string, to get the postfix string to process
    postfix = convert(buffer.substr(buffer.find("=") + 1));

    istringstream sp(postfix);
    int next_stack_idx = 0;
    while (sp >> token)
    {
        if (islower(token[0]) || isdigit(token[0]))
        {
            // This is an operand (variable or constant)

            // Get the location of token from the symbol table (location)
            int location = get_symbol_location(token);

            memory_check();
            memory[next_instruction_addr] = LOAD * 100 + location;
            next_instruction_addr++;

            memory_check();
            memory[next_instruction_addr] = STORE * 100;
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_instruction_addr++;
            next_stack_idx++;
        }
        else if (token == "+")
        {
            memory_check();
            memory[next_instruction_addr] = LOAD * 100;     // omit address
            next_stack_idx--;
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_instruction_addr++;

            memory_check();
            memory[next_instruction_addr] = ADD * 100;      // for addition, omit address
            next_stack_idx--;
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_instruction_addr++;

            memory_check();
            memory[next_instruction_addr] = STORE * 100;    // omit address
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_stack_idx++;
            next_instruction_addr++;
        }
        else if (token == "*")
        {
            memory_check();
            memory[next_instruction_addr] = LOAD * 100;     // omit address
            next_stack_idx--;
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_instruction_addr++;

            memory_check();
            memory[next_instruction_addr] = MULTIPLY * 100;      // for addition, omit address
            next_stack_idx--;
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_instruction_addr++;

            memory_check();
            memory[next_instruction_addr] = STORE * 100;    // omit address
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_stack_idx++;
            next_instruction_addr++;
        }
        else if (token == "-")
        {
            memory_check();
            memory[next_instruction_addr] = LOAD * 100;        // omit address
            next_stack_idx--;
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_instruction_addr++;
            
            memory_check();
            memory[next_instruction_addr] = STORE * 100;       // omit address
            flags[next_instruction_addr] = -2;
            next_instruction_addr++;
            
            memory_check();
            memory[next_instruction_addr] = LOAD * 100;        // omit address
            next_stack_idx--;
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_instruction_addr++;
            
            memory_check();
            memory[next_instruction_addr] = SUBTRACT * 100;    // for subtraction, omit address
            flags[next_instruction_addr] = -2;
            next_instruction_addr++;
            
            memory_check();
            memory[next_instruction_addr] = STORE * 100;       // omit address
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_stack_idx++;
            next_instruction_addr++;
        }
        else // if (token == "/")
        {
             memory_check();
            memory[next_instruction_addr] = LOAD * 100;        // omit address
            next_stack_idx--;
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_instruction_addr++;
            
            memory_check();
            memory[next_instruction_addr] = STORE * 100;       // omit address
            flags[next_instruction_addr] = -2;
            next_instruction_addr++;
            
            memory_check();
            memory[next_instruction_addr] = LOAD * 100;        // omit address
            next_stack_idx--;
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_instruction_addr++;
            
            memory_check();
            memory[next_instruction_addr] = DIVIDE * 100;    // for subtraction, omit address
            flags[next_instruction_addr] = -2;
            next_instruction_addr++;
            
            memory_check();
            memory[next_instruction_addr] = STORE * 100;       // omit address
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_stack_idx++;
            next_instruction_addr++;
        }
    }

    // Pop the final result off the stack

    memory_check();
    memory[next_instruction_addr] = LOAD * 100;
    flags[next_instruction_addr] = -3;
    next_instruction_addr++;

    memory_check();
    memory[next_instruction_addr] = STORE * 100 + lvar_location;
    next_instruction_addr++;
}
