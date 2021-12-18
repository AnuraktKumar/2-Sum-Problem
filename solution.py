A = range(-10000, 10001)
B = {}
#The code block below removes duplicate and marks the position corresponding to the number as 1
with open("input_file.txt", "r") as inp:
    for i in inp:
        B[int(i)] = 1
count = 0
for t in A:
   for j in list(B.keys()):
       a = int(t - int(j))
       #print("Hi!")
       if a!=j and (a in B):
           count += 1
           break
   print("t:", t, "Count:", count)
print("Final Count:", count)
