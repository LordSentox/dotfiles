#include "config.hpp"
#include <fstream>
#include <stdexcept>

Config::Config (const std::string &filename)
{
	std::ifstream input (filename);
	if (!input.is_open())
		throw std::invalid_argument (filename + " could not be opened. Failed to load configuration.");

	std::string line;
	while (std::getline(input, line))
	{
		if (!line.empty() && line [0] != '#')
			push_back (line);
	}
}
