local lu = require("luaunit")
local serpent = require("serpent")

local a = {1, nil, 3, x=1, ['true'] = 2, [not true]=3}

_G["TestSerpent"] = {}

function TestSerpent:test_dump()
    print(serpent.dump(a)) -- full serialization
    local b = loadstring(serpent.dump(a))
    print(serpent.line(b()))
end

function TestSerpent:test_line()
    print(serpent.line(a)) -- single line, no self-ref section
end

function TestSerpent:test_block()
    print(serpent.block(a,{indent="        "})) -- multi-line indented, no self-ref section
end

function TestSerpent:test_load()
    local ok,copy = serpent.load(serpent.dump(a))
    lu.assert_equals(copy[3], a[3])
end

os.exit(lu.LuaUnit.run())
