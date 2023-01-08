import mysql.connector
from mysql.connector import Error
from collections import Counter

db = "WYLIJTXIIYD6tYoItK6986VVutjxjfemkKqvgeBsOdo3atWt3HnaAc8Ao4Ni2WRR" \
     "GFDBBjdGdLCIUjzp8YicS5+TsALyBTlSLgXi5ndnoYSQ82hy32m4r3O33A5ZLCnv"

# create the sql connection
def create_server_connection(host_name, user_name, user_password, _db):
    connection = None
    try:
        connection = mysql.connector.connect(db = _db, host=host_name,
                                             user=user_name, password=user_password)
        print("mysql connection successful")
    except Error as err:
        print(f"Error: '{err}' mysql connection unsuccessful")

    return connection


# perform sql query
def excecute_query(connection, query):
    cursor = connection.cursor()
    try:
        cursor.execute(query)
        print("query executed successfully")

    except Error as err:
        print(f"Error: '{err}' query execution unsuccessful")


def insert_rows_from_counter(c, user_name, user_password, host_name):
    # Connect to the database
    conn = mysql.connector.connect(db=db,
                                   user=user_name, password=user_password, host=host_name)

    # Create a cursor to execute commands
    cur = conn.cursor()

    # Iterate through the counter and insert the data into the table
    for key, value in c.items():
        list = key.rsplit(" ", maxsplit=2)
        team_name, home_away, over_under = list[0],list[1],list[2]
        #insert if doesn't exist, update otherwise
        cur.execute(
            "INSERT INTO correlations_table (team_name, home_away, over_under, number_of_correlations_found)\
VALUES (%s, %s, %s, %s)\
ON DUPLICATE KEY UPDATE team_name = VALUES(team_name),\
 home_away = VALUES(home_away), over_under = VALUES(over_under),\
  number_of_correlations_found = VALUES(number_of_correlations_found);\
",
            (team_name, home_away, over_under, value))

    # Commit the changes to the database
    conn.commit()

    # Close the cursor and connection
    cur.close()
    conn.close()


def create_counter_from_database(user_name, user_password, host_name):
    # connect to the database
    cnx = mysql.connector.connect(db=db,
                                   user=user_name, password=user_password, host=host_name)
    # create a cursor
    cursor = cnx.cursor()

    # create a counter
    c = Counter()

    # select the rows you are interested in
    query = '''
        SELECT team_name, home_away, over_under, number_of_correlations_found
        FROM correlations_table
    '''
    cursor.execute(query)

    # iterate over the rows and update the counter
    for (team_name, home_away, over_under, number_of_times) in cursor:
        key = team_name + ' ' + home_away + ' ' + over_under
        c.update({key: number_of_times})

    # close the cursor and connection
    cursor.close()
    cnx.close()

    return c

