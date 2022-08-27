
""" age=input("请输入年龄")
age=int(age)
if age>18:
    print("你可以打工了")
else:
    print("haha") """

print(27**(1/3))
i=0
sum=0
while i<=200:
    sum=sum+i
    i=i+1
    if i==101:
        break
print(sum)


for i in [1,2,3]:
    print(i)




for i in range(5):
    print(i+1)

i=0
print(type(i))

#range(start,end,step),range参数最少一个，step默认是一
#/代表严格意义除号，//取整的除号
for i in range(2,10,2):
    print(i)