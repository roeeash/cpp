import mysql.connector
from mysql.connector import Error


# create the sql connection
def create_server_connection(host_name, user_name, user_password, _db):
    connection = None
    try:
        connection = mysql.connector.connect(db=_db, host=host_name,
                                             user=user_name, password=user_password, port=3306)
        print("mysql connection successful")
    except Error as err:
        print("Error: '{}' mysql connection unsuccessful".format(err))

    return connection


# perform sql query
def excecute_query(connection, query):
    cursor = connection.cursor()
    print("Executing query:", query)
    try:
        result = cursor.execute(query)
        print("Result of execute:", result)
        print("query executed successfully")
    except Error as err:
        print("Error: '{}' mysql connection unsuccessful".format(err))


# put our mysql temrinal password
pw = "Yuhaz1234@"


# insert the rows from the dictionary
def insert_rows_from_dict(d, user_name, user_password, host_name, _db):
    # Connect to the database
    conn = mysql.connector.connect(db=_db,
                                   user=user_name, password=user_password, host=host_name)

    # Create a cursor to execute commands
    cur = conn.cursor()

    # Iterate through the dictionary and insert the data into the table
    for key, value in d.items():
        cur.execute(
            "INSERT INTO players (id, first_name, last_name, position, height_feet, height_inches, weight_pounds, team_name, field_goal_pct) VALUES (%s, %s, %s, %s, %s, %s, %s, %s, %s) ON DUPLICATE KEY UPDATE id = VALUES(id), first_name = VALUES(first_name), last_name = VALUES(last_name), position = VALUES(position), height_feet = VALUES(height_feet), height_inches = VALUES(height_inches), weight_pounds = VALUES(weight_pounds), team_name = VALUES(team_name), field_goal_pct = VALUES(field_goal_pct);",
            (key, value['first name'], value['last name'], value['position'], value['height'][0], value['height'][1],
             value['weight'], value['team'], value['field goal pct']))

    # Commit the changes to the database
    conn.commit()

    # Close the cursor and connection
    cur.close()
    conn.close()



