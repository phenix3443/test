-- -*- coding:utf-8 -*-
-- author:liushangliang@xunlei.com
-- require:
-- yum install lua-devel
-- luarocks install lua-cjson
-- luarocks install luasocket

local cjson = require("cjson.safe")
local http = require("socket.http")

local export = {}

function export.static(payload)
    local body,code,head,status_line = http.request("http://127.0.0.1:30976/v1/push",cjson.encode(payload))
    if not body then
        print("falcon agent connect failed")
        return
    end
    print(body)
    print(code)
end

return export
