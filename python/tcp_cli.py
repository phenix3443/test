# -*- coding:utf-8 -*-

import socket


def run():
    s = socket.socket()

    srv_host = ""
    srv_port = 12345

    s.connect((srv_host, srv_port))

    buf_size = 1024
    while True:
        data = raw_input(">")
        if not data:
            break

        s.send(data)
        recv = s.recv(buf_size)
        if not recv:
            break
        print(recv)

    s.close()


if __name__ == "__main__":
    run()
