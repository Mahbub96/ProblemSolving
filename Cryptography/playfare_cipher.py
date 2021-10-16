from array import *


# impliment function to create a table
def make_table(table, ey):

    ch = 'A'
    c = 0
    C = 0

    sampleTable = [50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 61, 63,
                   64, 91, 93, 123, 125, 33, 34, 35, 36, 37, 38, 40, 41, 44, 46]
    for i in range(9):
        print(table, c)
        # push Capital Latters
        if(c <= 26):
            for j in range(9):
                if(c == 26):
                    table[i].append('a')
                    ch = 'b'
                    c += 1
                    break

                table[i].append(chr(ord(ch) + c))
                c += 1

        # # push small latter on table table
        # elif(c > 26 and c < 53):
        #     for j in range(9):
        #         c += 1
        #         if(c <= 52):
        #             table[i][j] = chr(ord(ch) + C)
        #         else:
        #             table[i][j] = chr(48)
        #             table[i][j] = chr(49)
        #             j += 2
        #             c += 2
        #             C = 0
        # else:
        #     for j in range(9):

        #         table[i][j] = chr(sampleTable[C])
        #         C += 1
    return table


# implimentation cipher maker app


def playfare_cipher(text, key):
    key = list(dict.fromkeys(text))  # to remove duplicates form key
    table = [9][9]
    print(make_table(table, key))  # to create a table
    # print(table)


playfare_cipher("apple", "apple")
