import api_data_orgranizer
from api_data_orgranizer import create_dict_for_players,create_dict_for_teams
from database import insert_rows_from_dict

if __name__ == "__main__":
    data = {}
    '''
    for i in range(1,200):
        d = create_dict_for_players(data, str(i), "100")
        print(i," was successful")
    print(len(d.keys()))
    '''

    for i in range(82):
        d = create_dict_for_players(data, str(i), "100")
        print(i, " was successful")

    print(len(d))

    # database name
    db = "basketball_data"
    pw = "Yuhaz1234@"
    conn = insert_rows_from_dict(d, host_name="localhost", user_name="root", user_password=pw, _db=db)
