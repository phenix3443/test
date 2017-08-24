local string = string

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

mystring.from_hex =	function (hexstr)
	return (hexstr:gsub('..', function (cc) return string.char(tonumber(cc, 16)) end))
end

mystring.to_hex = function (binstr)
    return (binstr:gsub('.', function (c) return string.format('%02X', string.byte(c)) end))
end


export = {
	["string"] = mystring
}
