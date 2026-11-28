import os,sys
def main():
    crackme_name:str
    path:str
    arch:str = "x86-64"
    os_name:str = "Windows"
    if len(sys.argv) >= 2:
        crackme_name = sys.argv[1]
    else:
        crackme_name = input("Enter crackme's name: ")
        # arch = input("Enter crackme's arch: ")
        # os_name = input("Enter crackme's OS name: ")
    path = f".\\write_ups\\{arch}\\{os_name}\\"+crackme_name+"\\"

    if not os.path.exists(path):
        os.makedirs(path)
    if not os.path.exists(path+crackme_name+".md"):
        try:
            with open(path+crackme_name.replace(" ", "_")+".md", 'x', encoding='utf-8') as f:
                f.write(f"# [{crackme_name}]()\n")
        except FileExistsError:
            pass
    try:
        with open(path+"write_up.md","x", encoding="utf-8"):
            pass
    except FileExistsError:
        pass


if __name__ == '__main__':
    main()