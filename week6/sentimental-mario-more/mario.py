while True:
	try:
		height = int(input("Height: "))
	except ValueError:
		continue
	if height > 0 and height < 9:
		break
	
for row in range(height):
	print(" " * (height - row - 1), end="")
	print("#" * (row + 1), end="")
	print("  ", end="")
	print("#" * (row + 1))


	
