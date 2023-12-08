#include "String.h"
#include <iostream>
#include <cstdlib>

void testDefaultConstructor();
void testCstyleConstructor();
void testCopyConstructor();
void testOperator_plus();
void testCapacity();
void testEmpty();
void testReserve();
void testOperator_eq();
void testOperator_plus2();
void testMaxString();
void testResize();
void testOperatorEqual();
void testc_str();
void testOpPlusB();
void testLength();


using std::cout;
using std::endl;

int main() {
  testDefaultConstructor();
  testCstyleConstructor();
    testCopyConstructor();
    testOperator_plus();
    testCapacity();
    testEmpty();
    testReserve();
    testMaxString();
    testResize();
    testOperatorEqual();
    testc_str();
    testOpPlusB();
    testLength();
    testOperator_eq();
    testOperator_plus2();
    std::exit(EXIT_SUCCESS);
}

//Constructors

void testDefaultConstructor() {
  String str;
  cout << "Default constructor" << endl;
  cout << "  Size : " << str.size() << "; and empty data : " << str.data << endl;
}

void testCstyleConstructor() {
  String str("Test du C-style constructor");
  cout << str.data << endl;
  cout << "  Size : " << str.size() << " Capacity : " << str.getCapacity() << endl;
}

void testCopyConstructor() {
  String str("Test du copy constructor");
  String str2(str);
  cout << str.data << endl;
  cout << "  Size : " << str2.size() << " Capacity : " << str2.getCapacity() << endl;
}


// Accessors

void testCapacity(){
  String str;
  cout << "Capacity is " << str.getCapacity() << endl;
}

//Member functions

void testEmpty(){
  String str;
  if (str.isEmpty()){
    cout << "The string is empty" << endl;
  } else {
    cout << "The string is not empty" << endl;

  }
}

void testReserve(){
  String str;
  str.reserve(10);
  cout << "Size is now " << str.size() << " and capacity is " << str.capacity << endl;
}

void testResize() {
  String str("TestResize");
  cout << str.data << endl;

  int newSize = 20;
  char fillChar = 'Y';
  str.resize(newSize, fillChar);
  cout << str.data << endl;

  newSize = -2;
  fillChar = 'Y';
  str.resize(newSize, fillChar);
  cout << str.data << endl;

  newSize = 10;
  fillChar = 'Y';
  str.resize(newSize, fillChar);
  cout << str.data << endl;

  newSize = 120;
  fillChar = 'o'; //if not a character but a 'string' given, take the last character of the 'string'
  str.resize(newSize, fillChar);
  cout << str.data << endl;
}

void testMaxString(){
  String str("testMaxString");
  cout << str.data << endl;
  cout << str.capacity << endl;
  cout << str.max_size() << endl;
}

void testc_str(){
  String str("testc_str");
  cout << str.c_str() << endl;
}


void testLength(){
  String str("testLength");
  cout << str.data << endl;
  cout << str.length() << endl;

}

// Operators
void testOperator_plus(){
  String str("Bonjour");
  cout << str.data << endl;
  String str2 = str+"Clement";
  cout << str2.size() << endl;
  cout << str2.data << endl;
}

void testOperatorEqual(){
  String str("testOpEqual");
  cout << str.data << endl;
  String other("wasRaplaced");
  str = other;
  cout << str.data << endl;
}

void testOpPlusB(){
  String str("testOpPlusB");
  cout << str.data << endl;
  String str2 = str+'t';
  cout << str2.data << endl;
}

void testOperator_eq(){
  String str;
  const char* p = "Bonjour";
  str = p;
  cout  << str.data << endl;
}

void testOperator_plus2(){
  String str1("Pourquoi");
  String str2(" il pleut");
  String result = str1 + str2;
  cout  << result.data << endl;
}
