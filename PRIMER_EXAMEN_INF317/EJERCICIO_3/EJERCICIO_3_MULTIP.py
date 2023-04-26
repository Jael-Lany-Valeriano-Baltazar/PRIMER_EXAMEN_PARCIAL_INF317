from multiprocessing import Pool

def is_palindrome(word):
    return word == word[::-1]

if __name__ == '__main__':
    word = "reconocer"
    with Pool() as p:
        result = p.apply(is_palindrome, args=(word,))
    if result:
        print(f"La palabra '{word}' es un palíndromo.")
    else:
        print(f"La palabra '{word}' no es un palíndromo.")
