import requests

url = requests.get('https://api.ipify.org/?format=json')
print(url.text)