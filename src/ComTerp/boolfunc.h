/*
 * Copyright (c) 2001 Scott E. Johnston
 * Copyright (c) 2000 IET Inc.
 * Copyright (c) 1994-1997,1999 Vectaport Inc.
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
 * This is a collection of boolean operators.  They inherit the 
 * C-like promotion mechanism of NumFunc. 
 */

#if !defined(_boolfunc_h)
#define _boolfunc_h

#include <ComTerp/numfunc.h>

//: && (and) operator.
class AndFunc : public NumFunc {
public:
    AndFunc(ComTerp*, boolean pre=false);

    virtual void execute();
    virtual boolean post_eval() { return !_pre; }
    virtual const char* docstring() { 
      return "&& is the and operator"; }

protected:
    boolean _pre;
};

//: || (or) operator.
class OrFunc : public NumFunc {
public:
    OrFunc(ComTerp*, boolean pre=false);

    virtual void execute();
    virtual boolean post_eval() { return !_pre; }
    virtual const char* docstring() { 
      return "|| is the or operator"; }

protected:
    boolean _pre;

};

//: ! (negate) operator.
class NegFunc : public NumFunc {
public:
    NegFunc(ComTerp*);

    virtual void execute();
    virtual const char* docstring() { 
      return "! is the negate operator"; }

};


//: == (equality) operator.
// also useful for partial string comparison with :n keyword, i.e.
// eq("string1" "string2" :n 6) returns true.
// also useful for symbol comparison with :sym keyword.
class EqualFunc : public NumFunc {
public:
    EqualFunc(ComTerp*);

    virtual void execute();
    virtual const char* docstring() { 
      return "== is the equal operator\nbool=eq(str1 str2 :n len) -- partial string comparison\nbool=eq(sym1 sym2 :sym) -- symbol comparison"; }

};


//: != (non-equality) operator.
// also useful for partial string comparison with :n keyword.
// neq("string1" "string2" :n 6) returns false.
// also useful for symbol comparison with :sym keyword.
class NotEqualFunc : public NumFunc {
public:
    NotEqualFunc(ComTerp*);

    virtual void execute();
    virtual const char* docstring() { 
      return "!= is the not-equal operator\nbool=neq(str1 str2 :n len) -- partial string comparison\nbool=neq(sym1 sym2 :sym) -- symbol comparison"; }

};


//: > (greater than) operator.
// also useful for partial string comparison with :n keyword, i.e.
// gt("string1" "string2" :n 6) returns false.
// also useful for symbol comparison with :sym keyword.
class GreaterThanFunc : public NumFunc {
public:
    GreaterThanFunc(ComTerp*);

    virtual void execute();
    virtual const char* docstring() { 
      return "> is the greater-than operator\nbool=gt(str1 str2 :n len) -- partial string comparison\nbool=gt(sym1 sym2 :sym) -- symbol comparison"; }

};


//: >= (greater than or equal) operator.
// also useful for partial string comparison with :n keyword.
// also useful for symbol comparison with :sym keyword.
class GreaterThanOrEqualFunc : public NumFunc {
public:
    GreaterThanOrEqualFunc(ComTerp*);

    virtual void execute();
    virtual const char* docstring() { 
      return ">= is the greater-than-or-equal operator\nbool=gt_or_eq(str1 str2 :n len) -- partial string comparison\nbool=gt_or_eq(sym1 sym2 :sym) -- symbol comparison"; }

};


//: < (less than) operator.
// also useful for partial string comparison with :n keyword, i.e.
// lt("string2" "string1" :n 6) returns false.
// also useful for symbol comparison with :sym keyword.
class LessThanFunc : public NumFunc {
public:
    LessThanFunc(ComTerp*);

    virtual void execute();
    virtual const char* docstring() { 
      return "< is the less-than operator\nbool=lt(str1 str2 :n len) -- partial string comparison\nbool=lt(sym1 sym2 :sym) -- symbol comparison"; }

};

//: <= (less than or equal) operator.
class LessThanOrEqualFunc : public NumFunc {
// also useful for partial string comparison with :n keyword.
// also useful for symbol comparison with :sym keyword.
public:
    LessThanOrEqualFunc(ComTerp*);

    virtual void execute();
    virtual const char* docstring() { 
      return "<= is the less-than-or-equal operator\nbool=lt_or_eq(str1 str2 :n len) -- partial string comparison\nbool=lt_or_eq(sym1 sym2 :sym) -- symbol comparison"; }

};

//: returns true
class TrueFunc : public NumFunc {
// Accepts any arguments and returns true
public:
    TrueFunc(ComTerp*);

    virtual void execute();
    virtual const char* docstring() { 
      return "true([...]) -- accepts any arguments and returns true"; }

};

//: returns false
class FalseFunc : public NumFunc {
// Accepts any arguments and returns false
public:
    FalseFunc(ComTerp*);

    virtual void execute();
    virtual const char* docstring() { 
      return "false([...]) -- accepts any arguments and returns false"; }

};


#endif /* !defined(_boolfunc_h) */

