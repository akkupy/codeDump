def isPalindrome(self, head):
  curr = head
  pos = 0
  
  while curr:
      curr = curr.next
      pos += 1
  
  pos = pos//2
  
  while beg <= fim:
      if arr[beg] != arr[fim]:
          return(False)
      else:
          beg += 1
          fim -= 1
  
  return(True)