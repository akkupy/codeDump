def reverse_words(s):
    words = s.split()  # Split the sentence into a list of words
    reversed_words = [word[::-1] for word in words]  # Reverse each word
    result = ' '.join(reversed_words)  # Join the reversed words back into a sentence
    return result
