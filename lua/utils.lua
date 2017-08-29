-- -*- coding:utf-8 -*-

local mystring = {}

mystring.split = function(str, pattern)
	pattern = pattern or "[^%s]+"
	if pattern:len() == 0 then
		pattern = "[^%s]+"
	end

	local parts = {__index = table.insert}
	setmetatable(parts, parts)
	str:gsub(pattern, parts)
	setmetatable(parts, nil)
	parts.__index = nil
	return parts
end

mystring.startswith = function(str, start)
	return string.sub(str,1,string.len(start)) == start
end

mystring.hex2bin =	function (hexstr)
	return (hexstr:gsub('..', function (cc) return string.char(tonumber(cc, 16)) end))
end

mystring.bin2hex = function (binstr)
    return (binstr:gsub('.', function (c) return string.format('%02X', string.byte(c)) end))
end


local mytable  = {}

mytable.shadow_copy = function (t)
    if type(t) ~= "table" then return t end
    local meta = getmetatable(t)
    local target = {}
    for k, v in pairs(t) do target[k] = v end
    setmetatable(target, meta)
    return target
end

mytable.deep_copy = function (orig)
	-- http://lua-users.org/wiki/CopyTable
    local orig_type = type(orig)
    local copy
    if orig_type == 'table' then
        copy = {}
        for orig_key, orig_value in next, orig, nil do
            copy[mytable.deep_copy(orig_key)] = mytable.deep_copy(orig_value)
        end
        setmetatable(copy, mytable.deep_copy(getmetatable(orig)))
    else -- number, string, boolean, etc
        copy = orig
    end

    return copy
end



export = {
	["string"] = mystring,
	["table"]  = mytable
}
