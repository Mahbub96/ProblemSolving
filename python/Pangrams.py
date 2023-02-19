s = input()


def isTrue(s):
    s = sorted(set(s.lower()))
    s = s[1:] if s[0] == ' ' else s[:]

    return "pangram" if len(s) == 26 else "not pangram"


print(isTrue(s))
