import re

regex = r'^\d+,\sSt\.\s[\w\s]+,\s\w+$'
address = '22, St. salah salem, Giza'
if re.match(regex,address):
    print('Valid RE')
else:
    print('Invalid RE')