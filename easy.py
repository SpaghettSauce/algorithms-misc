import matplotlib.pyplot as plt
t = [x/100 for x in range(-100, 200)]
aprior_est = 22
def F(x, t):
    val = t * (2 + abs(x))** (0.5) - t**2
    return val
x = []
for i in range(len(t)):
    cur_val_for_x = 2
    for j in range(aprior_est):
        cur_val_for_x = F(cur_val_for_x, t[i])
    x.append(cur_val_for_x)
plt.plot(t, x)
plt.xlabel('t')
plt.ylabel('x(t)')
plt.grid(True)
plt.show()