# Machine_learning_assignments
On K-NNC, Linear regression and perceptron on different big datasets
In k – nearest neighbour classifier (k-NNC), we draw a sphere which contains k nearest neighbours of X.
Among these k nearest neighbours, according to the majority of classes around we decide the predicted class label.
But to obtain optimal k value for having most accuracy of the classifier we apply cross validation technique and to find the distances we use Minkowski Distance formula.
		



In r-fold cross validation, we partition the training set into r blocks and consider all except one as training set and the remaining as the test set.
For the range of k values (here 1 to 10) find the accuracy on the test set. We take the mean of all the accuracies of test set nodes for the whole range of 1 to 10. The maximum of mean of all the test accuracy rates,corresponding k value will be the best k value for the given classifier.
We can further have variety of variations in finding the distance between two nodes. This is done by changing the value of p (here 1 to 5) in Minkowski distance formula. It becomes Euclidean distance when p = 2.
We repeat the above with all possible range of  k values and p values. Our best bet for the classifier gives us the maximum accuracy rate on the test set with  minimum error.
<br>
<b>We explained our code in respective (ML1.c && ML2.c) comments.</b>
