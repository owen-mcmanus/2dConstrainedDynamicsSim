import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import pandas as pd

m = pd.read_csv('out/build/x64-Debug/data.csv')

plt.style.use('seaborn')
fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)

t = m['time']
x = m['mass1:PX']
y = m['mass1:PY']


def animation(i):
    x = []
    y = []
    x = m[0:i]['mass1:PX']
    y = m[0:i]['mass1:PY']

    ax.clear()
    ax.plot(x, y)


ani = FuncAnimation(fig, animation, interval=33)
plt.show()
