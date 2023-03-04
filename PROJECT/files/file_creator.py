import random




with open ("sensor.txt","w") as f:
    for i in range (100):
        x=random.randint(0, 1)
        f.write(str(x))
        f.write("\n")
