import matplotlib.pyplot as plt

x = [0.01, 0.02, 0.03, 0.04, 0.05]
y = [0, 0.25, 0.50, 0.75, 1]
p = [0.49, 0.15, 0.01, 0, 0.63, 0.64, 0.51, 0.19, 0.01, 0, 0.01]
plt.xticks(x)
plt.yticks(y)
plt.plot(x,y, color='white')
plt.axhline(y = 0.20, color = 'r', linestyle = '--', label='Null of zero effect')
# 0.01 -> 3, 0.03 -> 1, 0.05 -> 1
y = [0.6, 0, 0.2, 0, 0.2]
plt.plot(x, y, marker='o', color='deepskyblue', label = 'Observed p-curve')
plt.plot(x, [0.4, 0.2, 0.17, 0.14, 0.11], linestyle='--', dashes=(8, 1), color='forestgreen', label='Null of 33% power')
plt.legend(loc='upper right')
for a, b in zip(x, y):
    plt.annotate(b, (a, b), xytext=(-8,8),textcoords='offset points')
plt.savefig('plot.png')
plt.show()



