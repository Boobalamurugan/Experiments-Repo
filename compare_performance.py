import time
import torch
import numpy as np
import jax
import jax.numpy as jnp
import tensorflow as tf

# Check device availability
if tf.config.list_physical_devices('GPU'):
    print("TensorFlow GPU")
else:
    print("TensorFlow CPU")

if torch.cuda.is_available():
    print("PyTorch GPU")
else:
    print("PyTorch CPU")

if jax.devices()[0].device_kind == "gpu":
    print("JAX GPU")
else:
    print("JAX CPU")

def measure_time(func, *args, avg_number=100):
    start_time = time.time()
    for _ in range(avg_number):
        func(*args)
    end_time = time.time()
    return ((end_time - start_time) / avg_number) * 1000


def comparsion_operations(size=1000):
    np_a = np.random.rand(size, size).astype(np.float32)
    np_b = np.random.rand(size, size).astype(np.float32)
    pt_a = torch.from_numpy(np_a).to(torch.float32)
    pt_b = torch.from_numpy(np_b).to(torch.float32)
    jax_a = jnp.array(np_a, dtype=jnp.float32)
    jax_b = jnp.array(np_b, dtype=jnp.float32)
    tf_a = tf.convert_to_tensor(np_a)
    tf_b = tf.convert_to_tensor(np_b)

    operations = {
        "Matrix multiplication": [
            (lambda: np.dot(np_a, np_b)),
            (lambda: torch.matmul(pt_a, pt_b)),
            (lambda: jax.numpy.dot(jax_a, jax_b)),
            (lambda: tf.matmul(tf_a, tf_b))
        ],
        "Element wise addition": [
            (lambda: np_a + np_b),
            (lambda: pt_a + pt_b),
            (lambda: jax_a + jax_b),
            (lambda: tf_a + tf_b)
        ],
        "Element wise multiplication": [
            (lambda: np_a * np_b),
            (lambda: pt_a * pt_b),
            (lambda: jax_a * jax_b),
            (lambda: tf_a * tf_b)
        ]
    }

    results = []

    for operation_name, funcs in operations.items():
        np_time = measure_time(funcs[0])
        pt_time = measure_time(funcs[1])
        jax_time = measure_time(funcs[2])
        tf_time = measure_time(funcs[3])

        results.append(f"{operation_name}: NUMPY: {np_time:.3f}ms, PYTORCH: {pt_time:.3f}ms, JAX: {jax_time:.3f}ms, TENSORFLOW: {tf_time:.3f}ms")
    
    return results

comparison = comparsion_operations()
for result in comparison:
    print(result)