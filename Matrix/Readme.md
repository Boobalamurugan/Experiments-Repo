# Matrix Operations Performance Comparison
This repository contains a performance comparison of popular Python frameworks for matrix operations, focusing on their CPU performance. The frameworks compared are NumPy, PyTorch, TensorFlow, and JAX.

### Overview
Matrix operations are fundamental in many computational tasks. This project benchmarks the following operations across the frameworks:

1.Matrix Multiplication

2.Element-wise Addition

3.Element-wise Multiplication


### Frameworks Compared

**NumPy**: The foundational package for numerical computing in Python.

**PyTorch**: A versatile framework known for its deep learning capabilities.

**TensorFlow**: A powerful platform optimized for a wide range of hardware configurations.

**JAX**: A framework gaining popularity for its efficient handling of matrix operations and automatic differentiation.

### Experiment

The experiment measures the time taken for each matrix operation using randomly generated 1000x1000 matrices. The performance of each framework is compared in milliseconds (ms).

### Results
Here are the results from the performance comparison:

**Matrix multiplication**: NUMPY: 49.634ms, PYTORCH: 36.959ms, JAX: 32.054ms, TENSORFLOW: 32.515ms

**Element wise addition**: NUMPY: 0.647ms, PYTORCH: 0.604ms, JAX: 0.697ms, TENSORFLOW: 1.156ms

**Element wise multiplication**: NUMPY: 0.619ms, PYTORCH: 0.610ms, JAX: 0.770ms, TENSORFLOW: 1.304ms

### Notes
Performance can vary between runs due to system load, background processes, and other factors. It’s essential to consider these variables when interpreting results.

### Setup
To run the experiments, follow these steps:

## Run on Google Colab
You can run the performance comparison script directly on Google Colab by clicking the button below:

[![Open In Colab](https://colab.research.google.com/assets/colab-badge.svg)](https://colab.research.google.com/drive/1uCCo_vAQQbDGN8TUHyaQ84S4J2tSuG5U#scrollTo=JWp3Pn-0NfI3)

1.Clone the repository:


```
git clone https://github.com/yourusername/repository.git
cd Matrix
```
2.Install the required packages:

```
pip install torch torchvision torchaudio
pip install tensorflow-cpu
pip install -U jax
```
or
```
pip install -r requirements.txt
```
3.Run the performance comparison script:

```
python compare_performance.py
```
### Script Overview
The compare_performance.py script initializes matrices, measures execution time for matrix operations, and outputs the results. It uses Google Colab for easy setup and execution.


### Contact
For any questions or feedback, please reach out to Boobalamurugan.

