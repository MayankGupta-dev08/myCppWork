import os

def updateReadMe(path):
    os.chdir(path)
    fileList = os.listdir(path)
    with open("ReadMe.txt", "w") as f:
        for file in fileList:
            print(file, sep="\n")
            f.write(file+"\n")

if __name__ == "__main__":
    try:
        path = r"D:\\Mayank\\Coding\\C++\\myWork_cpp"
        updateReadMe(path)
    except:
        print("Something went wrong!")