import os
import shutil
from config import *

def isExecFile(path: str):
    if os.path.isfile(path):
        return path.endswith(".exe")
    return False

def isWasteDir(path: str):
    dirs = ["__pycache__", ".ropeproject", "node_modules"]
    return os.path.isdir(path) and os.path.basename(path) in dirs

def clean(path: str, rule):
    for root, dirs, files in os.walk(path):
        for name in files:
            filePath = os.path.join(root, name)
            if(rule(filePath)):
                os.remove(filePath)
        for name in dirs:
            dirPath = os.path.join(root, name)
            if(rule(dirPath)):
                shutil.rmtree(dirPath)
