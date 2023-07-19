import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import pandas as pd

m = pd.read_csv('out/build/x64-Debug/data.csv')

plt.style.use('seaborn')
fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)

t = m['time']


def animation(i):
    x1 = []
    y1 = []
    x1 = m[0:i]['mass2:PX']
    y1 = m[0:i]['mass2:PY']

    x2 = []
    y2 = []
    #x2 = m[0:i]['mass3:PX']
    #y2 = m[0:i]['mass3:PY']

    ax.clear()
    ax.plot(x1, y1)
    #ax.plot(x2, y2)


ani = FuncAnimation(fig, animation, interval=33)
plt.show()
