#ifndef MYSTRING_H
#define MYSTRING_H

class MyString {
private:
    char* data;

public:
    MyString(char* input);
    ~MyString();
    int length() const;
    MyString slice(int start, int end, int step) const;
    bool is_palindrome();
};

#endif
