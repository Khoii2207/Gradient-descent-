import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
data = pd.read_csv('data.csv')


# print(data) 

# plt.scatter(data.Study_Hours, data.Student_Score)
# plt.show()

def loss_function (m, b, points):
    total_error = 0
    for i in range(len(points)):
        x = points.iloc[i].Study_Hours
        y = points.iloc[i].Student_Score
        total_error += (y - (m * x + b)) ** 2
    return total_error / float(len(points))

def gradient_descent(m_now, b_now, points, L):
    m_gradient = 0
    b_gradient = 0

    n = len(points)

    for i in range(n):
        x = points.iloc[i].Study_Hours
        y = points.iloc[i].Student_Score

        m_gradient += (-2/n) * x * (y - (m_now * x + b_now))
        b_gradient += (-2/n) * (y - (m_now * x + b_now))

    m = m_now - m_gradient * L
    b = b_now - b_gradient * L
    return m, b


m = 0
b = 0 
L = 0.001
epochs = 1000

for i in range(epochs):
    Loss = loss_function(m, b, data)
    if(i >= 1 and i < 10):
        print(f"epochs {i}: {Loss}")
    m, b = gradient_descent(m, b, data, L)
plt.scatter(data.Study_Hours, data.Student_Score, color = "black")
plt.plot(list(range(1, 11)), [m * x + b for x in range(1, 11)], color = "blue")

plt.show()
print(m, b)