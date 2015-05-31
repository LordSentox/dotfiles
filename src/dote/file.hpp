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

#ifndef DOTE_FILE_HPP
#define DOTE_FILE_HPP

#include <string>
#include <fstream>
#include <mutex>

namespace dote
{

class File
{
public:
	File () noexcept;
	File (const std::string &filename) noexcept;

	bool open (const std::string &filename) noexcept;
	bool isOpen () const noexcept;

	// Loads up to 8 Statements asynchronously into the buffer. abortParse is
	// really just a hard but clean stop for parsing, which is not recommended
	// under normal conditions, since the parse-thread will stop when it's done.
	void beginParse ();
	void abortParse () noexcept;

	// Execute the complete file. In case the parsing has not been started, this
	// function simply returns 0.
	int execute ();

private:
	// The input from which the parser will read the statements.
	std::ifstream m_input;

	// Variables to determine in which part of the buffer what operation is
	// currently being executed. The mutex will block so that the state cannot
	// be changed while the other state is being changed. -1 in case nothing is
	// being executed/parsed.
	class Multex
	{
	public:
		Multex () noexcept;

		void lock (uint8_t what) noexcept;
		void unlock (uint8_t what) noexcept;

	private:
		uint8_t m_locked;
		std::mutex m_mutex;
	} m_multex;

	// False by default and set to true when the asynchronous parsing starts.
	// It will then be set to false again afterwards, so the execution-thread
	// knows when to stop.
	bool m_parsing;

	// Buffer of 8 possible statements in the buffer. All non-loaded statements
	// are to be immediately set to nullptr.
	class Keyword *m_statements [8];
};

}

#endif
