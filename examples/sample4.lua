-- �����C++�д���Lua������table������C++��Lua��������


-- C++ ע���haha��
-- haha = { value =1, inside = { value = 2 } }
print(haha)

print(haha.value)
print(haha.inside)
print(haha.inside.value)

-- C++���ȡ haha.test ע��
haha.test = "input from lua"

-- C++ ����print_table ���� temp = { name = "local table !!" }
function print_table(arg)
	print("arg = ", arg)
	print("arg.name = ", arg.name)
end

-- C++ ����return_table  
function return_table(arg)
	local ret = {}
	ret.name = arg
	return ret
end