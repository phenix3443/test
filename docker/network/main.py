import redis


def main():
    r = redis.StrictRedis(host="db.app", db=0)
    r.set("foo", "bar")
    print(r.get("foo"))


if __name__ == "__main__":
    main()
