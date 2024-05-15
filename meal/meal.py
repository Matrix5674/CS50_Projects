def main():
    userInput = input('Time: ')
    time = convert(userInput)
    if time >= 7 and time <= 8:
        print('breakfast time')
    elif time >= 12 and time <= 13:
        print('lunch time')
    elif time >= 18 and time <= 19:
        print('dinner time')


def convert(time):
    hour, minutes = time.split(':')
    hour = float(hour)
    minutes = float(minutes)
    minutes /= 60
    return hour+minutes

if __name__ == "__main__":
    main()
