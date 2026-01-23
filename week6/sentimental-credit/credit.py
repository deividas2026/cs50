import re
from sys import exit

card_number = input("Number: ")
multiply_by_two = card_number[::-1][1::2]
dont_multiply = card_number[::-1][0::2]
card_sum = 0

for x in multiply_by_two:
	product = int(x) * 2
	if product > 9:
		card_sum += int(str(product)[0])
		card_sum += int(str(product)[1])
	else:
		card_sum += product

for x in dont_multiply:
	card_sum += int(x)

if card_sum % 10 != 0:
	print("INVALID")
	exit(1)

visa = r"^4(\d{12}|\d{15})$"
master = r"^5(1|2|3|4|5)\d{14}$"
amex = r"^3(4|7)\d{13}$"

m_visa = re.fullmatch(visa, card_number)
m_master = re.fullmatch(master, card_number)
m_amex = re.fullmatch(amex, card_number)

if m_visa is not None:
	print("VISA")
elif m_master is not None:
	print("MASTERCARD")
elif m_amex is not None:
	print("AMEX")
else:
	print("INVALID")

