import pandas as pd

def modifySalaryColumn(employees: pd.DataFrame) -> pd.DataFrame:
    """Multiplies the 'salary' column of the given DataFrame by 2 in-place."""
    employees['salary'] *= 2
    return employees

# Test cases
if __name__ == "__main__":
    data = {
        'name': ['Jack', 'Piper', 'Mia', 'Ulysses'],
        'salary': [19666, 74754, 62509, 54866]
    }
    employees_df = pd.DataFrame(data)
    
    print("Original DataFrame:")
    print(employees_df)
    
    result = modifySalaryColumn(employees_df)
    
    print("\nModified DataFrame:")
    print(result)
