#!/usr/bin/python3
def square_matrix_simple(matrix=[]):
    squared_result = []
    for line in matrix:
        squared_result.append([c**2 for c in line])
    return squared_result
