def simTest(comp1, comp2):
    if comp1 != comp2:
        return False
    else:
        return True

# function to test similarity of strings
def simTest2(comp1, comp2):
    if len(comp1) != len(comp2):
        return False
    else:
        num = 0
        for i in range(len(comp1)):
            if comp1[i] == comp2[i]:
                num += 1
        if num >= 16:
            return True
        else:
            return False

# function to process MR's with 3 prints
def three(f):
    line = f.readline()
    header = line
    trimmed = header.split('------')
    for i in range(7):
        f.readline()
    compare1 = f.readline()
    for i in range(3):
        f.readline()
    compare2 = f.readline()
    for i in range(2):
        f.readline()
    if simTest(compare1, compare2):
        print(trimmed[1], '--FAIL--')
        return False
    else:
        print(trimmed[1], '  PASS  ')
        return True

# function to process MR's with 2 prints
def two(f):
    line = f.readline()
    header = line
    trimmed = header.split('------')
    for i in range(3):
        f.readline()
    compare1 = f.readline()
    for i in range(3):
        f.readline()
    compare2 = f.readline()
    for i in range(2):
        f.readline()
    if simTest(compare1, compare2):
        print(trimmed[1], '--FAIL--')
        return False
    else:
        print(trimmed[1], '  PASS  ')
        return True

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
for x in range(10):
    result = three(f)
    if result:
        yes += 1
    else:
        fail += 1

# MR 2 testing
print('\nMR 2\n')
for x in range(4):  # 2.1 - 2.4
    result = two(f)
    if result:
        yes += 1
    else:
        fail += 1
result = three(f)   # 2.5
if result:
    yes += 1
else:
    fail += 1
for x in range(2):  # 2.6 - 2.7
    result = two(f)
    if result:
        yes += 1
    else:
        fail += 1
for x in range(2):
    result = three(f)   # 2.8 - 2.9
    if result:
        yes += 1
    else:
        fail += 1
result = two(f)   # 2.10
if result:
    yes += 1
else:
    fail += 1

# MR 3 testing
print('\nMR 3\n')
for x in range(6):  # 3.1 - 3.6
    result = two(f)
    if result:
        yes += 1
    else:
        fail += 1
result = three(f)   # 3.7
if result:
    yes += 1
else:
    fail += 1
for x in range(5):  # 3.8 - 3.12
    result = two(f)
    if result:
        yes += 1
    else:
        fail += 1


print('\n\n----------------------------\nResults\n')
print('Passed: ',yes,'/32')
print('Failed: ',fail,'/32')
print((yes/32)*100,'%')
 
