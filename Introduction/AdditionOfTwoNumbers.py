"""
Priyanka Kasture | pkasture2010@gmail.com
Addition Of Two Numbers: 15 and 25 (constants)
Expctd Result: 40
"""

# Importing the Tensorflow Library
import tensorflow as tf

# Assuming the numbers as tensorflow constants
A = tf.constant(15,name="A")
B = tf.constant(25,name="B")

# Using a predefined function [tf.add] to add A and B
C = tf.add(A,B,name="C")

'''
Here tensorflow has created a graph. But it does not run the graph till you create an instance of a session and then run the same. Before creating and running the session, if we try printing value of C, the output will be a tensor, not actual value of C.
'''
print("Value of C before running tensor:",C)

''' Value of C before running tensor: Tensor("C_1:0", shape=(), dtype=int32) '''

# An instance of a session is created using tf.Session() call.
sess = tf.Session()

# Now we run the session and store the results of the computation in 'output'
output = sess.run(C)
print("Value of C after running graph:",output)

# Closing the session
sess.close()

