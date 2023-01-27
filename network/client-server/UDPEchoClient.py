from socket import *

s_ip = 'localhost'
s_port = 9999
c_sock = socket(AF_INET, SOCK_DGRAM)
inputData = input('Enter string : ')
c_sock.sendto(inputData.encode('utf-8'), (s_ip, s_port) )

while inputData != 'q':
    data, addr = c_sock.recvfrom(1024)
    print('Echoed data : ', data.decode('utf-8'))
    inputData = input('Enter string : ')
    c_sock.sendto(inputData.encode('utf-8'), (s_ip, s_port))

c_sock.close()