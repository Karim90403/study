#!/usr/bin/env python
# coding: utf-8

# Задание 1
word = input()
if len(word) % 2 == 0:
    print(word[len(word) // 2 - 1] + word[len(word) // 2])
else:
    print(word[len(word) // 2])
# Задание 2
sum = 0
while True:
    num = int(input("Введите число:\n"))
    if num == 0:
        print("Результат:\n", sum)
    sum += num
# Задание 3
boys = ['Peter', 'Alex', 'John', 'Arthur', 'Richard']
girls = ['Kate', 'Liza', 'Kira', 'Emma', 'Trisha']
boys.sort()
girls.sort()
if len(boys) == len(girls):
    print("Идеальные пары:")
    for i in range(len(boys)):
        print(boys[i], "и", girls[i])
else:
    print("Внимание, кто-то может остаться без пары!")
# Задание 4
countries_temperature = [
    ['Thailand', [75.2, 77, 78.8, 73.4, 68, 75.2, 77]],
    ['Germany', [57.2, 55.4, 59, 59, 53.6]],
    ['Russia', [35.6, 37.4, 39.2, 41, 42.8, 39.2, 35.6]],
    ['Poland', [50, 50, 53.6, 57.2, 55.4, 55.4]]
]
print("Средняя температура в странах:")
for i in range(len(countries_temperature)):
    print(countries_temperature[i][0],
          round((sum(countries_temperature[i][1]) / len(countries_temperature[i][1]) - 32)*  5 / 9,1),'C')
# Задание 5
ids = {'user1': [213, 213, 213, 15, 213],
       'user2': [54, 54, 119, 119, 119],
       'user3': [213, 98, 98, 35]}
list = []

for key in ids:
    for i in range(len(ids[key])):
        list.append(ids[key][i])
print(set(list))
# Задание 6
queries = [
    'смотреть сериалы онлайн',
    'новости спорта',
    'афиша кино',
    'курс доллара',
    'сериалы этим летом',
    'курс по питону',
    'сериалы про спорт',
]

Array = []
for i in range(len(queries)):
    Array.append(len(queries[i].split()))
wordCount = list(set(Array))
for i in range(len(wordCount)):
    print("Поисковых запросов, содержащих ", wordCount[i], " слов(а): ",
          round((Array.count(wordCount[i]) / len(Array) * 100), 2), "%")
# Задание 7
results = {
    'vk': {'revenue': 103, 'cost': 98},
    'yandex': {'revenue': 179, 'cost': 153},
    'facebook': {'revenue': 103, 'cost': 110},
    'adwords': {'revenue': 35, 'cost': 34},
    'twitter': {'revenue': 11, 'cost': 24},
}

for key in results:
    results[key]['ROI'] = round((results[key]['revenue'] / results[key]['cost'] - 1) * 100, 2)
from pprint import pprint
pprint(results)
# Задание 8
stats = {'facebook': 55, 'yandex': 115, 'vk': 120, 'google': 99, 'email': 42, 'ok': 98}
max = 0
for key in stats:
    if stats[key] > max:
        max = stats[key]
        name = key
print("Максимальный объем продаж на рекламном канале:", name)
