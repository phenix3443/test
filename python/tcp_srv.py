# -*- coding:utf-8 -*-

import socket

def run():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    host = ""
    port = 12345
    addr = (host, port)
    s.bind(addr)

    s.listen(5)

    buf_size =1024
    while True:
        print('waitting for connect....')
        c_s, c_addr = s.accept()
        print('connect from ', c_addr)
        while True:
            data = c_s.recv(buf_size)
            if not data:
                break
            c_s.send('from client: ' + data)


        c_s.close()
    s.close()


if __name__ == '__main__':
    run()
