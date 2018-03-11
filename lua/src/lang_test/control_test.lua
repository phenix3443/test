-- -*- coding:utf-8 -*-
-- author:liushangliang
-- desc: 控制语句测试

local lu = require("luaunit")

_G.TestIO = {}

function _G.TestControl.IF()
    local var = false
    if var == 1  then
        print(1)
    elseif var == 2 then
        print(2)
    else
        print("else")
    end


end

os.exit(lu.LuaUnit.run())
