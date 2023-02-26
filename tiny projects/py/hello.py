# fileName=input("Enter the file name that you wanna generate:")
# content=input("enter content here:")

# with open(fileName,'w') as file:
#     file.write(content)


# open_file=input("do you wanna open this file? y or n")
# if open_file in ['y', 'n']:
#     if open_file=='y':
#         with open(fileName,'r') as file:
#             print(file.read())

import requests
import time
req=requests.get("http://swapi.dev/api/people/1")
person=req.json()
print({person['name']})

for film in person['films']:
    req=requests.get(film)
    film=req.json()
    print(film['title'])