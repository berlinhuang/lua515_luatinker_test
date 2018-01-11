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


-- ����Ļ�����Ϣ
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
            -- ��������ĸ�������
			for key,value in pairs(meta) do 
				if not string.find(key, "__..") then 
					if type(value) == "function" then
						print("\t[f] "..name..":"..key.."()") -- [f] test:set()
					elseif type(value) == "userdata" then
						print("\t[v] "..name..":"..key) -- [v] test:_test
					end
				end
			end
		end
	end
end
-------------------------------------------------------------------------------

-- Lua ��ӡ����ĵ�ַ����
print("g_test	-> ", g_test)
print("temp	-> ", temp)
print("a	-> ", a)

-- C++ ע���ȫ�ֶ���g_test
print("objinfo(g_test)")
objinfo(g_test)

-- Lua�����Ķ���
print("objinfo(temp)")
objinfo(temp)

-- δע��Ķ���
print("objinfo(a)")
objinfo(a)

