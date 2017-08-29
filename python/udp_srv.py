# -*- coding:utf-8 -*-
import socket

def run():
    host = ''
    port = 12345
    addr = (host, port)

    buf_size = 1024

    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    s.bind(addr)

    while True:
        data, c_addr = s.recvfrom(buf_size)
        print('recv from {}: {}'.format(c_addr, data))

    s.close()


if __name__ == '__main__':
    run()
