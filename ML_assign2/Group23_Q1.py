import random
f = open('Linear_regression.txt', "r")
lines = f.readlines()
f.close()
list=[]

list2=[]

for i in lines:
    list.append(i)
    str=i.split()
    list1=[]
    for j in str:
    	#print(j)
    	j=float(j)
    	list1.append(j)
    #print("**********************")
    list2.append(list1)

list3=[]
for l in list2:
	l=[1.0] + l
	list3.append(l)

random.shuffle(list3)

#for m in list3:
#	print(m)	
## x matrix === list4
## x1 matrix === list41
## y matrix === list5
## y2 matrix == list51
list51=[]
list41=[]
list4=[]	
list5=[]
count=0
for m in list3:
	#print(m[:-1])	
	if (count < 200):
		list4.append(m[:-1])
		list5.append(m[-1])
	else:
		list41.append(m[:-1])
		list51.append(m[-1])
	count = count + 1

## theta matrix ==== list6
list6=[]
for a in range(0,7):
	list6.append(0)

#print(list4[2][1])
for z in range(0,10000):
	## y predicted matrix ==== list7
	#for i in range(0,7):
	#	print(list6[i])

	#print("-----------------before--------------------------")
	
	list7=[]
	for i in range(0,count-108):
		sum=0.0
		for j in range(0,7):
			sum = sum + (list4[i][j] * list6[j])
		list7.append(sum)
			
	#for k in list7:
	#	print(k)	

	## error finding..  ## === list8
	list8=[]
	for i in range(0,count-108):
		err = (list5[i] - list7[i])
		list8.append(err) 

	#for k in list8:
	#	print(k)		
	#print("-----------------------------------------------------------")
	##  cost function ...
	sum1=0.0
	for i in range(0,count-108):				## cost = sum(error**2)/N
		sum1 = sum1 + (list8[i] * list8[i])
		
	cost =  sum1/(2*(count-108))
	#print(cost)	 ## cost function 
	#print("----------cost------------")

	## update theta value
	## differentiate value ==== list9
	list9=[]
	for i in range(0,7):
		sum2=0.0
		for j in range(0,count-108):
			sum2 = sum2 + (list4[j][i] * list8[j])
		list9.append(sum2)

	## theta value is updating...
	alpha = 0.01
	for a in range(0,7):
		list6[a] = list6[a] + (2 * alpha * list9[a])/(count-108)			##{ w = w + [sum(error**2)*X]/N }
	
		
	#for i in range(0,7):
	#	print(list6[i])
	
	#print("-----------------------------------------------------------")

print("\n total training error function -- ",cost)

print("\n total testing error function .... ")
list7=[]
for i in range(0,108):
	sum=0.0
	for j in range(0,7):
		sum = sum + (list41[i][j] * list6[j])
	list7.append(sum)
			
#for k in list7:
#	print(k)	

## error finding..  ## === list8
list8=[]
for i in range(0,108):
	err = (list51[i] - list7[i])
	list8.append(err) 

#for k in list8:
#	print(k)		
#print("-----------------------------------------------------------")
##  cost function ...
sum1=0.0
for i in range(0,108):
	sum1 = sum1 + (list8[i] * list8[i])
	
cost =  sum1/(2*108)
print(cost)	 ## cost function 


