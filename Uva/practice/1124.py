while(True):
    inp = ''
    try:
        inp = input()
    except EOFError:
        break
    print(inp)
