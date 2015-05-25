/*******************************************************************************
* The MIT License (MIT)
*
* Copyright (c) 2015 Arne Dussin
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*******************************************************************************/

#ifndef PARSER_HPP
#define PARSER_HPP

#include "keywords.hpp"

#include <istream>
#include <vector>

class Parser
{
public:
	Parser () noexcept;
	~Parser () noexcept;

	// Initializes the parser on the given input-stream. Throws an exception in
	// case the input-stream is invalid.
	void initialize (std::istream *input);

	// Finish current parsing session. Cleans up the instance. Also called when
	// the destructor is invoked.
	void finish () noexcept;

	// Functions to look up the next statement or parse it.
	// Parsing returns 0 on success and the Error-Code on failure.
	// It will also print a message on screen in case something went wrong.
	bool hasNext () const noexcept;
	int parseOne () noexcept;

	// Executes the current statement and returns the Error-Code of that
	// statement. In case no statement has been loaded it throws an exception.
	int executeOne () const;

private:
	// The current statement on which work is done. nullptr in case no statement
	// has been loaded. The pointer actually just points to the first keyword.
	// On deletion that keyword will take care of the other statements.
	Keyword *m_currentStatement;

	// The input stream from which the parser get's it's input.
	std::istream *m_input;

	struct
	{
		char character;
		std::string word;

		bool readingString;
	} m_pickup;
};

#endif
