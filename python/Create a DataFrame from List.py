import pandas as pd
from typing import List

def createDataframe(student_data: List[List[int]]) -> pd.DataFrame:
    """Converts a 2D list into a DataFrame with columns student_id and age."""
    return pd.DataFrame(student_data, columns=['student_id', 'age'])

# Test cases
if __name__ == "__main__":
    # case 1
    student_data = [
        [1, 15],
        [2, 11],
        [3, 11],
        [4, 20]
    ]
    print(createDataframe(student_data))
