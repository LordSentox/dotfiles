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

#include "package.hpp"
#include "add.hpp"
#include "../string.hpp"
#include <assert.h>
#include <iostream>

using namespace dote;

void Package::setPrevious (Element *previous)
{
	if (previous == nullptr || dynamic_cast<Add *> (previous) == nullptr)
	{
		std::cout << "The package-keyword must always be preceded by one like 'add' or 'no'.\n";
		throw 1;
	}

	m_previous = previous;
}

void Package::setNext (Element *next)
{
	String *packageName = dynamic_cast<String *> (next);
	if (packageName == nullptr)
	{
		std::cout << "Expected the name of the package after the package-keyword.\n";
		throw 2;
	}
}

int Package::execute ()
{
	// Not properly handled in parser.cc in case this fails.
	assert (m_next != nullptr);
	assert (m_previous != nullptr);

	// This should never fail if the parser was written correctly.
	String *packageName = dynamic_cast<String *> (m_next);
	assert (packageName != nullptr);

	if (dynamic_cast<Add *> (m_previous) != nullptr)
	{
		std::cout << "Adding package " << (*packageName) << " (not yet implemented).\n";
	}
	//else if (dynamic_cast<No *> (m_previous) != nullptr)
	else
	{
		std::cout << "Removing package " << (*packageName) << " (not yet implemented).\n";
	}

	return 0;
}
