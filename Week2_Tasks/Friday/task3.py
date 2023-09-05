import requests
from time import sleep

while True:
    url = requests.get('https://www.boredapi.com/api/activity')
    print(url.json()['activity'])
    sleep(2)