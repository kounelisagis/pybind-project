#ifndef MYSTRING_H
#define MYSTRING_H

class MyString {
private:
    char* data;

public:
    MyString(const char* input);
    ~MyString();
    char* get_data() const;
    int length() const;
    MyString* slice(int start, int end, int step) const;
    bool is_palindrome() const;
};

#endif
