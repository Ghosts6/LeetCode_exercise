import pandas as pd

def selectFirstRows(employees: pd.DataFrame) -> pd.DataFrame:
    """Returns the first 3 rows of the employees DataFrame."""
    return employees.head(3)

# Test Case
if __name__ == "__main__":
    data = {
        "employee_id": [3, 90, 9, 60, 49, 43],
        "name": ["Bob", "Alice", "Tatiana", "Annabelle", "Jonathan", "Khaled"],
        "department": ["Operations", "Sales", "Engineering", "IT", "HR", "Admin"],
        "salary": [48675, 11096, 33805, 37678, 23793, 40454]
    }
    
    employees_df = pd.DataFrame(data)
    print(selectFirstRows(employees_df))
