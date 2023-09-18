import socket

host = '127.0.0.1'
port = 1234

ClienSocket = socket.socket()
print('Waiting for connection')
try:
    ClienSocket.connect((host,port))
except socket.error as e:
    print(str(e))

Response = ClienSocket.recv(2048)
while True:
    message = input('Your message: ')
    ClienSocket.send(str.encode(message))
    reply = ClienSocket.recv(2048)
    decoded_reply = reply.decode('utf-8')
    print(decoded_reply)
    if decoded_reply == 'BYE':
        break
ClienSocket.close()
