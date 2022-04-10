import matplotlib.pyplot as plt


def sequenceMaker(l, r):
    res = 0
    count = 0
    while (l % 4 != 0):
        l -= 1
        count += 1

    if count == 0:
        res = l
    elif count == 1:
        res = 1

    elif count == 2:
        res = l + 3
    elif count == 3:
        res = 0

    for i in range(l+count+1, r+1):

        if (i % 4 == 0):
            res = res ^ i

        elif i % 4 == 1:
            res = res ^ 1

        elif (i % 4 == 2):
            res = res ^ (i + 1)

        elif (i % 4 == 3):
            res = res ^ 0

    return res


x = []
y = []
n = 127
for p in range(10):
    for i in range(p):
        x.append(i)
        y.append(sequenceMaker(i, p))


# print(x, y)

plt.xlabel('x Axis')
plt.ylabel('y axis')

plt.title('Plot Simulation')

plt.grid(True)
plt.plot(x, y)

plt.show()
