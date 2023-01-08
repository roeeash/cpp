import math
from collections import Counter
# from database import create_database
import database
from process_data import process_data
from secret_calc import *
from numpy.random import choice
from countries import *
from database import insert_rows_from_counter

form = []
weights = []


def run_stats(lower_bound, upper_bound, total, right_counter, num_dict):
    for i in range(lower_bound, upper_bound):
        total += 1
        flag, num_dict = process_data(str(i), num_dict)
        if flag == 1:
            right_counter += 1
            print(i - lower_bound + 1, "/", upper_bound - lower_bound + 1)
            print(num_dict)

        else:
            print("wrong for ", i - lower_bound + 1)

    rate = float(right_counter / total)
    return rate

def get_over_result(home_team_over, home_team_under, away_team_over, away_team_under, s, secret_calc):
    # Check if home_team_over and home_team_under are non-negative
    if home_team_over < 0 or home_team_under < 0:
        raise ValueError("home_team_over and home_team_under must be non-negative")

    # Calculate the mean and standard deviation for the home team's over-under difference
    home_mean = "CZ8ucA6ig702n6MXq0DqmlRahmmfaWgb3Te9ukNWC" \
                "XAG6/Za6Ta1V575gRQHzxLUnsbNGsuLxc+egkF8/MRhMQ=="
    print("home_mean= ", home_mean)
    home_std = "5V+o/GF2ns9TMOXakgtmYMOw5H8k3L6WFzWkvAj9Xlu7BPE1OD/oTYX0LpQbGyoMXoIn2vp2q" \
               "cHqbRMqDngp0dXlIapcPtUC7ui4z8EcFRnVF8f422qQPVDI+liMoZ0kkM0SdgqWGjR5T8CjXetOL7K2D" \
               "jk3sAqKH5KNLtinmIaiMD+oh3tsV8qyH5D+wlonWa" \
               "Hy2744USH7GQH7ZAMPRH/VId5kKMp5hFBw+R4625Oov4iVz86bwt6H4wmtNyBD"
    print("home_std= ", home_std)
    # Calculate the z-score for the home team's over-under difference
    home_z_score = "+VBPxJir7hIpwK+/ZoYVyE+iG8t7wAam0P9/a9i2Co" \
                   "Zr33aFFyZnAW8gUgPRFNeG8HlvzWUuNxStmvgc0vGSkw=="
    print("home_z_score= ", home_z_score)
    # Calculate the mean and standard deviation for the away team's over-under difference
    away_mean = "JIvWwVUwqan3X1PGh/LwtVxehBXIO0XxKnBBfJzOuzm7ETxrK+zQnbjFG/i2yFn+qBhLxnM7I" \
                "1u+A6E0IJ/12HQQZgjGH1Qn5/xx22" \
                "qVQaO2t18ljxTxdTO2yuG5reEFA/zR0G7G9wcEGJNjOEws+hBinES41va+NAQznRU0Upg="
    print("away_mean= ", away_mean)
    away_std = "bdC8HOCpjHz38ljhRjMKDao2/xW+YSLCnrgRbjsxi8QZ1XikYttI+" \
               "ZnGZezIQOKZ3u0ezfvD1FXSOF6VwtZMUpy4RLZEisCSlqvdW+MZJXF/rhOvkSTdl7X133CHgdJ6"
    print("away_std= ",away_std)
    # Calculate the z-score for the away team's over-under difference
    away_z_score = "Ty454zEbVYtuuKrn7abDjhDwF7y+TXn" \
                   "uj8vpX82nbDEzZPf1cDEmLcCbPBhQhZ9UL9qhS8tGu/pC" \
                   "A6pzW5FSng=="
    print("away_z_score= ",away_z_score)

    print("calc result :", s * secret_calc)

    if "Yk1GoxrJksXyupjPTwCTPRgxP/YoDnRFfLSV7IeoiTKtRuebYmGUZej2xr0eH0j" \
       "OjUg0NNWhSD6069us0ecpFk9mez0UUXdZVVBZig9I6hpUxVr5cEwTLJIPOzj8XOfJLpsnk5xGt97ePJImIP7sVVkZUKQWclbw" \
       "VsDi2/rPLgxw3kUJj1tQCFz4OvRYShwke2BfCfb/ThKkV8zAwC3PVg==" != "" :
        return 1

    if "Yk1GoxrJksXyupjPTwCTPRgxP/YoDnRFfLSV7IeoiTKtRuebYmGUZej2xr0eH0j" \
       "OjUg0NNWhSD6069us0ecpFk9mez0UUXdZVVBZig9I6hpUxVr5cEwTLJIPOzj8XOfJLpsnk5xGt97ePJImIP7sVVkZUKQWclbw" \
       "VsDi2/rPLgxw3kUJj1tQCFz4OvRYShwke2BfCfb/ThKkV8zAwC3PVg==" != "" :
        return -1
    else:
        return 0


