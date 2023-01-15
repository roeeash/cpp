import requests
import json


# count how many players are there at most per page
def count_max_per_page(_page, _per_page):
    url = "https://free-nba.p.rapidapi.com/stats"

    querystring = {"page": _page, "per_page": _per_page}

    headers = {
        "X-RapidAPI-Key": "920e0b5635mshcc871236773f1cbp1b1d5cjsnbc5934157e17",
        "X-RapidAPI-Host": "free-nba.p.rapidapi.com"
    }

    response = get_response_text(url,headers,querystring)
    data = response.json()

    while 'next' in response.links.keys():
        response = requests.get(response.links['next']['url'])
        data.extend(response.json())
    d = create_dictionary_from_text(response.text)
    print(len(d['data']))


#get response text for players from rapis api
def get_response_text_for_players(_page, _per_page):
    url = "https://free-nba.p.rapidapi.com/stats"

    querystring = {"page": _page, "per_page": _per_page}

    headers = {
        "X-RapidAPI-Key": "920e0b5635mshcc871236773f1cbp1b1d5cjsnbc5934157e17",
        "X-RapidAPI-Host": "free-nba.p.rapidapi.com"
    }

    return get_response_text(url,headers,querystring)

#get response text for teams
def get_response_text_for_teams(_page, _per_page):
    url = "https://www.balldontlie.io/api/v1/games"

    querystring = {"page": _page, "per_page": _per_page}

    return get_response_text(url,{},querystring)

# runs generic get_response_text
def get_response_text(url,headers,querystring):
    if headers != {}:
        response = requests.request("GET", url,headers=headers, params=querystring)
    else:
        response = requests.request("GET", url,  params=querystring)
    return response.text

# creates python dict from json object
def create_dictionary_from_text(text):
    data = json.loads(text)
    return data  # The resulting dictionary


# forms the dictionary values based on an argument
# that says if it is a team dict or player dict
def form_dict_values_by_argument(value_dict, data_item,dict_type):
    if dict_type == "teams":
        value_dict["id"] = data_item["id"]
        value_dict["game_date"] = data_item["date"]
        value_dict["home_team_id"] = data_item["home_team"]["id"]
        value_dict["home_team_name"] = data_item["home_team"]["full_name"]
        value_dict["home_team_score"] = data_item["home_team_score"]
        value_dict["season"] = data_item["season"]
        value_dict["visitor_team_id"] = data_item["visitor_team"]["id"]
        value_dict["visitor_team_name"] = data_item["visitor_team"]["full_name"]
        value_dict["visitor_team_score"] = data_item["visitor_team_score"]

    elif dict_type == "players":
        value_dict["first name"] = data_item["player"]["first_name"]
        value_dict["last name"] = data_item["player"]["last_name"]
        value_dict["position"] = data_item["player"]["position"]
        value_dict["height"] = data_item["player"]["height_feet"], data_item["player"]["height_inches"],
        value_dict["weight"] = data_item["player"]["weight_pounds"]

        # player's team
        value_dict["team"] = data_item["team"]["full_name"]
        # points
        value_dict["points per game"] = data_item["pts"]
        # assists
        value_dict["assists per game"] = data_item["ast"]
        # rebounds
        value_dict["rebounds per game"] = data_item["reb"]
        # blocks
        value_dict["blocks per game"] = data_item["blk"]
        # steals
        value_dict["steals per game"] = data_item["stl"]
        # field goal pct
        value_dict["field goal pct"] = data_item["fg_pct"]

    return value_dict


# create dict for teams
def create_dict_for_teams(data, page_number, number_per_page):
    return create_dict(data, page_number, number_per_page, "teams")


# create dict for players
def create_dict_for_players(data, page_number, number_per_page):
    return create_dict(data, page_number, number_per_page, "players")


# create dict from json.loads
def create_dict(data, page_number, number_per_page, dict_type):
    # get text from website
    text = get_response_text_for_teams(page_number, number_per_page)

    # create_dictionary
    d = create_dictionary_from_text(text)

    for data_item in d["data"]:
        value_data = {}

        # player data
        value_data = form_dict_values_by_argument(value_dict=value_data,
                                                  data_item=data_item,dict_type=dict_type)

        # if it is a player
        if dict_type == "players":
            # insert to data dictionary
            data[data_item["player"]["id"]] = value_data

        # if it is a team
        elif dict_type == "teams":
            # insert to data dictionary
            data[data_item["id"]] = value_data

    return data
