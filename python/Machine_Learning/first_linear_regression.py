import matplotlib.pyplot as plt

x = [1,2,3,4,5]
y = [4,12,28,52,80]

plt.xlabel('x Axis')
plt.ylabel('y axis')

plt.title('Linear Regression')

plt.grid(True)
plt.plot(x,y)

plt.show()
