local _floor = math.floor
local _tonumber = tonumber
local _tostring = tostring
local _insert = table.insert
local _concat = table.concat
local _reverse = string.reverse

function ToBinary(num, baseNum)
	local tmp = 0
	local retTab = {}
	while num > 0 do
		tmp = num % baseNum
		num = _floor(num / baseNum)
		_insert(retTab, tmp)
	end

	return _reverse(_concat(retTab))
end

local i = _tonumber(arg[1])
local numStr_2 = ""
local numStr_8 = ""
local numStr_10 = ""
while true do
	i  = i + 1
	numStr_2 = ToBinary(i, 2)
	numStr_8 = ToBinary(i, 8)
	numStr_10 = _tostring(i)
	if numStr_2 == _reverse(numStr_2)
		and numStr_8 == _reverse(numStr_8)
		and numStr_10 == _reverse(numStr_10) then
		break
	end
end

print(i, numStr_2, numStr_8, numStr_10)
