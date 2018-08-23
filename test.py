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
        #print(trimmed[1], '--FAIL--')
        return False
    else:
        #print(trimmed[1], '  PASS  ')
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
        #print(trimmed[1], '--FAIL--')
        return False
    else:
        #print(trimmed[1], '  PASS  ')
        return True

# counter variables
fail = 0
yes = 0
summary = open('../count.txt', 'a')
try:
    f = open('output.txt')
except:
    summary.write('This mutant did not run correctly!\n')

# header stuff
for i in range(3):
    f.readline()
cipher = f.readline()
#print(cipher)
for i in range(4):
    f.readline()
plain = f.readline()
#print(plain)
for i in range(2):
    f.readline()

# MR 1 testing
#print('\nMR 1\n')
for x in range(10):
    result = three(f)
    if result:
        yes += 1
    else:
        fail += 1

# MR 2 testing
#print('\nMR 2\n')
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
#print('\nMR 3\n')
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

# MR 4 testing
#print('\nMR 4\n')
line = f.readline()		# 4.1
header = line
trimmed = header.split('------')
for x in range(3):
    f.readline()
compare1 = f.readline()
for x in range(3):
    f.readline()
compare2 = f.readline()
for x in range(2):
    f.readline()
if not simTest(compare1, compare2):
    #print(trimmed[1], '--FAIL--')
    fail += 1
else:
    #print(trimmed[1], '  PASS  ')
    yes += 1
line = f.readline()		# 4.2
header = line
trimmed = header.split('------')
for x in range(3):
    f.readline()
compare1 = f.readline()
for x in range(3):
    f.readline()
compare2 = f.readline()
for x in range(2):
    f.readline()
if simTest(compare1, compare2):
    #print(trimmed[1], '--FAIL--')
    fail += 1
else:
    #print(trimmed[1], '  PASS  ')
    yes += 1
line = f.readline()         	# 4.3
header = line
trimmed = header.split('------')
for x in range(3):
    f.readline()
compare1 = f.readline()
for x in range(7):
    f.readline()
compare2 = f.readline()
for x in range(2):
    f.readline()
if simTest(compare1, compare2):
    #print(trimmed[1], '  PASS  ')
    yes += 1
else:
    #print(trimmed[1], '--FAIL--')
    fail += 1
line = f.readline()         	# 4.4
header = line
trimmed = header.split('------')
for x in range(3):
    f.readline()
compare1 = f.readline()
for x in range(15):
    f.readline()
compare2 = f.readline()
for x in range(2):
    f.readline()
if simTest(compare1, compare2):
    #print(trimmed[1], '  PASS  ')
    yes += 1
else:
    #print(trimmed[1], '--FAIL--')
    fail += 1

# last test
correct1 = '95f8a5e5dd31d9 0491e89 de9ace932e5a84b 0736c5d52\n'
correct2 = '80 0 0 0 0 0 0 0 0 1 2 3 4 5 6 7\n'
correct3 = '  97  98  99 100 101 128   0   0\n   0   0   0   0   0   0   1   2\n   3   4   5   6   7  26   0   0\n   0   0   0   0   0   0   0   0\n   0   0   0   0   0 149 248 165\n 229 221  49 217   0  73  30 137\n  13 233 172 233  50 229 168  75\n   0 115 108  93  82   0   0   0\n'
for x in range(4):
    f.readline()
compare1 = f.readline()
for x in range(3):
    f.readline()
compare2 = f.readline()
f.readline()
compare3 = f.readline()
for x in range(7):
   compare3+=f.readline()
if (str(compare1) != correct1):
    #print('Last Test Failed')
    fail += 1
elif (str(compare2) != correct2):
    #print('Last Test Failed')
    fail += 1
elif (str(compare3) != correct3):
    #print('Last Test Failed')
    fail += 1
else:
    #print('Last Test Passed')
    yes += 1


#print('\n\n----------------------------\nResults\n')
#print('Passed: ',yes,'/37')
#print('Failed: ',fail,'/37')
#print((yes/37)*100,'%')

summary = open('../count.txt', 'a')
if fail != 0:
  summary.write(str(fail))
  summary.write('\n')
else: 
  summary.write('This mutant survived all.\n')
 
