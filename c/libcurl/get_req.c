/* -*-coding:utf-8; -*- */
/* 使用libcurl发送get请求 */

#include <curl/curl.h>
#include <stdio.h>

int main (int argc, char *argv[]) {
    CURL *curl = curl_easy_init ();
    if (curl) {
        /* curl_easy_setopt (curl, CURLOPT_VERBOSE, 1); */
        curl_easy_setopt (curl, CURLOPT_URL, "http://baidu.com");
        CURLcode res = curl_easy_perform (curl);
        if (CURLE_OK != res) {
            printf ("connect error\n");
            return -1;
        }

        char *ct = NULL;
        res = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &ct);
        if (!res && ct) {
            printf("content-type:%s\n", ct);
        }
    }
    curl_easy_cleanup(curl);
    return 0;
}
