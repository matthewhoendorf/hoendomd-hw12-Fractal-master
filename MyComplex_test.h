/*
  MyComplex_test.h
  Unit tests for the MyComplex class
  
*/

#include "MyComplex.h"
#include <stdexcept>

#include <cxxtest/TestSuite.h>

class MyComplexTest : public CxxTest::TestSuite {
public:

  void testAddComplex1(){
    MyComplex a(1,2);
    MyComplex b(3,4);
    MyComplex c = a.add(b);
    TS_ASSERT_EQUALS(c.getReal(), 4);
  }

  void testAddComplex2(){
    MyComplex a(1,2);
    MyComplex b(3,4);
    MyComplex c = a.add(b);
    TS_ASSERT_EQUALS(c.getImg(), 6);
  }

  void testSubtractComplex1(){
    MyComplex a(1,2);
    MyComplex b(3,4);
    MyComplex c = a.subtract(b);
    TS_ASSERT_EQUALS(c.getReal(), -2);
  }

  void testSubtractComplex2(){
    MyComplex a(1,2);
    MyComplex b(3,4);
    MyComplex c = a.subtract(b);
    TS_ASSERT_EQUALS(c.getImg(), -2);
  }
  
  void testMultComplex1(){
    MyComplex a(1,2);
    MyComplex b(3,4);
    MyComplex c = a.mult(b);
    TS_ASSERT_EQUALS(c.getReal(), -5);
  }

  void testMultComplex2(){
    MyComplex a(1,2);
    MyComplex b(3,4);
    MyComplex c = a.mult(b);
    TS_ASSERT_EQUALS(c.getImg(), 10);
  }

  void testMultComplex3(){
    MyComplex a(-1,-2);
    MyComplex b(-3,-4);
    MyComplex c = a.mult(b);
    TS_ASSERT_EQUALS(c.getReal(), -5);
  }

  void testMultComplex4(){
    MyComplex a(-1,-2);
    MyComplex b(-3,-4);
    MyComplex c = a.mult(b);
    TS_ASSERT_EQUALS(c.getImg(), 10);
  }

  void testDivComplex1(){
    MyComplex a(1,2);
    MyComplex b(3,4);
    MyComplex c = a.div(b);
    TS_ASSERT_EQUALS(c.getReal(), 0.44);
  }

  void testDivComplex2(){
    MyComplex a(1,2);
    MyComplex b(3,4);
    MyComplex c = a.div(b);
    TS_ASSERT_EQUALS(c.getImg(), 0.08);
  }

  void testDivComplex3(){
    MyComplex a(-1,-2);
    MyComplex b(-3,-4);
    MyComplex c = a.div(b);
    TS_ASSERT_EQUALS(c.getReal(), 0.44);
  }

  void testDivComplex4(){
    MyComplex a(-1,-2);
    MyComplex b(-3,-4);
    MyComplex c = a.div(b);
    TS_ASSERT_EQUALS(c.getImg(), 0.08);
  }

  void testMultNum1(){
    MyComplex a(1,2);
    MyComplex c = a.mult(3);
    TS_ASSERT_EQUALS(c.getReal(), 3);
  }

  void testMultNum2(){
    MyComplex a(1,2);
    MyComplex c = a.mult(3);
    TS_ASSERT_EQUALS(c.getImg(), 6);
  }

  void testDivNum1(){
    MyComplex a(1,2);
    MyComplex c = a.div(2);
    TS_ASSERT_EQUALS(c.getReal(), 0.5);
  }

  void testDivNum2(){
    MyComplex a(1,2);
    MyComplex c = a.div(2);
    TS_ASSERT_EQUALS(c.getImg(), 1);
  }

  void testCon1(){
    MyComplex a(1,2);
    MyComplex c = a.conj();
    TS_ASSERT_EQUALS(c.getImg(), -2);
  }

  void testMag1(){
    MyComplex a(1,2);
    TS_ASSERT_EQUALS(a.mag2(), 5);
  }

  void testMag2(){
    MyComplex a(3,4);
    TS_ASSERT_EQUALS(a.mag2(), 25);
  }

  void testDist1(){
    MyComplex a(1,2);
    MyComplex b(3,4);
    TS_ASSERT_EQUALS(a.dist2(b), 8);
  }

  void testDist2(){
    MyComplex a(1,2);
    MyComplex b(1,2);
    TS_ASSERT_EQUALS(a.dist2(b), 0);
  }
  
};
