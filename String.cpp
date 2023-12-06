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

//

int String::max_size() const {
  //returns the maximum number of characters
  return 2147483647; // This is the maximum value for a 32-bit signed int
}

void String::resize(int newSize, char fillChar) {
  if (newSize < 0) {
    //size can't be under 0, break
    std::cout << "ERROR: A negative size is not allowed" << std::endl;
    return;
  }
  if (newSize < size_) {
    //we need to truncate the string, if newsize to small
    size_ = newSize;
    data[size_] = '\0';

  } else if (newSize > capacity) {
    //if more memory needs to be allocated (capacity to small)
    int newCapacity = newSize + 1;
    char* newData = new char[newCapacity];

    //existing data
    for (int i = 0; i < size_; ++i) {
      newData[i] = data[i];
    }

    //we add the specified fillChar in the size added
    for (int i = size_; i < newSize; ++i) {
      newData[i] = fillChar;
    }

    newData[newSize] = '\0';

    capacity = newCapacity;
    delete[] data;
    data = newData;
    size_ = newSize;

  }else{
    //last case : no need to change the capacity
    for (int i = size_; i < newSize; ++i) {
        data[i] = fillChar;
    }
    data[newSize] = '\0';
    size_ = newSize;
  }
}

String& String::operator=(const String& other) {
  if (this != &other) {
    //just to avoid any unecessary action
    clear();

    //adjust all string members
    size_ = other.size_;
    capacity = other.capacity;
    data = new char[capacity];

    //copy the data
    for (int i = 0; i <= size_; ++i) {
        data[i] = other.data[i];
    }
  }
  return *this;
}




// Operators
/*
void String::operator_eq(const char* p){
  this->data = p;
}
*/
