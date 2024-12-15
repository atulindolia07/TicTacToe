import pandas as pd

read_file = pd.read_csv('23.53_tempus.logv_runtime1.csv')
read_file.to_excel('23.53_tempus_logv_runtime1.xlsx', index=None, header=True)