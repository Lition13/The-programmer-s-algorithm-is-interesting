local _floor = math.floor
local _tonumber = tonumber
local _tostring = tostring
local _insert = table.insert
local _concat = table.concat
local _reverse = string.reverse

local convert_16 = {
	[10] = "A",
	[11] = "B",
	[12] = "C",
	[13] = "D",
	[14] = "E",
	[15] = "F",
}

-- ToBinary1 only 10 to 2,8
function ToBinary1(num, baseNum)
	local remainder,binary,i = 0,0,1

	while (num ~= 0) do
		remainder = num % baseNum
		num = math.floor(num / baseNum)
		binary = binary + (remainder * i)
		i = i * 10
	end

	return _tostring(binary)
end

-- ToBinary2 only 10 to 2,8,16
function ToBinary2(num, baseNum)
	local tmp = 0
	local retTab = {}
	while num > 0 do
		tmp = num % baseNum
		num = _floor(num / baseNum)
		if tmp >= 10 then tmp = convert_16[tmp] end
		_insert(retTab, tmp)
	end

	return _reverse(_concat(retTab))
end

local i = _tonumber(arg[1])
local numStr_2 = ""
local numStr_8 = ""
local numStr_10 = ""
local numStr_16 = ""
while true do
	i  = i + 1
	numStr_2 = ToBinary2(i, 2)
	numStr_8 = ToBinary2(i, 8)
	numStr_10 = _tostring(i)
	--numStr_16 = ToBinary2(i, 16)
	if numStr_2 == _reverse(numStr_2)
		and numStr_8 == _reverse(numStr_8)
		--and numStr_16 == _reverse(numStr_16)
		and numStr_10 == _reverse(numStr_10) then
		break
	end
end

print(i, numStr_2, numStr_8, numStr_10, numStr_16)
