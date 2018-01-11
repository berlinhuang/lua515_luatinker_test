-- ��C++�ж���������lua������Lua����ʹ��
-- ��C++��ΪLua�������ȫ�ֱ�������ʵ������


print(g_test._test) -- ��ӡg_test�ĳ�Ա����_test
print(g_test:is_test())
print(g_test:ret_int())



temp = test(4) -- ����һ��test��
print(temp._test) -- ��ӡtest��_test��Ա

a = g_test:get()

temp:set(a)
print(temp._test)
print(temp:is_base())
print(temp:is_test())



-- ��� ��ü�� metatable�� ���� ��ϵ� Ŭ������ �� �Լ����� ���캸�� �Լ�
-------------------------------------------------------------------------------
function objinfo(obj)
	local meta = getmetatable(obj)
	if meta ~= nil then
		metainfo(meta)
	else
		print("no object infomation !!")
	end
end

function metainfo(meta)
	if meta ~= nil then
		local name = meta["__name"]
		if name ~= nil then
			metainfo(meta["__parent"])
			print("<"..name..">")
			for key,value in pairs(meta) do 
				if not string.find(key, "__..") then 
					if type(value) == "function" then
						print("\t[f] "..name..":"..key.."()") 
					elseif type(value) == "userdata" then
						print("\t[v] "..name..":"..key)
					end
				end
			end
		end
	end
end
-------------------------------------------------------------------------------

-- Lua ���� ��ü�� userdata�� �νĵȴ�.
print("g_test	-> ", g_test)
print("temp	-> ", temp)
print("a	-> ", a)

-- C++ ���� ����� g_test �� ��ü ������ ���캻��.
print("objinfo(g_test)")
objinfo(g_test)

-- constructor �� ���� ������ temp ��ü ������ ���캻��.
print("objinfo(temp)")
objinfo(temp)

-- ������� ���� A ����ü ���� a ��ü ������ ���캻��.
print("objinfo(a)")
objinfo(a)

