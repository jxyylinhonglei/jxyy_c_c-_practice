
#import os
## path = "C:/Users/Administrator/Desktop/pdfdecrypt-master"
#path = "D:/C++"
#def func(ttt):
#    print("|",end="")
#    _len=len(ttt)
#    for i in range(_len):
#        print(" ",end="")
#def show(path,ttt,j,i):
#    if(i==0):
#        print("|")
#    for file in os.listdir(path):
#        print("|---",end="")
#        print(file,end="")
#        file1 = path + '/' + file
#        if os.path.isdir(file1):
#            show(file1,file,j,i+1)
        #print("")                       // c u注释，uk。
        #if j!=i:
        #    func(ttt+"---")

#ttt=""
#i=0;
#show(path,ttt,0,i)
#import math
#print(math.sin(math.pi/2))
#def func(n):#天数
#    if n==1:
#        return 1 
#    else:
#        return 2*(func(n-1)+1)
#print(func(10))

#M=int(input())#将字符串转化为整数
#N=int(input())
#r=M*N#提前保存好M与N的乘积
#if M<N:#让M为最大的数，如果输入进来的M大于N就不需要交换M与N的值
#    tmp=M
#    M=N
#    N=tmp
#while M%N!=0:
#    M=N
#    N=M%N
##出来while循环N就是最大公因数
#print("最大公因数为",N)
#print("最小公倍数为",r/N)#两个数相乘除以最大的公因数
#def func(n):
#    if(len(n)==0):
#        return [1]
#    elif len(n)==1:
#        return [1,1]
#    else:
#        list=[1,1]
#        sz=len(n)
#        for i in range(1,sz):
#            tmp=n[i-1]+n[i]
#            list.insert(i,tmp)
#        return list;
#def func1(n):
#    list=[]
#    for i in range(n):# 1到n-1
#        list=func(list);
#        for k in range(n-i):
#            print(" ",end="")
#        for j in range(len(list)):
#            print(list[j],"",end="")
#        print("")

#func1(5)
##for i in range(1,10):
##    print(i)

#pip install
#import time
#import random
##print(time.time())#获取当前时间戳
##stime=time.localtime()#结构化时间
##print(stime)
##stime=time.localtime()#将时间戳转化结构化时间，没有参数就获取当前时间戳转化为结构化时间
##print(stime)
##print(stime.tm_year)
#file_name="a.jpg"
#ttime=str(int(time.time()))
#tmp=""
#for i in range(5):
#    tmp=str(random.randint(1,10))+tmp
#random.random()
#file_name=ttime+tmp+file_name
#print(file_name)
#name="tom"
#age=10
##time.sleep(60)#线程休眠
#print(f"我的名字是{name},年龄是{age}")#格式化输出
#print(time.asctime(time.localtime()))#国外时间类型
##2000-10-1 12:00:00  time.strptime时间字符串转化为时间格式
##time.mktime()#将结构化时间转化为时间戳
#t1="2001-7-14 00:00:00"
#result=time.strptime(t1,"%Y-%m-%d %H:%M:%S")
#print((time.time()-time.mktime(result))/60)
# 输入：
# n = int(input())
# x = sorted(list(map(int, input().split())))
# y = sorted(list(map(int, input().split())))
# 
# m = int(input())
# q = []
# for _ in range(m):
#     q.append(list(map(int, input().split())))

n=3
x=[3,4,5]
y=[3,4,5]
m=2
q=[[1,1],[3,3]]


e = []
for xx, yy in zip(x, y):
    a = -yy / xx
    b = yy
    e.append([a, b])

 
def check(dx, dy, point):
    a, b = point
    return a * dx + b <= dy


for dx, dy in q:
    left = 0
    right = n
    while left < right:
        mid = (left + right) // 2
        if check(dx, dy, e[mid]):
            left = mid + 1
        else:
            right = mid
    print(left)
