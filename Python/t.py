
def mystery(l):
    if len(l) < 2:
        return (l)
    else:
        return ([l[-1]] + mystery(l[1:-1]) + [l[0]])
runs = {"Test":{"Dhawan":[190,14,35,119],"Kohli":[3,103,13,42],"Pujara":[153,15,133,8]},"ODI":{"Dhawan":[37],"Kohli":[63]}}
print(mystery([31, 12, 71, 28, 35]))
triples = [(x, y, z) for x in range(1, 4) for y in range(2, 5) for z in range(5, 8) if x + y > z]
print (triples)
#runs["ODI"]["Pujara"][0]=44
#runs["ODI"]["Pujara"] = [44]
#runs["ODI"]["Pujara"].extend([44])
#runs["ODI"]["Pujara"].append([44])
inventory = {}
#inventory[("Amul","Mystic Mocha")] = 55
#inventory[["Amul","Mystic Mocha"]] = 55
#inventory["Amul, Mystic Mocha"] = 55
#inventory["Amul"] = ["Mystic Mocha",55]