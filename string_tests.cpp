#include "String.h"
#include <iostream>
#include <cstdlib>

void testDefaultConstructor();
void testCstyleConstructor();
void testCopyConstructor();
void testAccessors();
void testClear();
void testOperator_plus();
void testEmpty();
void testReserve();
void testResize();
void testOperatorEqualA();
void testOperatorEqualB();
void testOperatorEqualC();
void testOperatorPlusA();
void testOperatorPlusB();
void testOperatorPlusC();
void testOperator_plus2();


void testOpPlusB();


using std::cout;
using std::endl;

int main() {
  testDefaultConstructor();
  testCstyleConstructor();
  testCopyConstructor();
  testAccessors();
  testClear();
  testEmpty();
  testReserve();
  testResize();
  testOperatorEqualA();
  testOperatorEqualB();
  testOperatorEqualC();
  testOperatorPlusA();
  testOperatorPlusB();
  testOperatorPlusC();

  std::exit(EXIT_SUCCESS);
}

//Constructors

void testDefaultConstructor() {
  String str;
  cout << "Default constructor" << endl;
  cout << " Size : " << str.size() << "; and empty data : " << str.c_str() << endl;
}

void testCstyleConstructor() {
  String str("Test du C-style constructor");
  cout << str.c_str() << endl;
  cout << " Size : " << str.size() << " Capacity : " << str.capacity() << endl;
}

void testCopyConstructor() {
  String str("Test du copy constructor");
  String str2(str);
  cout << str.c_str() << endl;
  cout << " Size : " << str2.size() << " Capacity : " << str2.capacity() << endl;
}


// Accessors

void testAccessors(){
  String str("Test");
  cout << "Test of Accessors : "<< endl;
  cout << " data : " << str.c_str() << endl;
  cout << " capacity() : " << str.capacity() << endl;
  cout << " size() : " << str.size() << endl;
  cout << " length() : " << str.length() << endl;
  cout << " c_str() : " << str.c_str() << endl;
  cout << " max_size() : " << str.max_size() << endl;
}

//Member functions

void testClear(){
  String str("currentdata");
  cout << "Test of clear() : " << endl;
  cout << " Before clear() : data is : " << str.c_str() << "; size is : " << str.size() << endl;
  str.clear();
  cout << " After clear() : data is : " << str.c_str() << "; size is : " << str.size() << endl;
}

void testEmpty(){
  cout << "Test empty() :" << endl;
  String str;
  if (str.empty()){
    cout << " The string is empty" << endl;
  } else {
    cout << " The string is not empty" << endl;
  }
}

void testReserve(){
  String str;
  cout << "Test reserve() : " << endl;
  cout << " Before : size is " << str.size() << " and capacity is " << str.capacity() << endl;
  str.reserve(20);
  cout << " After : size is " << str.size() << " and capacity is " << str.capacity() << endl;
}

void testResize() {
  String str("currentdata");

  cout << "Test of resize : " << endl;
  cout << " Before resize : " << str.c_str() << endl;

  int newSize = 20;
  char fillChar = 'Y';
  str.resize(newSize, fillChar);
  cout << " After resize of 20 : " << str.c_str() << endl;

  newSize = -2;
  fillChar = 'Y';
  str.resize(newSize, fillChar);
  cout << " After resize of -2 : " << str.c_str() << endl;

  newSize = 11;
  fillChar = 'Y';
  str.resize(newSize, fillChar);
  cout << " After resize of 11 (current size) : " << str.c_str() << endl;

  newSize = 120;
  fillChar = 'Y';
  str.resize(newSize, fillChar);
  cout << "After resize of 120 (greater than maxSize_): " << str.c_str() << "; size is : " << str.size() << endl;
}

// Operators

void testOperatorEqualA(){
  String str("currentdata");
  cout << "Test of operator=(char)" << endl;
  cout << " Data before = : " << str.c_str() << endl;
  str = 'a';
  cout << " Data after = : " << str.c_str() << endl;
}

void testOperatorEqualB(){
  String str("currentdata");
  String other("otherdata");
  cout << "Test of operator=(const string&)" << endl;
  cout << " Data before = : " << str.c_str() << endl;
  str = other;
  cout << " Data after = : " << str.c_str() << endl;
}

void testOperatorEqualC(){
  String str("currentdata");
  cout << "Test of operator=(const char*)" << endl;
  cout << " Data before = : " << str.c_str() << endl;
  str = "otherdata";
  cout << " Data after = : " << str.c_str() << endl;
}

void testOperatorPlusA(){
  String str("Hello");
  cout << "Test of operator+(const string&, const char*)" << endl;
  cout << " Data before + : " << str.c_str() << " (size : " << str.size() << ")" << endl;;
  String result = str + " World";
  cout << " Result after + : " << result.c_str() << " (size : " << result.size() << ")" << endl;
}

void testOperatorPlusB(){
  String str("Hello");
  cout << "Test of operator+(const string&, const char)" << endl;
  cout << " Data before + : " << str.c_str() << " (size : " << str.size() << ")" << endl;;
  String result = str + 'o';
  cout << " Result after + : " << result.c_str() << " (size : " << result.size() << ")" << endl;
}

void testOperatorPlusC(){
  String str1("Pourquoi");
  String str2(" il pleut?");
  cout << "Test of operator+(const string&, const string&)" << endl;
  cout << " Data1 before + : " << str1.c_str() << "; Data2 before + " << str2.c_str() << endl;
  String result = str1 + str2;
  cout << " Result after + : " << result.c_str() << " (size : " << result.size() << ")" << endl;
}
