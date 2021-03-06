/*
 * Copyright (c) 2011 Wave Semiconductor Inc.
 * Copyright (c) 2001 Scott E. Johnston
 * Copyright (c) 2000 IET Inc.
 * Copyright (c) 1999 Vectaport Inc.
 *
 * Permission to use, copy, modify, distribute, and sell this software and
 * its documentation for any purpose is hereby granted without fee, provided
 * that the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the names of the copyright holders not be used in
 * advertising or publicity pertaining to distribution of the software
 * without specific, written prior permission.  The copyright holders make
 * no representations about the suitability of this software for any purpose.
 * It is provided "as is" without express or implied warranty.
 *
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS
 * SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY SPECIAL,
 * INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING
 * FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
 * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION
 * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 * 
 */

/*
 * collection of list manipulation functions
 */

#if !defined(_listfunc_h)
#define _listfunc_h

#include <ComTerp/comfunc.h>

class ComTerp;
class ComValue;

//: create list command for ComTerp.
// lst=list([olst|strm|val] :strmlst :attr :size n) -- create list, copy list, or convert stream
class ListFunc : public ComFunc {
public:
    ListFunc(ComTerp*);

    virtual void execute();
    virtual boolean post_eval() { return true; }
    virtual const char* docstring() { 
      return "lst=%s([olst|strm|val] :strmlst :attr :size n) -- create list, copy list, or convert stream (unary $$)"; }
};

//: list member command for ComTerp.
// val=at(list|attrlist|str n :set val :ins val) -- return (or set or insert after) the nth item in a list or string.
class ListAtFunc : public ComFunc {
public:
    ListAtFunc(ComTerp*);

    virtual void execute();
    virtual const char* docstring() { 
      return "val=at(list|attrlist n :set val :ins val) -- return (or set or insert after) the nth item in a list"; }
};

//: list size command for ComTerp.
// num=size(list|attrlist|string) -- return size of a list (or string).
class ListSizeFunc : public ComFunc {
public:
    ListSizeFunc(ComTerp*);

    virtual void execute();
    virtual const char* docstring() { 
      return "val=size(list|attrlist|string) -- return the size of the list (or string)"; }
};

//: , (tuple) operator.
class TupleFunc : public ComFunc {
public:
    TupleFunc(ComTerp*);

    virtual void execute();
    virtual const char* docstring() { 
      return ", is the tuple operator"; }

    CLASS_SYMID("TupleFunc");

};


//: list index command for ComTerp.
// val=index(list|str val|char|str :last :all :substr) -- return index of value (or char or string) in list (or string), nil if not found.
class ListIndexFunc : public ComFunc {
public:
    ListIndexFunc(ComTerp*);

    virtual void execute();
    virtual const char* docstring() { 
      return "num=index(list|str val|char|str :last :all :substr) -- return index of value (or char or string) in list (or string), nil if not found"; }
};

#endif /* !defined(_listfunc_h) */
