n = 10
s = "ehfslkjhalwfouberubvaisdhvalkjdsbvaliuerboqv;webdsvlajksdbliuvahgsdfobndslvbasdo;u vacs;od hvdiosuh aljsdnlj dhsj hksdjc odjh clusdhcl jsdhc hds"


def substring_list(n, s):
    """Return a list in of substrings of length n from original string s"""
    ret_list = list()
    
    for i in range(0, len(s)-n):
        temp = s[i:i+n]
        ret_list.append(temp)
    
    return ret_list



