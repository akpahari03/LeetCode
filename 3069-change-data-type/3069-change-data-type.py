import pandas as pd

def changeDatatype(students: pd.DataFrame) -> pd.DataFrame:
    #method 1
    # students['grade'] = students['grade'].astype(int)
    #method 2
    students = students.astype({
        'grade' : int
    })
    return students