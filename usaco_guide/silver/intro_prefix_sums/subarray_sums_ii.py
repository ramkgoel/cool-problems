# make prefix sum array
# starting at i, the valid arrays are: the minimal one from i->j, and then all possible 0-sum arrays from j onwards
# so as you do prefix[i], add prefix[i] + x to targets. if prefix[j] in targets, then you have the minimal hit from j backwards or something. 
# also whenever you have prefix[i], add it to the list in dict for prefix[i]. now you win. 
