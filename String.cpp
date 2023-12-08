#include "String.h"
#include <iostream>

// Constructors

String::String(){
  // Initialize with a default string, e.g., "Hello World"
  const char* defaultString = "Hello World";
  size_ = 0;
  capacity = 100; // Initial capacity, can be adjusted based on requirements
  data = new char[capacity];

  // Copy the default string manually
  while (defaultString[size_] != '\0' && size_ < capacity - 1) {
    data[size_] = defaultString[size_];
    size_++;
  }

  // Add null terminator
  data[size_] = '\0';
}

// Copy constructor
String::String(const String& other) {
  size_ = other.size_;
  capacity = other.capacity;
  data = new char[capacity];

  // Copy the data from the other string
  for (int i = 0; i <= size_; ++i) {
    data[i] = other.data[i];
  }
}

// Constructor with a C-style string parameter
String::String(const char* str) {
    size_ = 0;
    capacity = 100; // Initial capacity, can be adjusted based on requirements

    data = new char[capacity];

    while (str[size_] != '\0' && size_ < capacity - 1) {
      data[size_] = str[size_];
      size_++;
    }

    // Add null terminator
    data[size_] = '\0';
}

String::~String(){
  delete[] data;
}


// Accessors

int String::getCapacity(){
  return capacity;
}

int String::size(){
  return size_;
}

// Member functions

void String::clear(){
  delete[] data;
  size_ = 0;
  data = new char[capacity];
  data[0]='\0';
}

String& String::operator=(char c) {
  clear(); // Clear the existing contents
  size_ = 1;
  data[0] = c;
  data[1] = '\0'; // Null-terminate the string
  return *this;
}

String String::operator+ (const char* rhs){
  String result(data);
  int newsize = size_;
  int rhs_size = 0;


  while (rhs[rhs_size] != '\0' && newsize < capacity - 1) {
    result.data[newsize] = rhs[rhs_size];
    newsize++;
    rhs_size++;
  }

  result.data[newsize]='\0';
  result.size_=newsize;
  return result;

}

String& String::operator=(const char* c){
  if (this != reinterpret_cast<const String*>(c)) {
    clear();

    int newsize = 0;
    while (c[newsize] != '\0') {
      ++newsize;
    }

    data = new char[newsize + 1]; //for null terminator

    for(int i=0; i <= newsize; ++i){
      data[i] = c[i];
    }
    data[newsize] = '\0';

  }
  return *this;
}

String String::operator+ (const String& str){
  String str2(str);

  String result(data);
  int newsize = size_;
  int str2_size = 0;

  while(str.data[str2_size] != '\0' && newsize < capacity - 1){
    result.data[newsize] = str2.data[str2_size];
    newsize++;
    str2_size++;
  }

  result.data[newsize]='\0';
  result.size_=newsize;
  return result;
}

bool String::isEmpty(){
  return size_ == 0;
}

void String::reserve(int n){
  if (size_ + n > maxSize){
    std::cout << "ERROR : size is too big" << std::endl;
  }else {
    size_ += n;
    if (capacity < size_){
      capacity = size_;
    }
  }
}
