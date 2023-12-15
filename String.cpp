#include "String.h"
#include <iostream>

// Constructors

String::String(){
  size_ = 0;
  capacity_ = 10; // Initial capacity, can be adjusted based on requirements
  data = new char[capacity_];
  data[size_] = '\0'; // Add null terminator
}

// Copy constructor
String::String(const String& other) {
  size_ = other.size_;
  capacity_ = other.capacity_;
  data = new char[capacity_];

  // Copy the data from the other string
  for (int i = 0; i <= size_; ++i) {
    data[i] = other.data[i];
  }
}

// Constructor with a C-style string parameter
String::String(const char* str) {
    size_ = 0;
    capacity_ = 10; // Initial capacity, can be adjusted based on requirements

    data = new char[capacity_];

    while (str[size_] != '\0' && size_ < capacity_ - 1) {
      if(size_== capacity_ - 2){
        capacity_ += 10;
      }
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

int String::capacity(){
  return capacity_;
}

int String::size(){
  return size_;
}

int String::length(){
  //all characters are equal to one byte
  //size  equal to length
  return size_;
}

int String::max_size() const {
  //returns the maximum number of characters
  return maxSize_; // This is the maximum value for a 32-bit signed int
}

const char* String::c_str() const {
    return data; // The data array is already null-terminated
}

// Member functions

void String::clear(){
  delete[] data;
  size_ = 0;
  data = new char[capacity_];
  data[0]='\0';
}

bool String::empty(){
  return size_ == 0;
}

void String::reserve(int n){
  if (n > maxSize_){
    std::cout << "ERROR : n is bigger than maxSize_" << std::endl;
  }else {
    if (capacity_ < n){
      capacity_ =  n;
    }
  }
}

void String::resize(int newSize, char fillChar) {
  if (newSize < 0) {
    //size can't be under 0, break
    std::cout << "ERROR: A negative size is not allowed" << std::endl;
    return;
  }
  if (newSize > maxSize_) {
    //size can't be bigger than maxSize_, break
    std::cout << "ERROR: n greater than maxSize_" << std::endl;
    return;
  }
  if (newSize <= size_) {
    //we need to truncate the string, if newsize to small
    size_ = newSize;
    data[size_] = '\0';
  } else if (newSize > capacity_) {
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

    capacity_ = newCapacity;
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

//Operators

String& String::operator=(char c) {
  clear(); // Clear the existing contents
  size_ = 1;
  data[0] = c;
  data[1] = '\0'; // Null-terminate the string
  return *this;
}



String& String::operator=(const char* c){
  if (this != reinterpret_cast<const String*>(c)) {
    clear();

    int newsize = 0;
    while (c[newsize] != '\0') {
      ++newsize;
    }
    size_ = newsize+1;

    for(int i=0; i <= newsize; ++i){
      data[i] = c[i];
    }
    data[newsize] = '\0';

  }
  return *this;
}

String& String::operator=(const String& other) {
  if (this != &other) {
    //just to avoid any unecessary action
    clear();

    //adjust all string members
    size_ = other.size_;
    capacity_ = other.capacity_;

    //copy the data
    for (int i = 0; i <= size_; ++i) {
        data[i] = other.data[i];
    }
  }
  return *this;
}

String String::operator+ (const char* rhs){
  String result(data);
  int newsize = size_;
  int rhs_size = 0;

  while (rhs[rhs_size] != '\0' && newsize < capacity_ - 1) {
    //increase capacity if needed
    if(newsize == capacity_ - 2){
      capacity_ += 10;
    }
    result.data[newsize] = rhs[rhs_size];
    newsize++;
    rhs_size++;
  }

  result.data[newsize]='\0';
  result.size_=newsize;
  return result;
}

String String::operator+(const String& str){
  String str2(str);

  String result(data);
  int newsize = size_;
  int str2_size = 0;

  while(str.data[str2_size] != '\0' && newsize < capacity_ - 1){
    //increase capacity if needed
    if(newsize == capacity_ - 2){
      capacity_ += 10;
    }
    result.data[newsize] = str2.data[str2_size];
    newsize++;
    str2_size++;
  }

  result.data[newsize]='\0';
  result.size_=newsize;
  return result;
}

String String::operator+(char c){
  String result(data);

  //check if capacity big enough
  if (size_ + 1 >= capacity_) {
      //if not add some
      result.capacity_++;
  }

  //add the character to the end

  result.data[size_] = c;
  result.size_++;
  result.data[result.size_] = '\0';  // Null-terminate the string
  return result;
}
