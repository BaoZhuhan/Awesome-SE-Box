import matplotlib.pyplot as plt
x=['China', 'Japan', 'France', 'Germany', 'Spanish', 'Italy']
y=[22000,  2900,  2100,  1500,  2900,  900]
plt.pie(y,explode=[0.2,0,0,0,0,0],labels=x,shadow=True,startangle=60,autopct='%1.1f%%')
plt.title("high-speed rail")
plt.show()
