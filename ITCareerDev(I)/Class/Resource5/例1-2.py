import numpy as np
import matplotlib.pyplot as plt
a = np.linspace(0, 10, 10)
plt.plot(a,a*1.5,'go-',a,a*2,'b-..',a,a*5,'r1:')#格式字符串中的顺序没有要求
plt.show()
