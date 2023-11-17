#include "MyString.h"
#include <cstring>

MyString::MyString(const char* input) {
    data = new char[strlen(input) + 1];
    strcpy(data, input);
}

MyString::~MyString() {
    delete[] data;
}

char *MyString::get_data() const {
    return data;
}

int MyString::length() const {
    return strlen(data);
}

MyString* MyString::slice(int start, int end, int step) const {
    int len = length();
    start = (start < 0) ? len + start : start;
    end = (end > len) ? len : end;

    char* sliced_data = new char[len+1];
    int j = 0;

    for (int i = start; i < end; i += step) {
        sliced_data[j++] = data[i];
    }

    sliced_data[j] = '\0';

    MyString *sliced_string = new MyString(sliced_data);
    delete[] sliced_data;
    return sliced_string;
}

bool MyString::is_palindrome() const {
    int len = strlen(data);
    for (int i = 0; i < len / 2; i++) {
        if (data[i] != data[len - i - 1]) {
            return false;
        }
    }
    return true;
}
