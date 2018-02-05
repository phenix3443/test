-- -*- coding:utf-8 -*-
-- file: 使用nginx api版本的falcon接口
-- author:liushangliang@xunlei.com
-- require:
-- yum install lua-devel
-- luarocks install lua-cjson

local cjson = require("cjson.safe")

local export = {}

function export.static(payload)
    local resp = ngx.location.capture("/falcon",
                                      {
                                          method = ngx.HTTP_POST,
                                          body=cjson.encode(payload)

    })
    if resp.status ~= ngx.HTTP_OK then
        ngx.log(ngx.ERR,"falcon agent falid: http_status=",resp.status)
        return
    end
end

return export
