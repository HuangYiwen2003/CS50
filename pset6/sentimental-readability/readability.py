from cs50 import get_string


def main():
    text = get_string("Text: ")
    letters1 = count_letters(text)
    words1 = count_words(text)
    sentences1 = count_sentences(text)

    words_per_100 = words1 / 100
    L = letters1 / words_per_100
    S = sentences1 / words_per_100
    index = round(0.0588 * L - 0.296 * S - 15.8)

    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


def count_letters(text):
    letters = 0
    for i in range(len(text)):
        if (text[i] >= 'A' and text[i] <= 'Z'):
            letters += 1
        if (text[i] >= 'a' and text[i] <= 'z'):
            letters += 1
    return letters


def count_words(text):
    words = 0
    for i in range(len(text)):
        if (text[i] == ' '):
            words += 1
    words += 1
    return words


def count_sentences(text):
    sentences = 0
    for i in range(len(text)):
        if (text[i] == '.' or text[i] == '!' or text[i] == '?'):
            sentences += 1
    return sentences


main()