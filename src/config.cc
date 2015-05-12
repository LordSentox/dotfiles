#include "config.hpp"
#include <fstream>

Config::Config (const std::string &filename)
{
	std::ifstream input (filename);
	if (!input.is_open())
		throw std::exception (filename + " could not be opened. Failed to load configuration.");

	std::string line;
	while (std::getline(input, line))
	{
		if (!line.empty() && line [0] != '#')
			push_back (line);
	}
}
