/*    @file fractal.cpp    
      @author Matt Hoendorf <hoendomd@mail.uc.edu>
      @date 2014/11/18

			@description 
*/
#include <iostream>
#include <stdlib.h>
#include "MyComplex.h"
#include <math.h>
#include <sstream>

#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"

#define cimg_display 0
#include "CImg.h"

using namespace std;

MyComplex f(const MyComplex &a){
  MyComplex ret = (a.mult(a).mult(a)).add(a.mult(a)).subtract(3);
  return ret;
}

MyComplex df(const MyComplex &a){
  MyComplex ret = (a.mult(a).mult(3)).add(a.mult(2));
  return ret;
}

struct newton_ans_t{ 
  
  MyComplex ans; 
  unsigned int steps;
};

newton_ans_t newton(MyComplex start,MyComplex(*f)(const MyComplex &a),MyComplex(*df)(const MyComplex &a),unsigned int max_steps, double min_diff){
  newton_ans_t ret;
  MyComplex current = start;
  MyComplex next;
  MyComplex temp;
  ret.steps = 0;

  do{
    next = current.subtract(f(current).div(df(current)).mult(1.5));
    temp = current;
    current = next;
    ret.ans = next;
    ret.steps++;
  } while(ret.steps <= max_steps && next.dist2(temp) > min_diff);

  return ret;
}

int main(){
  srand(time(0));

  // Generate the html page
  cgicc::Cgicc cgi;

  // Send HTTP header
  cout << cgicc::HTTPHTMLHeader() << endl;

  // Set up the HTML document
  cout << "<html>\n" << "<head><title>Fractals</title></head>\n" << endl;
  cout << "<body><h1>Fractals</h1>\n" << endl;

  cgicc::form_iterator width = cgi.getElement("mywidth");
  cgicc::form_iterator height = cgi.getElement("myheight");
  string input_w;
  string input_h;
    
  // Generate an image
  if(width != cgi.getElements().end() && height != cgi.getElements().end()) {
    
    input_w = **width;
    input_h = **height;

    cout << "<form method=\"GET\">\n";
    cout << "Width: <input type=\"text\" name=\"mywidth\" value=\"" << input_w << "\">\n";
    cout << "Height: <input type=\"text\" name=\"myheight\" value=\"" << input_h << "\">\n";
    cout << "<input type=\"submit\" value=\"Go!\">\n";
    cout << "</form>\n";
    
    int w = atoi((**width).c_str());
    int h = atoi((**height).c_str());

    cil::CImg<unsigned char> image(w,h,1, 3, 255); // Prefill image as white
    
    int r = rand() % 500;
    int g = rand() % 500;
    int b = rand() % 500;
    newton_ans_t current;

    for(int x = 0; x < w; x++){
      for(int y = 0; y < h; y++){
        MyComplex start(x-(w/2),y-(h/2));
        current = newton(start,f,df,500,0.0001);
        *(image.data(x, y, 0, 0)) = (current.steps * r) % 256;
        *(image.data(x, y, 0, 1)) = (current.steps * g) % 256;
        *(image.data(x, y, 0, 2)) = (current.steps * b) % 256;
      }
    }

    // Save the image with a random string for this particular request
    int num = rand() % 1000;
    stringstream stream;
    stream << "images/image" << num << ".png";
    string filename = stream.str();
    
    // Saves the image relative to the running server, so images and cgi-bin should be subfolders.
    image.save(filename.c_str());
  
    // Include the image in the html, this is relative to the cgi-bin folder.
    cout << "<img src=\"../" << filename << "\" >" << endl;

  }

  else{
    
    input_w = "800";
    input_h = "800";

    cout << "<form method=\"GET\">\n";
    cout << "Width: <input type=\"text\" name=\"mywidth\" value=\"" << input_w << "\">\n";
    cout << "Height: <input type=\"text\" name=\"myheight\" value=\"" << input_h << "\">\n";
    cout << "<input type=\"submit\" value=\"Go!\">\n";
    cout << "</form>\n";
  }

  // Close the HTML document
  cout << "</body></html>\n";
  
  
  return 0;


}
