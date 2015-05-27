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

#ifndef DOTE_ELEMENT_HPP
#define DOTE_ELEMENT_HPP

namespace dote
{

// Class representing an element that stands in relation to other elements
// sorrounding it, for instance after it has been parsed.
class Element
{
public:
	Element () noexcept;
	virtual ~Element () noexcept;

	Element *previous () const noexcept;
	virtual void setPrevious (Element *previous);

	Element *next () const noexcept;
	virtual void setNext (Element *next);

protected:
	Element *m_previous;
	Element *m_next;
};

}

#endif
