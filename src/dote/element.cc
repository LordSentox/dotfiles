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

#include "element.hpp"
#include <iostream>

using namespace dote;

Element::Element () noexcept
: m_previous {nullptr}, m_next {nullptr}
{
}

Element::~Element () noexcept
{
	// Every element takes care of the next one, so that only the first one
	// has to be destroyed explicitely in a chain.
	if (m_next != nullptr)
		delete m_next;
}

Element *Element::previous () const noexcept
{
	return m_previous;
}

void Element::setPrevious (Element *previous)
{
	m_previous = previous;
}

Element *Element::next () const noexcept
{
	return m_next;
}

void Element::setNext (Element *next)
{
	if (m_next != nullptr)
		std::cout << "Changing next element even though the previous one was not null.\n";

	m_next = next;
}
