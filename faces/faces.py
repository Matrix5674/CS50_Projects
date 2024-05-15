def convert(a):
    a = a.replace(':)', '🙂')
    a = a.replace(':(', '🙁')
    return a

text = input("Input: ")
print(convert(text))

