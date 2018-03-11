-- -*- coding:utf-8 -*-
-- author:liushangliang
-- desc: IO接口测试

local lu = require("luaunit")

_G.TestIO = {}

function _G.TestIO.Hello()
    print("Hello,world")
end

os.exit(lu.LuaUnit.run())
