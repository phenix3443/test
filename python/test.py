# -*- coding:utf-8-*-
import multiprocessing as mp
import os
import time
import geoip2.database



if __name__ == "__main__":
    reader = geoip2.database.Reader("/home/lsl/github/test/lua/mmdb/GeoLite2-City.mmdb")
    # ip = "114.119.117.18"
    # ip = "173.194.72.139"
    with open("/home/lsl/ip.txt") as f:
        for line in f:
            ip = line.strip()
            data = reader.city(ip)
            if data.country.name == "United States":
                print(ip)
