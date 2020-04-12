import sys

def gcd(a, b):
    while b != 0: a, b = b, a % b
    return a

def freecell_statistics(N, PD, PG):
    a = 100 // gcd(100, PD)
    if a > N: return 'Broken'
    if PD < 100 and PG == 100: return 'Broken'
    if PD > 0 and PG == 0: return 'Broken'
    return 'Possible'
    

def main(filename):
    Input = open(filename, 'r').read().split('\n')
    Output = ""
    for i in range(1, int(Input[0]) + 1):
        args = Input[i].split(' ')
        N = int(args[0]); PD = int(args[1]); PG = int(args[2])
        result = freecell_statistics(N, PD, PG)
        Output += "Case #" + str(i) + ": " + result + "\n"
    open(filename[:-3] + ".out", 'w').write(Output)

if __name__ == "__main__": main(sys.argv[1])
