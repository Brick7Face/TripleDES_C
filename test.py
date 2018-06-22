# counter variables
fail = 0
yes = 0
f = open('output.txt')

# header stuff
for i in range(3):
    f.readline()
cipher = f.readline()
print(cipher)
for i in range(4):
    f.readline()
plain = f.readline()
print(plain)
for i in range(2):
    f.readline()

# MR 1 testing
print('\nMR 1\n')
line = f.readline()
for x in range(10):
    header = line
    trimmed = header.split('------')
    for i in range(11):
        f.readline()
    compare1 = f.readline()
    for i in range(5):
        f.readline()
    compare2 = f.readline()
    if compare1 == compare2:
        print(trimmed[1], '\t--FAIL--')
        fail += 1
    else:
        print(trimmed[1], '\t  PASS  ')
        yes += 1
    for i in range(2):
        f.readline()
    line = f.readline()

# MR 2 testing
print('\nMR 2\n')
for x in range(2):  # 2 for now; needs to be 10
    header = line
    trimmed = header.split('------')
    for i in range(4):
        f.readline()
    compare1 = f.readline()
    for i in range(3):
        f.readline()
    compare2 = f.readline()
    if compare1 == compare2:
        print(trimmed[1], '\t--FAIL--')
        fail += 1
    else:
        print(trimmed[1], '\t  PASS  ')
        yes += 1
    for i in range(2):
        f.readline()
    line = f.readline()

# MR 3 testing
print('\nMR 3\n')
for x in range(6):  # 6 for now; needs to be 10
    header = line
    trimmed = header.split('------')
    for i in range(4):
        f.readline()
    compare1 = f.readline()
    for i in range(3):
        f.readline()
    compare2 = f.readline()
    if compare1 == compare2:
        print(trimmed[1], '\t--FAIL--')
        fail += 1
    else:
        print(trimmed[1], '\t  PASS  ')
        yes += 1
    for i in range(2):
        f.readline()
    line = f.readline()
 
