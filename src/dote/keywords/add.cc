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

#include "add.hpp"
#include "package.hpp"
#include <assert.h>
#include <iostream>

using namespace dote;

void Add::setPrevious (Element *previous)
{
	if (previous != nullptr)
	{
		std::cout << "The add-keyword may not be preceded by anything more than blank space.\n";
		throw 2;
	}

	m_previous = previous;
}

void Add::setNext (Element *next)
{
	// For the time being only the package-keyword may follow the add-keyword.
	if (dynamic_cast<Package *> (next) == nullptr)
	{
		std::cout << "Unexpected specifier after 'add'.\n";
		throw 1;
	}

	m_next = next;
}

int Add::execute ()
{
	Keyword *next = dynamic_cast<Keyword *> (m_next);
	assert (next != nullptr);

	// The next keyword is actually the one that does the work.
	return next->execute();
};
