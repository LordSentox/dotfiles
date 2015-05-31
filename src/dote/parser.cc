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

#include "parser.hpp"
#include <iostream>
#include <assert.h>
#include <stdexcept>

using namespace dote;

Parser::Parser () noexcept
: m_currentStatement {nullptr}, m_input {nullptr}
{
}

Parser::~Parser () noexcept
{
	finish();
}

void Parser::initialize (std::istream *input)
{
	assert (m_input == nullptr);
	assert (m_currentStatement == nullptr);

	if (input == nullptr)
		throw std::runtime_error {"Attempted to initialize Parser on nullptr-input-stream."};

	m_input = input;
}

void Parser::finish () noexcept
{
	if (m_currentStatement != nullptr)
	{
		delete m_currentStatement;
		m_currentStatement = nullptr;
	}

	// The input does not have to be deleted here. It is expected to be
	// handled where it's origins lie.
	m_input = nullptr;
}

bool Parser::hasNext () const noexcept
{
	if (m_input == nullptr)
		return false;

	return !m_input->eof();
}

int Parser::parseOne () noexcept
{
	if (!hasNext())
	{
		std::cout << "Unable to parse statement. No statement available to parse.\n";
		return -1;
	}

	if (m_currentStatement != nullptr)
	{
		delete m_currentStatement;
		m_currentStatement = nullptr;
	}

	m_pickup.word = "";
	m_pickup.readingString = false;
	auto readChar = [&](){ (*m_input) >> std::noskipws >> m_pickup.character; };

	for (readChar(); m_pickup.character != ';' && !m_input->eof(); readChar())
	{

	}

	return 0;
}

int Parser::executeOne () const
{
	if (m_currentStatement == nullptr)
		throw std::runtime_error {"Unable to execute a statement. No statement has been loaded."};

	// Recursive call to execute the complete statement by calling the firstmost element.
	return m_currentStatement->execute();
}
