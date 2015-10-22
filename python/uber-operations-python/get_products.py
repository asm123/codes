import requests
import json

url = 'https://api.uber.com/v1/products'

parameters = {
    'server_token': 'x4I5xyXjsV7ke7Gp6yHdv5taV1l7R17J9Fe0viTt',
    'latitude': 12.9399453,
    'longitude': 77.6938651,
}

response = requests.get(url, params=parameters)

data = response.json()


print json.dumps(data, indent=4, sort_keys=True)