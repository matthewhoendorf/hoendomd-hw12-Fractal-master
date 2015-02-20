#ifndef COMPLEX_H
#define COMPLEX_H 
/*    @file MyComplex.cpp    
      @author Matt Hoendorf <hoendomd@mail.uc.edu>
      @date 2014/11/18

			@description 
*/
#include <iostream>
#include <stdlib.h>

using namespace std;

class MyComplex{
  
  public:
  double real;
  double complex;
  
  MyComplex():real(0.0),complex(0.0){};
  
  MyComplex(double a, double b){
    real = a;
    complex = b;
  }
  
  MyComplex add(const MyComplex &b) const{
    MyComplex ret;
    ret.real = real + b.real;
    ret.complex = complex + b.complex;
    return ret;
  }

  MyComplex subtract(const MyComplex &b) const{
    MyComplex ret;
    ret.real = real - b.real;
    ret.complex = complex - b.complex;
    return ret;
  }

  MyComplex mult(const double &a) const{
    MyComplex ret;
    ret.real = real * a;
    ret.complex = complex * a;
    return ret;
  }

  MyComplex mult(const MyComplex &b) const{
    MyComplex ret;
    ret.real = (real * b.real) - (complex * b.complex);
    ret.complex = (real * b.complex) + (complex * b.real);
    return ret;
  }

  MyComplex conj() const{
    MyComplex ret;
    ret.real = real;
    ret.complex = complex * -1;
    return ret;
  }

  MyComplex div(const double &b) const{
    MyComplex ret;
    ret.real = real / b;
    ret.complex = complex / b;
    return ret;
  }

  MyComplex div(const MyComplex &b) const{
    float d = (b.real * b.real) + (b.complex * b.complex);
    MyComplex ret;
    ret.real = (real * b.real + complex * b.complex) / d;
    ret.complex = (complex * b.real - real * b.complex) / d;
    return ret;
  }
  
  double mag2() const{
    double mag;
    mag = (real*real)+(complex*complex);
    return mag;
  }
  
  double dist2(const MyComplex &b){
    double dist;
    dist = ((real-b.real)*(real-b.real))+((complex-b.complex)*(complex-b.complex));
    return dist;
  }

  double getReal() const{
    return real;
  }

  double getImg() const{
    return complex;
  }
  
};
#endif
