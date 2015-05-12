#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <vector>

class Config : public std::vector <std::string>
{
public:
	Config (const std::string &filename);

private:
	unsigned int parse ();

};

#endif
