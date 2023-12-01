class String{

  public:
    char* data;    // pointer to the character array
    int size;   // current size of the string
    int capacity;// capacity of the allocated memory
    String();
    String(const String& str);
    String(const char* str);
    ~String();

    //Member functions
    bool isEmpty();

    //Accessors
/*
    getData();
    getSize();

*/
    int getCapacity();

};
