import requests
import time
import datetime
import re

balance=200

while True:
    index=index+datetime.timedelta()
    a = requests.get('http://167.172.99.92:3100/get_price/2020-04-17T10:00:00/2020-04-17T10:00:01/1 ').json()
    print(a['last'])
    
