#ifndef STATEMENT_HPP
#define STATEMENT_HPP

#include <string>

class Context;

//---------------------------------------
// A statement that can be run. Perhaps
// base-class for all other statements to
// come?
//---------------------------------------
class Statement
{
public:
	// Create the statement from the given string.
	// This does not yet execute the statement.
	Statement (const std::string &string);
	virtual ~Statement () = default;

	virtual int execute () = 0;
};

#endif
