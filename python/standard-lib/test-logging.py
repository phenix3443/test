""" 测试logging.config模块
"""
# -*- coding:utf-8;-*-

import logging
import logging.config

logger = logging.getLogger(__name__)


if __name__ == '__main__':
    logging.config.dictConfig({
        "version": 1,
        "disable_existing_loggers": True,
        "formatters": {
            "verbose": {
                "format": "{asctime} {levelname} {name}:{lineno} {message}",
                "datefmt": "%Y-%m-%d %H:%M:%S",
                "style": "{"
            },
            "simple": {
                "format": "{levelname} {message}"
            },
        },
        "handlers": {
            "null": {
                "level": "DEBUG",
                "class": "logging.NullHandler",
            },
            "console": {
                "level": "DEBUG",
                "class": "logging.StreamHandler",
                "formatter": "verbose"
            },
            "file": {
                "level": "DEBUG",
                "class": "logging.handlers.RotatingFileHandler",
                "maxBytes": 1024 * 1024 * 10,
                "backupCount": 50,
                "delay": True,
                "filename": "logs/mysite.log",
                "formatter": "verbose"
            }
        },
        "loggers": {
            "test": {
                "handlers": ["file"],
                "level": "INFO",
            },
        }
    })

    logger.debug("hello,debug")
    logger.info("hello,info")
