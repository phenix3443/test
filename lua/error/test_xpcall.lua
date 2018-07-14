local function foo(a)
    return a[1]
end

local function handler(err)
    print(err)
    print(debug.traceback())
end

local function main()
    -- foo(false)
    local status,err = xpcall(foo, handler, false)
    print(status)
    print(err)
end
main()
