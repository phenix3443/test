# -*- coding:utf-8-*-
import multiprocessing as mp
import os
import time


def f():
    time.sleep(3)
    print("f wake up")


if __name__ == "__main__":
    p = mp.Process(target=f, args=())
    p.start()
    p.join()
    print(p.is_alive())
    print(p.exitcode)
    print(p.pid)
    print("main end")
    # with mp.Pool(processes=mp.cpu_count()) as pool:
    #     res = [pool.apply_async(f, (i, )) for i in range(4)]
    #     print([r.get(timeout=1) for r in res])
