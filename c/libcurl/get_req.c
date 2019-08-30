/* -*-coding:utf-8; -*- */
/* 使用libcurl发送get请求 */
/* 由于没有设置write回调，请求会打印在标准输出上 */

#include <curl/curl.h>
#include <stdio.h>

int main (int argc, char *argv[]) {
    /* printf("curl version:%s\n",curl_version()); */
    CURL *curl = curl_easy_init ();
    if (curl) {
        /* curl_easy_setopt (curl, CURLOPT_VERBOSE, 1); */
        curl_easy_setopt (curl, CURLOPT_URL, "http://httpbin.org/get");
        /* curl_easy_setopt(curl, CURLOPT_HEADER, 1); */

        CURLcode res = curl_easy_perform (curl);
        if (CURLE_OK != res) {
            printf ("connect error\n");
            return -1;
        }
    }
    curl_easy_cleanup(curl);
    return 0;
}
