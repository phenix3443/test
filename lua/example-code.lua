-- -*- coding:utf-8 -*-

local cjson = require("cjson.safe")

_G.g_var = "this is var in global scope"

local function main()
    local var = string.format("this is var in %s scope", "local")
    print("local var:", var)

    local  t = {
        "first element",
        "sencond element",
        dict_key = "dict value"
    }

    -- 使用pairs遍历
    for i, v in pairs(t) do
        print("idx:", i, " value:", v)
    end

    print("\n")

    -- 使用ipairs遍历
    for i, v in ipairs(t) do
        print("idx:", i, " value:", v)
    end

    print("\n")

    print(cjson.encode(t))

end

main()
