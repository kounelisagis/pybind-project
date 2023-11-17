import pbstring

my_str = pbstring.MyString('Hello, World!')

print(f'Length of the string "{my_str}" (using len()) is {len(my_str)}')
print(
    f'Length of the string "{my_str}" is (using .length()) {my_str.length()}')
print(
    f'The string "{my_str}" is {"not " if not my_str.is_palindrome() else ""}a palindrome')

new_str = 'aabaa'
print(f'The string {new_str} is {"not " if not pbstring.MyString(new_str).is_palindrome() else ""}a palindrome')
print(
    f'The string aabbaa is {"not " if not pbstring.MyString("aabbaa").is_palindrome() else ""}a palindrome')

print(f'Every second character of "{my_str}" is {my_str[::2]}')

sub_str = my_str[1:5]
print(f'A substring of "{my_str}" from index 1 to 5 is {sub_str}')

print(f'I can also do this str[:] resulting in {my_str[:]}')
print(f'Or even str[::] resulting in {my_str[::]}')
