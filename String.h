#ifndef STRING_H
#define STRING_H

class String{

  public:
    char* data;    // pointer to the character array
    int capacity;// capacity of the allocated memory

    // Constructor
    String();
    String(const String& str);
    String(const char* str);
    ~String();

    //Accessors
    int getCapacity();
    int size();
    int max_size() const;
    const char* c_str() const;
    int length();

    // Member functions
    void clear();
    bool isEmpty();
    void reserve(int n);
    void resize(int newSize, char fillChar);

    //Operators
    String operator+ (const char* rhs);
    String& operator+(char c);
    String operator+(const String& str);
    String& operator=(const char* c);
    String& operator=(char c);
    String& operator=(const String& other);


  protected:
    int size_;
    int maxSize = 100;

};


/*
Student B:
    constructor from a c-string
    length()
    operator=(const string&)
    operator+(const string&, char)
*/

#endif
