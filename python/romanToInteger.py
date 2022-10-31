def romanToInt(self, s):
  sumTotal = 0
  pos = 0
  
  while pos < len(s):
      if(s[pos] == 'M'):
          sumTotal += 1000
      elif(s[pos] == 'D'):
          sumTotal += 500
      elif(s[pos] == 'C'):
          if(pos < len(s)-1):
              if(s[pos+1] == 'D'):
                  sumTotal += 400
                  pos += 1
              elif(s[pos+1] == 'M'):
                  sumTotal += 900
                  pos += 1
              else:
                  sumTotal += 100
          else:
              sumTotal += 100
      elif(s[pos] == 'L'):
          sumTotal += 50
      elif(s[pos] == 'X'):
          if(pos < len(s)-1):
              if(s[pos+1] == 'L'):
                  sumTotal += 40
                  pos += 1
              elif(s[pos+1] == 'C'):
                  sumTotal += 90
                  pos += 1
              else:
                  sumTotal += 10
          else:
              sumTotal += 10
      elif(s[pos] == 'V'):
          sumTotal += 5
      elif(s[pos] == 'I'):
          if(pos < len(s)-1):
              if(s[pos+1] == 'V'):
                  sumTotal += 4
                  pos += 1
              elif(s[pos+1] == 'X'):
                  sumTotal += 9
                  pos += 1
              else:
                  sumTotal += 1
          else:
              sumTotal += 1
      
      pos += 1
      
  return(sumTotal)