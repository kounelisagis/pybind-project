This project is based on this template: https://github.com/TileDB-Inc/py-cppstring-starter

# Run code

```
git clone <uri>
cd <repo>
mkdir bld && cd bld
cmake ..
cmake --build .
```

Then you can try running

```
python
```

and run some of the supported commands.

Or run the code of the example file by running

```
python ../examples/example.py
```

The output should be something like

```
Length of the string "Hello, World!" (using len()) is 13
Length of the string "Hello, World!" is (using .length()) 13
The string "Hello, World!" is not a palindrome
The string aabaa is a palindrome
The string aabbaa is a palindrome
Every second character of "Hello, World!" is Hlo ol!
A substring of "Hello, World!" from index 1 to 5 is ello
I can also do this str[:] resulting in Hello, World!
Or even str[::] resulting in Hello, World!
```
