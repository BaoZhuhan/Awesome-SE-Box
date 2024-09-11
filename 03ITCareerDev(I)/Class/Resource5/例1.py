import numpy as np  
import matplotlib.pyplot as plt
x = np.linspace(0, 16, 100)
y = np.cos(x)
#plt.plot(x, y, "r^-.")
plt.plot(x, y, color='r', marker="o", linestyle="-")

plt.show()

