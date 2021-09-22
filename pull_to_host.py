import socket
HOST="192.168.43.86"
PORT=9877
AF_INET_DATA=(HOST,PORT)
sock=socket.socket()
sock.connect(AF_INET_DATA)
while True:
	print(sock.recv(1024).decode())
	sock.send(input('Enter to send>').encode())
sock.close()