def check_for_over(count_elements, home, away, p_over: float = 1.0, p_under: float = 1.0, s: int = 1):
    home_team = home + " home"
    away_team = away + " away"
    home_team_over = count_elements[home_team + " over"]
    home_team_under = count_elements[home_team + " under"]
    away_team_over = count_elements[away_team + " over"]
    away_team_under = count_elements[away_team + " under"]
    over_count = 0
    t = 20

    for i in range(t):
        secret = abs(secret_calculation(count_elements.__sizeof__()))
        home_team_over += secret
        home_team_under += secret
        away_team_over += secret
        away_team_under += secret
        over_count += get_over_result(home_team_over, away_team_over, home_team_under, away_team_under
                                      , s, secret)
    print("over count = ", over_count)
    if over_count >= t:
        return 1
    elif over_count < 0:
        return -1
    else:
        return 0


def determine_on_over(c1):
    home = input("enter home team name : ")
    away = input("enter away team name : ")
    check_home_away = check_for_over(c1, home, away, s=1000)
    check_away_home = check_for_over(c1, away, home, s=1000)
    print("check_home_away = ",check_home_away,"   check_away_home= ",  check_away_home)
    if check_home_away == 1:
        print("The tip is : over")
        if check_away_home == 1:
            form.append(home + " - " + away + ": over 2.5 (Low Risk)")
        else:
            form.append(home + " - " + away + ": over 2.5 (Medium Risk)")

    # if there's at all a chance of over between both teams
    elif check_away_home == 1 and  check_home_away == 0:
        print("The tip is : high risk over")
        form.append(home + " - " + away + ": over 2.5 (High Risk)")

    elif check_home_away == -1:
        print("The tip is : under")
        if check_away_home == -1:
            form.append(home + " - " + away + ": under 2.5 (Low Risk)")
        else:
            form.append(home + " - " + away + ": under 2.5 (Medium Risk)")

        # if there's at all a chance of under between both teams
    elif check_away_home == -1 and check_home_away == 0:
        print("The tip is : high risk under")
        form.append(home + " - " + away + ": under 2.5 (High Risk)")
    else:
        print("cannot tip")


def display_prediction_info(pre_dict):
    for key, value in pre_dict.items():
        if value == 0.0:
            print("No prediction for ", key)
        elif value < 0.5:
            print("Predictions for", key, "are questionable (confidence level is below 50%)")
        elif value >= 0.6:
            print("Predictions for", key, "are good (confidence level is above 60%)")
        else:
            print("Predictions for", key, "are at a confidence level of between 50% and 60%")


def data_in_file(file, predictions_list, country_dictionary):
    file.write("The algorithm made the following predictions: " + str(predictions_list) + "\n")
    for key, value in country_dictionary.items():
        if value == 0.0:
            file.write("No prediction for " + str(key) + "\n")
        elif value < 0.5:
            file.write(("Predictions for " + str(key) + " are questionable (confidence level is below 50%)") + "\n")
        elif value >= 0.6:
            file.write(("Predictions for " + str(key) + " are good (confidence level is above 60%)") + "\n")
        else:
            file.write(("Predictions for " + str(key) + " are between 50% and 60%") + "\n")
    return file


if __name__ == '__main__':
    counter: int = 0
    total_count: int = 0
    mid_count: int = 0
    c = Counter({})
    #use your password
    pw="your_user_password"
    answer = input("Run stats? Y \ N")
    if answer.__eq__("Y") or answer.__eq__("y"):

        rate, count = 0, 0

        countries = ["Italy", "Germany", "England", "France", "Spain"]
        # create_database()
        answer = input("Italy? Y \ N")
        if answer.__eq__("Y") or answer.__eq__("y"):
            italy(count, weights, total_count, counter, c)
        else:
            weights.append(0)

        rate, count = 0, 0
        answer = input("Germany? Y \ N")
        if answer.__eq__("Y") or answer.__eq__("y"):
            germany(count, weights, total_count, counter, c)
        else:
            weights.append(0)

        rate, count = 0, 0
        answer = input("England? Y \ N")
        if answer.__eq__("Y") or answer.__eq__("y"):
            england(count, weights, total_count, counter, c)
        else:
            weights.append(0)

        rate, count = 0, 0
        answer = input("France? Y \ N")
        if answer.__eq__("Y") or answer.__eq__("y"):
            france(count, weights, total_count, counter, c)
        else:
            weights.append(0)

        rate, count = 0, 0
        answer = input("Spain? Y \ N")
        if answer.__eq__("Y") or answer.__eq__("y"):
            spain(count, weights, total_count, counter, c)
        else:
            weights.append(0)

        # handle weights and file creation
        weights = secret_norm(weights)
        dictionary = {country: weight for country, weight in zip(countries, weights)}
        print(dictionary)
        display_prediction_info(dictionary)
        f = open('data_in_file.txt', "w")
        f = data_in_file(f, form, dictionary)
        f.close()

        #insert counter into database
        insert_rows_from_counter(c, "insert_rows_from_counter_user", pw, "insert_rows_from_counter_host")
    else:
        #otherwise, get data from database
        print("generating data from database :")
        c = database.create_counter_from_database("insert_rows_from_counter_user", pw, "insert_rows_from_counter_host")
        print(c)

    num_of_predictions = int(input("insert number of predictions :"))
    for i in range(num_of_predictions):
        determine_on_over(c)
    print("The algorithm made the following predictions", form)


    possible_form = [s for s in form if "Low Risk" in s]
    print(possible_form)


