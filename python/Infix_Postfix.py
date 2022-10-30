class stack:
    def __init__(self):
        self.item = []
    
    def push(self,it):
        self.item.append(it)
    def peek(self): #position of the data
        if self.isempty() == True:
            return 0
        return self.item[-1]
    
    def pop(self):
        if self.isempty() == True:
            return 0
        return(self.item.pop())
    
    def length(self):
        return (len(self.item))
    
    
    def isempty(self):
        if self.item == []:
            return True
        else:
            return False
    
    def display(self):
        if self.isempty()== True:
            return
        temps = stack()
        while(self.isempty() != True):
            x = self.peek()
            print("~",x)
            temps.push(x)
            self.pop()
        while(temps.isempty() != True):
            x = temps.peek()
            self.push(x)
            temps.pop()
    
    
    def isOperand(self, ch): 
        return ch.isalpha()
        
    def notGreater(self, i):
        precedence = {'+':1, '-':1, '*':2, '/':2, '%':2, '^':3}
        if self.peek() == '(':
            return False
        a = precedence[i]
        b = precedence[self.peek()] 
        if a <= b:
            return True
        else:
            return False
            
    
    
    def infixToPostfix(self, exp):
        output = ""
        
        for i in exp:
            
            if self.isOperand(i) == True: # check if operand add to output
                print(i,"~ Operand push to stack")
                output = output + i
    
            # If the character is an '(', push it to stack 
            elif i == '(':
                self.push(i)
                print(i," ~ Found ( push into stack")
    
            elif i == ')': # if ')' pop till '('
                while( self.isempty() != True and self.peek() != '('):
                    n = self.pop() 
                    output = output + n
                    print(n, "~ Operator popped from stack")
                if (self.isempty() != True and self.peek() != '('):
                    print("_________")
                    return -1
                else:
                    x = self.pop()
                    print(x, "Popping and deleting (")
            else: 
                while(self.isempty() != True and self.notGreater(i)):
                    if self.peek()=='^' and i=='^':
                        break
                    c = self.pop()
                    output = output + c
                    print(c,"Operator popped after checking precedence from stack")
                self.push(i)
                print(i,"~ Operator pushed to stack")
    
        # pop all the operator from the stack 
        while self.isempty() != True:
            xx = self.pop()
            output = output + xx
            print(xx,"~ pop at last")
        print(output)
        self.display()
st = stack()
st.infixToPostfix("a^b^c")
