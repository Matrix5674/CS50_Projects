greeting = input("Greeting: ")
greeting = greeting.lower()
a = True
if greeting.__contains__('hello'):
    print('$0')
    a = False
elif greeting[0] == 'h' and a == True:
    print('$20')
    a = False

if a == True:
    print('$100')

