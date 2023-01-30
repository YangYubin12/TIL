from socket import *

s_ip = 'localhost'
s_port = 9999
s_sock = socket(AF_INET, SOCK_DGRAM)
s_sock.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
s_sock.bind( (s_ip, s_port) )
data, c_addr = s_sock.recvfrom(1024)

while data.decode('utf-8') != 'q':
    print('Received from', c_addr)
    print('Obtained', data.decode('utf-8'))
    print()

s_sock.sendto(data, c_addr)
data, c_addr = s_sock.recvfrom(1024)
s_sock.close()
