vowel = {'a','A','e','E','i','I','o','O','u','U'}
letter = input("Enter letter: ")
if(letter in vowel):
    print(f"'{letter}' is vowel")
else:
    print(f"'{letter}' is constant")