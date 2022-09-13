"""
Question 4:

Create a function that takes a list of football clubs with properties: name, wins, loss, draws, scored, conceded, and returns the team name with the highest number of points. If two teams have the same number of points, return the team with the largest goal difference.

How to Calculate Points and Goal Difference
team = { "name": "Manchester United", "wins": 30, "loss": 3, "draws": 5, "scored": 88, "conceded": 20 }
Total Points = 3 * wins + 0 * loss + 1 * draws = 3 * 30 + 0 * 3 + 5 * 1 = 95 points 
Goal Difference = scored - conceded = 88 - 20 = 68
"""

def RankTeams(lst):
    for each_team in lst:
        points = 3 * each_team[1] + 1 * each_team[3]
        goal_diff = each_team[4] - each_team[5]
        each_team.append(goal_diff)
        each_team.append(points)

    # making points table by sorting teams in descending order based on points, goal difference(if points are equal)
    # points is the value at index 7 in our list and goal difference is at index 6
    table = sorted(lst, key= lambda x: (x[7], x[6]), reverse=True)
    return table

# Input
# is a list of lists, think of it as a 2D array
# each individual list contains team name, wins, losses, draws, goals scored and goals conceded, in that order
lst = [['Man Utd', 30, 3, 5, 88, 20],
       ['Man City', 31, 0, 6, 104, 12],
       ['Chelsea', 31, 2, 6, 95, 0]]

points_table = RankTeams(lst)

# name of team ranked first in the points table
print(points_table[0][0])