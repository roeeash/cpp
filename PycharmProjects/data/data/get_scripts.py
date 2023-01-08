import requests
from selenium import webdriver
from bs4 import BeautifulSoup
import json

def get_webpage(url):
    # create a new PhantomJS browser
    options = webdriver.ChromeOptions()
    options.add_argument('--headless')
    driver = webdriver.Chrome(options=options)



    # load the webpage
    driver.get(url)

    # wait for the page to load
    driver.implicitly_wait(5)

    # get the HTML content of the page
    html = driver.page_source

    # close the browser
    driver.close()

    return html


def get_shots(html):
    # parse the HTML content
    soup = BeautifulSoup(html, 'html.parser')

    # find all the script tags
    scripts = soup.find_all('script')

    return scripts

def get_json_shots_data(html):
    scripts = get_shots(html)
    shots = scripts[3].string
    # strip unwanted symbols
    ind_start_shots = shots.index("(") + 2
    ind_end_shots = shots.index(")") - 1
    json_shots_data = shots[ind_start_shots:ind_end_shots]
    json_shots_data = json_shots_data.encode("utf8").decode("unicode_escape")
    json_data = json.loads(json_shots_data)
    return json_data
