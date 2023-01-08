import json
import math
import numpy
import pandas as pd
import requests
from bs4 import BeautifulSoup
from selenium import webdriver
import secret_calc
import get_scripts



# from database import insert_to_database


def input_match_data(match):
    base_url = "https://understat.com/match/"
    # match = str(input("enter match id: "))
    address = base_url + match
    return address


'''
uses request address to scrape the data using lxml and json
'''


def prep_params(name):
    x = [name[index][key] for index in range(len(name)) for key in name[index] if key == "X"]
    y = [name[index][key] for index in range(len(name)) for key in name[index] if key == "Y"]
    xg = [name[index][key] for index in range(len(name)) for key in name[index] if key == "xG"]
    team = [name[index][key] for index in range(len(name)) for key in name[index] if key == "h_team"]
    return x, y, xg, team


'''
returns the x,y,xg,team parameters for the calculation from the webpage
'''


def get_parameters(input_data):
    home = input_data['h']
    away = input_data['a']

    x = [home[index][key] for index in range(len(home)) for key in home[index] if key == "X"]
    y = [home[index][key] for index in range(len(home)) for key in home[index] if key == "Y"]
    xg = [home[index][key] for index in range(len(home)) for key in home[index] if key == "xG"]
    team = [home[index][key] for index in range(len(home)) for key in home[index] if key == "h_team"]

    x += [away[index][key] for index in range(len(away)) for key in away[index] if key == "X"]
    y += [away[index][key] for index in range(len(away)) for key in away[index] if key == "Y"]
    xg += [away[index][key] for index in range(len(away)) for key in away[index] if key == "xG"]
    team += [away[index][key] for index in range(len(away)) for key in away[index] if key == "a_team"]

    return x, y, xg, team


def create_list(input_data, input_goals, c):
    x, y, xg, team = get_parameters(input_data)
    col_names = ['x', 'y', 'xg', 'team']
    df = pd.DataFrame([x, y, xg, team], index=col_names)
    df = df.T

    df['x'] = df['x'].astype(float)
    df['y'] = df['y'].astype(float)
    df['xg'] = df['xg'].astype(float)
    df.loc["Total"] = df.sum(numeric_only=True)
    pd.set_option("display.max_rows", None, "display.max_columns", None)

    names = df.team.unique()
    home_name = names[0] + " home"
    away_name = names[1] + " away"

    secret = abs(secret_calc.secret_calculation(2 * math.pi))
    #print("secret = ", secret)
    projection = df["xg"]["Total"]
    projection += secret
    input_goals += secret
    proj = ""
    t_high = (2.5 + secret)
    t_low = (2.5 - secret)

    if projection >= t_high + 2 * secret:
        proj = " over"
    else:
        proj = " under"

    # calculate the prediction
    if (projection > t_high + 2 * secret and input_goals >= t_high + 0.5) or (projection <= t_low - 2 * secret and input_goals < t_low - 0.5):
        right = True
        # print("projection was right projection :%s, goals:%s" % (projection, input_goals))
        home_name += proj
        if home_name in c.keys():
            c[home_name] += 1
        else:
            c[home_name] = 1
        # insert_to_database(home_name,c[home_name] )
        away_name += proj
        if away_name in c.keys():
            c[away_name] += 1
        else:
            c[away_name] = 1
        # insert_to_database(away_name , c[away_name])
    else:
        right = False

    return right, c


def compare(html):
    # parse the HTML content
    soup = BeautifulSoup(html, 'html.parser')
    title = soup.find_all("title")
    counter = 0
    sum_goals = 0
    index = 0
    title = str(title[0])
    while counter < 2 and index <= len(title):
        x = title[index]
        if x.isdigit():
            counter += 1
            sum_goals += int(x)
        index += 1

    return sum_goals


def process_data(match_id, c):
    url = input_match_data(match_id)
    html = get_scripts.get_webpage(url)
    data = get_scripts.get_json_shots_data(html)
    goals = compare(html)
    flag, c = create_list(data, goals, c)
    if flag == 1:
        return 1, c
    else:
        return 0, c
