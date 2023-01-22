from socket import *
 
s_ip = 'localhost'
s_port = 9999
 
c_sock = socket(AF_INET, SOCK_STREAM)
c_sock.connect( (s_ip, s_port) )
 
while True:
    inputData = input('Enter string : ')
    c_sock.send(inputData.encode('utf-8'))
    print(c_sock.recv(1024).decode('utf-8'))
   
    if inputData == 'q':
        print('송신종료')
        break
 
c_sock.close()
