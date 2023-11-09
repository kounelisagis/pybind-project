import pbstring

user_input = input("Enter a string: ")
my_str = pbstring.MyString(user_input.encode('utf-8'))

print(f"Length of the string: {my_str.length()}")
print(f"Is palindrome: {my_str.is_palindrome()}")
my_str[0:6:2]
