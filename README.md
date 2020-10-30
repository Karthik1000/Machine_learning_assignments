# Machine_learning_assignments
## Machine learning Assignment-1
<!DOCTYPE html>
<br>
<br>
In k – nearest neighbour classifier (k-NNC), we draw a sphere which contains k nearest neighbours of X. Among these k nearest neighbours, according to the majority of classes around we decide the predicted class label. But to obtain optimal k value for having most accuracy of the classifier we apply cross validation technique and to find the distances we use Minkowski Distance formula.
<br>
<br>


![Capture](https://user-images.githubusercontent.com/38176926/97692099-56149100-1ac5-11eb-9210-1db35a22d9db.JPG)

<br>
In r-fold cross validation, we partition the training set into r blocks and consider all except one as training set and the remaining as the test set.
For the range of k values (here 1 to 10) find the accuracy on the test set. We take the mean of all the accuracies of test set nodes for the whole range of 1 to 10. The maximum of mean of all the test accuracy rates,corresponding k value will be the best k value for the given classifier.
We can further have variety of variations in finding the distance between two nodes. This is done by changing the value of p (here 1 to 5) in Minkowski distance formula. It becomes Euclidean distance when p = 2.
We repeat the above with all possible range of  k values and p values. Our best bet for the classifier gives us the maximum accuracy rate on the test set with  minimum error.
<br>
<b>We explained our code in respective (ML1.c && ML2.c) comments.</b>

<b>Results obtained:-  </b><br>
<b>1. Wheat seeds Data set.</b><br>
We obtained maximum accuracy when p=1 and different values of k (1 to 10).You can observe the values of accuracy percentages in below image.
As we are shuffling the data each time ,the pair of k and p values for which we are getting maximum accuracies is changing .Also we are getting maximum accuracies between 85 .0to 90.0%.
<br>
<br>
<b>2. 2.Optical recognition of Handwritten digits dataset:</b>
 Here we compared our results with the results provided in that dataset link(optdigits.names).
 <br><br>
Dataset results(expected):<br>
(K,p) values          -----      accuracy <br>
1,2		-------- 	98.00%	<br>
2,2		-------- 	97.30%	<br>
3,2		-------- 	97.21%	<br>
4,2		-------- 	97.43%	<br>
5,2		-------- 	97.05%	<br>
6,2		-------- 	97.03%	<br>
7,2		-------- 	97.26%	<br>
8,2		-------- 	97.17%	<br>
9,2		-------- 	97.20%	<br>
10,2		-------- 	97.74%	<br>
11,2		-------- 	97.79%	<br>
<br>
Dataset results(obtained):
(K,p) values          -----      accuracy <br>
1,2		-------- 	95.00%	<br>
2,2		-------- 	94.30%	<br>
3,2		-------- 	97.31%	<br>
4,2		-------- 	94.63%	<br>
5,2		-------- 	97.25%	<br>
6,2		-------- 	97.43%	<br>
7,2		-------- 	97.76%	<br>
8,2		-------- 	97.47%	<br>
9,2		-------- 	97.40%	<br>
10,2		-------- 	97.84%	<br>
11,2		-------- 	97.99%	<br>
<br>
			Thank you……..

</body>

## Machine learning Assignment - 2
<body>
<br>
<b>Dataset:-</b>
<br>
We have chosen 1st 200 patterns form the dYacht Hydrodynamics Data Set for training.The remaing patterns are used for testing. 
<br>
Algorithm:-
<br>
1.All the points(i.e the feature sets) are stored as list of lists(which is ‘list’ in our code).<br>
2.All the corresponding output values(residuary resistance per unit weight of displacement, adimensional) for each point is stored in another list at the corresponding indices.<br>
3.Now 1 is augmented in the 0th index of every point(to make the dot product easy).<br>
4.Shuffling of all the points is done so as to maintain the randomness of the dataset.<br>
5.Now, a random weight vector is assumed with all the values in it as ‘0’(‘list6’ in our code).<br>
6.Then the dot product of these two vectors(‘list’.’list6’) is done and all the outputs are stored in another list namely predicted vector(‘list7’ in our code).<br>
7.Now the error is calculated as the difference of predicted value and original value, these errors are stored in another list (‘list8’ in our code).<br>
8.The mean square of these errors is caluculated,which is the cost function and the weight list is updated.<br>
9.Now these steps are repeated for ‘n’(10000 to 100000 in our case) until the optimum accuracy is achieved(i.e cost function is minimized).<br>
<br>
<b>Error :-</b><br>
Training error – 28 to 55(due to both shuffling and nonshuffling and due to change in iterations)<br>
Testing error – 31 to 50%(due to both shuffling and nonshuffling and due to change in iterations)<br>
<br>

<b>Dataset :-</b><br>
We have stored the iris data set that belongs to Versicolor and Virginica classes,shuffled the data set and then used the 1st 70 patterns for training and remaining 30 patterns for testing.
<br>
<b>Algorithm :-</b>
<br>
1.We stored all the points(feature sets including the class label) in a list.<br>
2.Then ‘1’ is augmented at the starting index of every point.<br>
3.Now, in these points the class labels ‘Iris-versicolor’,’Iris-virginica’ are replaced with ‘1’ and ‘-1’ respectively and this entire dataset is stored in ‘list3’ in our code.<br>
4.Now the dataset is shuffled and the 1st 70 are used for training(list4 in code) and remaining(‘list41’ in code).<br>
5.Now a Weight vector is assumed with all the initial values as ‘0’.<br>
6.Dot product between all the feature set and the weight list is done(list4[i][j]*list6[i]).<br>
7.Now if the ith output is >= 0 it is assigned to class ‘1’ else to class ‘-1’ and stored in another list(‘list7’ in code).<br>
8.Now the differnce of list7 and list5(i.e originalpredicted) is stored as error in another list(‘list8’ in the code)<br>
9.The mean square of these errors is calculated(cost function) and the weight list is updated.<br>
10.This Algo is repeated until optimal accuracy and minimum error is achieved.( up to 10000 iterations)<br>
11.Then using the weight vector corresponding to minimum error is used to classify the test set and error on the test set is calculated.<br>
<br>
<b>Errors:-</b>

Training error – 0 to 5(due to both shuffling and nonshuffling and due to change in iterations)<br>
Testing error – 0 to 10%(due to both shuffling and nonshuffling and due to change in iterations)<br>
</body>
