f = open("textfile.txt", "r")
words = f.read()
print("Number of words:", len(words.split()))