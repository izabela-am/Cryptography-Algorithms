import sys
from string import ascii_lowercase as lower_case_letters

file = open(sys.argv[1], 'r').read().lower() # File to be read by the program
key = int(sys.argv[2]) # Shift key
operation = sys.argv[3] # operation: encrypt or decrypt

final_message = ''

for letter in file:
  if letter in lower_case_letters:
    letter_index = lower_case_letters.find(letter)

    if operation == 'encrypt':
      letter_index = (letter_index + key) % 26
    elif operation == 'decrypt':
      letter_index = (letter_index - key) % 26

    final_message += lower_case_letters[letter_index]
  else:
    final_message += letter

print(final_message,)