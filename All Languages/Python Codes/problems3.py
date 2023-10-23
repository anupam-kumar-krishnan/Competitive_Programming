with open('exchangecurrency.txt') as f:
    lines = f.readlines()

dictcurrency = {}
for lines in lines:
    parsed = lines.split("/t")
    dictcurrency[parsed[0]]=parsed[1]

amount = int(input("Enter amount:\n"))
print("Enter the name of the currency you want to convert this amount to?  Available Options:\n")
print(item)

for item in dictcurrency.keys():
    currency = input("Please enter one of these values: \n")
    print(f"{amount} INR is equal to {amount*float(dictcurrency[currency])} {currency}")




