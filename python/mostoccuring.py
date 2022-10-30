# Python program to find the most occurring
# character and its count
from collections import Counter
  
def find_most_occ_char(input):
  
    # now create dictionary using counter method
    # which will have strings as key and their 
    # frequencies as value
    wc = Counter(input)
  
    # Finding maximum occurrence of a character 
        # and get the index of it.
    s = max(wc.values())
    i = wc.values().index(s)
      
    print wc.items()[i]
  
# Driver program
if __name__ == "__main__":
    input = 'geeksforgeeks'
    find_most_occ_char(input)
