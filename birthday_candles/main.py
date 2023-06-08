import streamlit as st
import pandas as pd
import numpy as np

years_to_live=[75.97,75.45,74.48,73.50,72.52,71.53,70.54,69.55,68.56,67.57,66.57,65.58,64.59,63.60,62.61,61.63,60.66,59.70,58.74,57.79,56.85,55.91,54.98,54.06,53.16,52.22,51.31,50.39,49.48,48.56,47.65,46.74,45.83,44.92,44.01,43.10,42.19,41.28,40.37,39.47,38.56,37.65,36.75,35.85]

male_data=pd.read_csv('m_pre_2015.csv',error_bad_lines=False)

df=pd.DataFrame(
    male_data
)
st.dataframe(df)

curr_year=st.number_input(
    'input the current year',
    min_value=1900,
    max_value=2095
)
age=st.number_input(
    'input youre age', 
    min_value=0, 
    max_value=119
)

'the current year is:',curr_year

'youre age is:',age

life_expectancy=0

for i in range(1,len(df.index)):
    if (df.iloc[i,1]==curr_year and df.iloc[i,2]==age):
        life_expectancy=df.iloc[i,7]

"you're life expectancy is:",life_expectancy