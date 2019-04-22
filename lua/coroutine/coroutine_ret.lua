local co = coroutine.create(function (val,n)
        local loop_count = 0
        repeat
            for i=1,n do
                print(val)
            end
            loop_count = loop_count + 1
            print(loop_count .. " loop_count")
        until (not coroutine.yield(loop_count))

        print("all finish")
end)

local function test()
    local ret, count = coroutine.resume(co,"hello,lua",5)
    while ret do
        if count < 3 then
            ret, count = coroutine.resume(co,true)
        else
            ret, count = coroutine.resume(co,false)
            break
        end
    end
end

test()
