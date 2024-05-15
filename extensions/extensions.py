def type(file):
    if file.endswith('.gif'):
        print('image/gif')
    elif file.endswith('.jpg'):
        print('image/jpeg')
    elif file.endswith('.jpeg'):
        print('image/jpeg')
    elif file.endswith('.png'):
        print('image/png')
    elif file.endswith('.pdf'):
        print('application/pdf')
    elif file.endswith('.txt'):
        file = file.replace('.txt', '')
        print('text/' + file)
    elif file.endswith('.zip'):
        print('application/zip')
    else:
        print('application/octet-stream')

    return


input = input("File: ")
input = input.lower()
input = input.replace(' ', '')
type(input)




