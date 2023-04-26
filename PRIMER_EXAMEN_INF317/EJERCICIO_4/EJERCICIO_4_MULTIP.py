from multiprocessing import Pool

def fibonacci_block(start, end):
    fibs = []
    a, b = 0, 1
    for i in range(start, end):
        fibs.append(a)
        a, b = b, a + b
    return fibs

if __name__ == '__main__':
    with Pool() as p:
        block_size = 1000
        num_blocks = 1
        results = p.starmap(fibonacci_block, [(i * block_size, (i + 1) * block_size) for i in range(num_blocks)])
    fibs = [num for block in results for num in block]
    print(fibs)
