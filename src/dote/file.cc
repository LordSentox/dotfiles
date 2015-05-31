
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

#include "file.hpp"
#include "keywords.hpp"

using namespace dote;

File::File () noexcept
: m_parsing {false}
{

}

File::File (const std::string &filename) noexcept
{
	open (filename);
}

bool File::open (const std::string &filename) noexcept
{
	// In case it's still parsing a file a (different?) file cannot be opened.
	// It has to either finish or be aborted.
	if (m_parsing)
		return false;

	m_input.open (filename);
	if (!m_input.is_open())
		return false;

	beginParse();
	return true;
}

bool File::isOpen () const noexcept
{
	return m_input.is_open();
}

void File::beginParse ()
{
	if (!isOpen())
		throw std::string {"Cannot begin parsing when there is no input-file opened."};

	// TODO: Begin parsing.
}

//------------------------------------------
// Multex class to make multithreading safe.
//------------------------------------------

File::Multex::Multex () noexcept
: m_locked {0}
{
}

void File::Multex::lock (uint8_t what) noexcept
{
	if (m_mutex.try_lock())
	{}
}

/*
short File::Status::parsing () noexcept
{
	std::lock_guard<std::mutex> lock {m_mutex};
	return m_parsing;
}

bool File::Status::setParsing (short parsing) noexcept
{
	std::lock_guard<std::mutex> lock {m_mutex};

	if (m_executing == parsing && parsing != -1)
		return false;

	m_parsing = parsing;
	return true;
}

short File::Status::executing () noexcept
{
	std::lock_guard<std::mutex> lock {m_mutex};
	return m_executing;
}

bool File::Status::setExecuting (short executing) noexcept
{
	std::lock_guard<std::mutex> lock {m_mutex};

	if (m_parsing == executing && executing != -1)
		return false;

	m_executing = executing;
	return true;
}
*/
