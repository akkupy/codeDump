def longestCommonPrefix(self, strs):
  """
  :type strs: List[str]
  :rtype: str
  """
  temp = strs[0]
  palavra = ""
  result = ""
  for pos in range(len(temp)):
      palavra += temp[pos]
      for word in strs:
          if not word.startswith(palavra):
              return result
          
      result = palavra
  
  return result