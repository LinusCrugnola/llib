import os
from datetime import date
import glob
import re
import fnmatch

today = date.today()

# snippets to insert
head_1 = "/*!****************************************************************************************************************************************\n* @file     "
head_2 = "\n*\n* @author   Linus Crugnola <linus.crugnola@epfl.ch>     \n*\n* @version  1.0\n*\n* @date     "
head_3 = "\n*****************************************************************************************************************************************/"


path = os.path.dirname(os.path.abspath(__file__))

files = []
    
for end in ['*.cpp', '*.cc', '*.h']:
    for root, dirnames, filenames in os.walk(path):
        for filename in fnmatch.filter(filenames, end):
            if 'build' not in root and 'build' not in filename:
                files.append(os.path.join(root, filename))

for file in files:
    myfile = open(file, 'r')
    if file[-1] == "c":
        describtion = file.replace('.cc','') + " implementation"
    elif file[-1] == "h":
        describtion = file.replace('.h','') + " interface"
    fline = head_1 + os.path.basename(file) + head_2 + today.strftime("%d.%m.%Y") + head_3
    content = myfile.read()
    if content[0:10] != "/*!*******":
        new_content = fline + "\n \n" + content
        myfile.close()
        myfile = open(file, "w")
        myfile.write(new_content)
        myfile.close()
    else:
        myfile.close()
        with open(file, "w") as myfile:
            myregex = re.compile("\/\*{10,}[\s\S]*\*{10,}\/")
            myfile.write(myregex.sub(fline, content))

print("added headers for: ", end="")
for file in files:
    print(file, end="")
    print(", ", end="")