#include <iostream>
#include <ctime>
#include <hiredis/hiredis.h>

int main(int argc, char **argv)
{
		timeval timeout;
		timeout.tv_sec = 10;
		timeout.tv_usec = 0;
		redisContext* c = redisConnectWithTimeout("172.16.1.59", 6389, timeout);
		if (c==NULL || c->err) {
				if (c) {
						std::cout << "Error:" << c->errstr << std::endl;
				} else {
						std::cout << "can not allocate redis context" << std::endl;
				}
				return 1;
		}
		redisReply* reply = NULL;
		reply = reinterpret_cast<redisReply*>(redisCommand(c, "auth %s","lixian_black"));
		if (!reply) {
				std::cout<<"redis auth err" << c->errstr << std::endl;
				return 1;
		} else {
				freeReplyObject(reply);
		}

		reply = reinterpret_cast<redisReply*>(redisCommand(c, "ping"));
		if (!reply) {
				std::cout<<"redis ping err" << c->errstr << std::endl;
				return 1;
		} else {
				std::cout << reply->str << std::endl;
				freeReplyObject(reply);
		}

		return 0;
}
