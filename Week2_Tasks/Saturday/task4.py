def GPIO_init():
    port = ['x'] * 8
    for i in range (8):
        direction = input(f'Please enter bit {i} mode [in,out]: ')
        if (direction == 'in'):
            port[-1-i] = '0'
        elif (direction == 'out'):
            port[-1-i] = '1'
    port = ''.join(port)
    port = int(port,2)
    return (format(port,'#010b'))
answer = GPIO_init()
print(answer)