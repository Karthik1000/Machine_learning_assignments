import random
f = open('perceptron.txt', "r")
lines = f.readlines()
f.close()
list=[]

list2=[]

for i in lines:
    list.append(i)
    str=i.split(',')
    if (str[4] =='Iris-versicolor\n'):
    	list1=[]
    	for j in str:
    		j=j*1
    		if (j == 'Iris-versicolor\n'):
    			j=1.0
    		j=float(j)
    		list1.append(j)
    elif (str[4] == 'Iris-virginica\n'):
    	list1=[]
    	for j in str:
    	 	#j = j*(-1)
    	 	if (j == 'Iris-virginica\n'):
    	 		j=-1.0
    	 	else:
    	 		j=float(j)
    	 		j=j*1
    	 		
    	 	#j=float(j)
    	 	list1.append(j)
		
    #print("**********************")
    list2.append(list1)

list3=[]
for l in list2:
	l=[1.0] + l
	list3.append(l)

random.shuffle(list3)

#for m in list2:
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
	if (count < 70):
		list4.append(m[:-1])
		list5.append(m[-1])
	else:
		list41.append(m[:-1])
		list51.append(m[-1])
	count = count + 1
#print(count)

## theta matrix ==== list6
list6=[]
for a in range(0,5):
	list6.append(0)

#print(list4[2][1])
for z in range(0,1000):
	## y predicted matrix ==== list7
	#for i in range(0,7):
	#	print(list6[i])

	#print("-----------------before--------------------------")
	
	list7=[]
	for i in range(0,count-30):
		sum=0.0
		for j in range(0,5):
			sum = sum + (list4[i][j] * list6[j])
		if(sum >= 0):
			list7.append(1.0)
		else:
			list7.append(-1.0)
			
	#for k in list7:
	#	print(k)	

	## error finding..  ## === list8
	list8=[]
	for i in range(0,count-30):
		err = (list5[i] - list7[i])
		list8.append(err) 

	#for k in list8:
	#	print(k)		
	#print("-----------------------------------------------------------")
	##  cost function ...
	sum1=0.0
	for i in range(0,count-30):						## cost = sum(error**2)/N
		sum1 = sum1 + (list8[i] * list8[i])
		
	cost =  sum1/(count-30)		######cost function
	cost = cost + 0.001		#
	#print(cost)	 ## cost function 
	#print("----------cost------------")

	## update theta value
	## differentiate value ==== list9
	list9=[]
	for i in range(0,5):
		sum2=0.0
		for j in range(0,count-30):
			sum2 = sum2 + (list4[j][i] * list8[j])
		list9.append(sum2)

	## theta value is updating...
	alpha = 0.01
	for a in range(0,5):
		list6[a] = list6[a] + (2 * alpha * list9[a])/(count-30)			##{ w = w + [sum(error**2)*X]/N }
	
		
	#for i in range(0,7):
	#	print(list6[i])
	
	#print("-----------------------------------------------------------")

print("\nminimum training error function value is ",cost)

print("\ntotal testing error function .... ")
list7=[]
for i in range(0,30):
	sum=0.0
	for j in range(0,5):
		sum = sum + (list41[i][j] * list6[j])
	if(sum >= 0):
		list7.append(1.0)
	else:
		list7.append(-1.0)
			
#for k in list7:
#	print(k)	

## error finding..  ## === list8
list8=[]
count1=0
for i in range(0,30):
	if(list51[i] != (list7[i])):
		count1 = count1+1		

#for k in list8:
#	print(k)		
#print("-----------------------------------------------------------")
##  cost function ...
	
cost =  (count1/((30)))*100
print(cost)	 ## cost function 
