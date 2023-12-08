#ifndef STRING_H
#define STRING_H

class String{

  public:
    // Constructor
    String();
    String(const String& str);
    String(const char* str);
    ~String();

    //Accessors
    int capacity();
    int size();
    int max_size() const;
    const char* c_str() const;
    int length();

    // Member functions
    void clear();
    bool empty();
    void reserve(int n);
    void resize(int newSize, char fillChar);

    //Operators
    String operator+ (const char* rhs);
    String operator+(char c);
    String operator+(const String& str);
    String& operator=(const char* c);
    String& operator=(char c);
    String& operator=(const String& other);


  protected:
    char* data;    // pointer to the character array
    int size_;
    int maxSize_ = 100;
    int capacity_;// capacity of the allocated memory

};

#endif
