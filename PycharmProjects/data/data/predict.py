import matplotlib.pyplot as pyplot
from matplotlib.pyplot import figure
from sklearn.tree import DecisionTreeClassifier
import math
import numpy as np

fig, ax = pyplot.subplots()

def display(counter):
    teams = np.array([])
    nums = np.array([])
    # scatter plot of examples by class label
    for team, num in counter.items():
        pyplot.barh(team, num, label=str(team))
        np.append(teams, [team])
        np.append(nums, [num])

    #y_pos = np.arange(len(teams))
    #ax.set_yticks(y_pos)
    #ax.set_ylabel(teams)
    #ax.invert_yaxis()  # labels read top-to-bottom
    #figure(figsize=(10, 8), dpi=80)
    ax.set_xlabel('Occurrences')
    ax.set_title('Data')
    pyplot.legend()
    pyplot.show()
    #tree(labels, nums)


def convertToNumber(s):
    return int.from_bytes(s.encode(), 'little')


def convertFromNumber(n):
    return n.to_bytes(math.ceil(n.bit_length() / 8), 'little').decode()


def tree(labels, nums):
    model: DecisionTreeClassifier = DecisionTreeClassifier(max_depth=2, random_state=0)
    labels_as_numbers = np.array([convertToNumber(num) for num in labels])
    data = np.array([labels_as_numbers, nums])
    model.fit(data, labels_as_numbers)
    model.predict(labels_as_numbers)
    tree.plot_tree(model)
