import matplotlib.pyplot as plt
import matplotlib
matplotlib.rcParams['font.family']='SimHei'
matplotlib.rcParams['font.sans-serif'] = ['SimHei']
plt.plot([1,2,4,6,9],[1,2,3,4,5],color='r', linewidth=2,
         linestyle="dashed",marker='o')
plt.title("坐标系标题")
plt.xlabel('时间 (s)')
plt.ylabel('范围 (m)')
plt.xticks([1,2,3,4,5,6,7,8,9],[r'$\pi/3$', r'$2\pi/3$', r'$\pi$',
                   r'$4\pi/3$', r'$5\pi/3$',r'$2pi$',r'$7\pi/3$',
                                r'$8\pi/3$',r'$3pi$'])
plt.show()
