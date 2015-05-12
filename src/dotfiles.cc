#include "config.hpp"
#include <iostream>

int main (int argc, char *argv[])
{
	// Execute all actions that are asked for.
	for (int i = 1; i < argc; ++i)
	{
		std::string command (argv [i]);
		if (command == "--update")
		{
			std::cout << "Update has been started.." << std::endl;
		}
		else {
			std::cout << "Unrecognized flag: " << command << std::endl;
		}
	}

	return 0;
}
