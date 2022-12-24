#!/usr/bin/env python
# coding: utf-8

# In[2]:


import numpy as np


# In[3]:


#Задание 1
n=int(input())
array=np.arange(n)[::-1]
print(array)


# In[ ]:


#Задание 2
N=int(input())
sum=0
matr = np.zeros((N,N), dtype=int)
numbers=np.arange(N)[::-1]
for i in range(N):
    matr[i][i]=numbers[i]
    sum+=matr[i][i]
for i in matr:
	print(*i)
print(sum)


# In[ ]:


#Задание 3
print("Введите число перменных:")
m = int(input())
print("Введите число уравнений в системе:")
n = int(input())
matr = np.zeros((n, m), dtype=int)
array = np.zeros(n)
for i in range(n):
    for j in range(m):
        print("Введите X", j + 1, " уравнения номер ", i + 1, ":", sep='')
        matr[i][j] = int(input())
    print("Введите значение выражения номер ", i + 1, ":", sep='')
    array[i] = int(input())

ansver = np.linalg.solve(matr, array)
print(ansver)


# In[4]:


#Задание 4

users_stats = np.array(
    [
        [2, 1, 0, 0, 0, 0],
        [1, 1, 2, 1, 0, 0],
        [2, 0, 1, 0, 0, 0],
        [1, 1, 2, 1, 0, 1],
        [0, 0, 1, 2, 0, 0],
        [0, 0, 0, 0, 0, 5],
        [1, 0, 0, 0, 0, 0],
        [0, 1, 1, 0, 0, 0],
        [0, 0, 0, 1, 1, 3],
        [1, 0, 0, 2, 1, 4]
    ],
    np.int32
)

next_user_stats = np.array([0, 1, 2, 0, 0, 0])

users_stats_length = np.linalg.norm(users_stats)
next_user_stats_length = np.linalg.norm(next_user_stats)

mas = np.dot(users_stats, next_user_stats) / (users_stats_length * next_user_stats_length)

for i in range(len(mas)):
    if(mas[i]==max(mas)):
        print('На этого пользователя похож пользователь:',i)


# In[ ]:




