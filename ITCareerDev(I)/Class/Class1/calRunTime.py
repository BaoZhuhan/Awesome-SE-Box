import time
limit = 10*1000*1000
start = time.perf_counter()
while True:
    limit -= 1
    if limit <= 0 :
        break
delta = time.perf_counter() - start
print("程序运行时间是：{}秒".format(delta))