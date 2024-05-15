expression = input("Expression: ")

parts = expression.split()

num1 = float(parts[0])
num2 = float(parts[2])

operation = parts[1]

if operation == '/' and num2 == 0:
    print("Invalid expression")
    exit()

operations = {
    '*': lambda x, y: x * y,
    '+': lambda x, y: x + y,
    '-': lambda x, y: x-y,
    '/': lambda x, y: x/y
}

if operation in operations:
    result = operations[operation](num1, num2)
    print(result)
else:
    print("Invalid operation")
    exit()
