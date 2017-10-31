from nltk.tokenize import sent_tokenize

def substring_list(n, s):
    """Return a list in of substrings of length n from original string s"""
    ret_list = list()

    for i in range(0, len(s)-n):
        temp = s[i:i+n]
        ret_list.append(temp)

    return ret_list

def lines(a, b):
    """Return lines in both a and b"""

    # TODO
    # Take in string inputs A, B
    # Split the lines into lists
    asplit = a.splitlines()
    bsplit = b.splitlines()
    simlist = list()

    # Iterate through all elements.
    for x in range(len(bsplit)):
        # Compare them
        if asplit[x] == bsplit[x]:
            # And add to a new list if they are the same
            if simlist.count(bsplit[x]) == 0:
                simlist.append(bsplit[x])
    return simlist


def sentences(a, b):
    """Return sentences in both a and b"""

    asplit = sent_tokenize(a)
    bsplit = sent_tokenize(b)
    simlist = set(asplit) & set(bsplit)



    # # Iterate through all elements.
    # for x in range(len(bsplit)):
    #     # Compare them
    #     if (len(asplit) < len(bsplit)) and (asplit[x] == bsplit[x]):
    #         # And add to a new list if they are the same
    #         if simlist.count(bsplit[x]) == 0:
    #             simlist.append(bsplit[x])
    return simlist


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""
    asplit = substring_list(n, a)
    bsplit = substring_list(n, b)
    simlist = set(asplit) & set(bsplit)

    return simlist


