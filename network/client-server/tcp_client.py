# 1. socket (연결)
# 2. bind (open)
# 3. listen(Client로 부터 요청이 있을 때 까지 계속 listen)
# 4. accept (Client로 부터 온 요청을 처리)
# 5. close (종료)

from socket import *

s_ip = 'localhost'
s_port = 9999

c_sock = socket(AF_INET, SOCK_STREAM)
c_sock.connect( (s_ip, s_port) )

data1 = 'Thank you for connecting'
print(data1, c_sock.recv(1024).decode('utf-8'))
data2 = '안녕하세요 이것은 소켓 프로그래밍입니다.'
c_sock.send(data2.encode('utf-8'))

c_sock.close()
