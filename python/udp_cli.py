# -*- coding:utf-8 -*-
import socket

def run():
    host = ''
    port = 12345
    addr = (host, port)

    buf_size = 1024

    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    while True:
        data = raw_input('>')
        if not data:
            break
        s.sendto(data, addr)

    s.close()


if __name__ == '__main__':
    run()
