# q4.py
import numpy as np

def run_iteration():
    ranarr = np.random.rand(2, 3)
    print("\nRandom 2x3 Array (ranarr):\n", ranarr)

    onearr = np.ones((2, 3))
    print("\nArray of ones (onearr):\n", onearr)

    boolarr = ranarr > 0.5
    print("\nBoolean array where ranarr > 0.5 (boolarr):\n", boolarr)

    newarr = onearr[boolarr]
    print("\nNew array using boolean indexing (newarr):\n", newarr)

    print("Shape of newarr:", newarr.shape)
    
run_again = 'y'
while run_again == 'y':
    run_iteration()
    run_again = input("Do you want to run again? (y/n): ")
