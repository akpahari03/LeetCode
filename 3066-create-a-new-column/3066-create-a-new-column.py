import pandas as pd

def createBonusColumn(employees: pd.DataFrame) -> pd.DataFrame:
    #method 1
    # employees['bonus'] = employees['salary']*2

    #method 2
    employees = employees.assign(bonus=employees['salary']*2)
    return employees