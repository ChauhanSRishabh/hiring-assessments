import os
import csv
import json
from collections import defaultdict

dirname = os.path.dirname(__file__)
csvFilePath = os.path.join(dirname, 'input.csv')
jsonFilePath = os.path.join(dirname, 'final_output.json')


def dynamicTree():
    return defaultdict(dynamicTree)

def getValue():
    return {}


def makeNode(name, leaf):
    res = {"name": name}
    if len(leaf.keys()) > 0:
        a = [makeNode(k, v) for k, v in leaf.items() if k != ""]
        if len(a) != 0:
            res["children"] = a

    return res
    

tree = {}
with open(csvFilePath) as csvfile:
    reader = csv.reader(csvfile)
    for rid, row in enumerate(reader):
        if rid == 0:
            continue
        leaf = {}
        tree[row[0]] = getValue()
        leaf.update(tree[row[0]])

        for cid in range(1, len(row)):
            try:
                leaf = leaf[row[cid]]
                
            except KeyError:
                pass
                leaf = getValue(row[cid], tree)

res = []
for name, leaf in tree.items():
    res.append(makeNode(name, leaf))

# Creating JSON File
with open(jsonFilePath, 'w', encoding='utf-8') as jsonf:
        jsonf.write(json.dumps(res, indent=1))