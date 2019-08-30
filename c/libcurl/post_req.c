/* -*-coding:utf-8; -*- */
/* 使用libcurl发送post请求，body是json数据 */
/* 设置post body，header中的content-type */

#include <curl/curl.h>
#include <stdio.h>
#include <string.h>

size_t write_cb (char *ptr, size_t size, size_t nmemb, void *userdata) {
    size_t body_len = size * nmemb;
    printf ("%s:%ld\n", (char *)userdata, body_len);
    char content[body_len +1];
    memcpy(content,ptr,body_len);
    content[body_len] = 0;
    printf("content:%s\n", content);
    return body_len;
}

int main (int argc, char *argv[]) {
    CURL *curl = curl_easy_init ();
    if (curl) {
        curl_easy_setopt (curl, CURLOPT_VERBOSE, 1);
        curl_easy_setopt (curl, CURLOPT_URL, "http://httpbin.org/post?a=1&b=2");

        /* get resp body */
        curl_easy_setopt (curl, CURLOPT_WRITEFUNCTION, write_cb);
        char *userdata = "resp body len:";
        curl_easy_setopt (curl, CURLOPT_WRITEDATA, userdata);

        /* post */
        curl_easy_setopt(curl,CURLOPT_POST, 1);
        /* header */
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        /* post body */
        char body[] = "{\"key\":\"value\"}";
        curl_easy_setopt (curl, CURLOPT_POSTFIELDS, body);
        /* curl_easy_setopt (curl, CURLOPT_POSTFIELDSIZE, strlen(body)); */
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

        curl_slist_free_all(headers);
    }
    curl_easy_cleanup(curl);
    return 0;
}
