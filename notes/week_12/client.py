import requests

response = requests.get("http://127.0.0.1:7500/myapi/add/5/7")
print(response.text)
