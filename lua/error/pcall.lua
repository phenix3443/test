local function foo(a)
    return a[1]
end

local status,err = pcall(foo,false)
print(status)
print(err)
