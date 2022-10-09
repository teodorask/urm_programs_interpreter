#include "URMprogram.h"
#include <iostream>
#include <string>
#include "Command.h"

void testLoad()
{
	URMprogram pr;
	pr.load("./example_programs/add.urm");
	pr.code();
}

void testInstr()
{
	URMprogram pr;
	pr.load("./example_programs/add.urm");
	pr.set(0, 5);
	pr.set(1, 9);
	pr.run();
	pr.mem(2, 2);
}

void testCommands()
{
	URMprogram pr;
	pr.load("./example_programs/fib-add.urm");
	pr.code();
	pr.set(0, 9);
	pr.run();
	pr.mem(0, 7);
	pr.code();
}

void testAdd()
{
	URMprogram pr;
	pr.load("./example_programs/fib.urm");
	pr.code();
	pr.set(0, 9);
	pr.run();
	pr.mem(0, 7);
	pr.code(); 
}

void dialog()
{
	std::cout << "Supported commands: \n/zero x y \n/set x y \n/copy x y z \n/mem x y \n/load <file name> \n";
	std::cout << "/run \n/add <file name> \n/quote <command/instruction> \n/code \n/comment <text> \n";

	URMprogram pr;
	while (true)
	{
		std::string command;
		getline(std::cin, command);
		Command* cmd = Command::cmdFactory(pr, command);
		cmd->execute();
	}
}

int main()
{
	//testLoad();
	//testInstr();
	//testLabel();
	//testCommands();
	//testAdd();

	dialog();
	return 0;
}