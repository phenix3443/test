import logging

logger = logging.getLogger(__name__)

# logging.getLogger('foo').addHandler(logging.NullHandler())

# h = logging.StreamHandler()
# h.setLevel(logging.DEBUG)

# logger.setLevel(logging.DEBUG)
# logger.addHandler(h)

# logger.debug("debug log")
# logger.info("info log")
# logger.warn("warning")


def test():
    logger.debug("debug log")
    logger.info("info log")
    logger.warn("warning")


if __name__ == "__main__":
    # pass
    h = logging.StreamHandler()
    h.setLevel(logging.DEBUG)

    logger.setLevel(logging.DEBUG)
    logger.addHandler(h)

    test()
