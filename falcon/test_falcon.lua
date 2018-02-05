-- -*- coding:utf-8 -*-
-- author:liushangliang@xunlei.com

package.cpath = package.cpath .. ";/usr/lib/lua/5.1/?.so;"
local payloads = {
    {
        endpoint= "test-endpoint",
        metric= "test-metric",
        timestamp= os.time(),
        step= 60,
        value= 1,
        counterType= "GAUGE",
        tags= "idc=lg,loc=beijing",
    }
}

local falcon = require("falcon")
falcon.static(payloads)
