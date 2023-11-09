#include "MyString.h"
#include <cstring>

MyString::MyString(char* input) {
    data = new char[strlen(input) + 1];
    strcpy(data, input);
}

MyString::~MyString() {
    delete[] data;
}

int MyString::length() const {
    return strlen(data);
}

MyString MyString::slice(int start, int end, int step) const {
    int len = length();
    end = (end > len) ? len : end;

    if (start < 0) {
        start = len + start;
    }

    char* sliced_data = new char[(end - start + 1) / step + 1];
    int j = 0;

    for (int i = start; i < end; i += step) {
        sliced_data[j++] = data[i];
    }

    sliced_data[j] = '\0';

    MyString result(sliced_data);

    // Free the memory allocated for sliced_data
    delete[] sliced_data;

    return data;
}

bool MyString::is_palindrome() {
    int len = strlen(data);
    for (int i = 0; i < len / 2; i++) {
        if (data[i] != data[len - i - 1]) {
            return false;
        }
    }
    return true;
}
