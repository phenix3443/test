# -*- coding:utf-8; -*-

import redis
import time


def handle(message):
    print(message["data"])


if __name__ == "__main__":
    red = redis.Redis(host="127.0.0.1", port=6379, db=0)
    p = red.pubsub()
    p.subscribe(**{"channel": handle})
    thread = p.run_in_thread(sleep_time=0.001)
    time.sleep(2)
    thread.stop()
