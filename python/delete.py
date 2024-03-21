#!python

import requests
import json

url = 'http://localhost:8081'

print('Insert value')
while True:
    data = input()
    if data.isdigit():
        break
    else:
        print("Введите число!!!")
        
data = {'temp': data}

response = requests.delete(url, json =data)

if response.status_code == 200:
    print('Запрос успешно выполнен')
    print('Ответ сервера:')
    print(response.text)
else:
    print('Ошибка при выполнении запроса. Код ошибки:', response.status_code)
