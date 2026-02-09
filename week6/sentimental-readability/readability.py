text = input("Text: ")

words = 1
sentences = 0
letters = 0

for c in text:
    if c == " ":
        words += 1
    elif c in ".!?":
        sentences += 1
    elif c.lower() in "qwertyuiopasdfghjklzxcvbnm":
        letters += 1

L = (letters / words) * 100
S = (sentences / words) * 100
index = round((0.0588 * L) - (0.296 * S) - 15.8)

if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {index}")

    

