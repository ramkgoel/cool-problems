def pre_process(s):
        tokens = list(s.replace(' ', ''))
        cur_num = ''
        final = []
        
        for char in tokens:
            if char not in '+/-*()':
                cur_num += char
            else:
                if len(cur_num) >= 1:
                    final.append(int(cur_num))
                cur_num = ''
                final.append(char)

        if len(cur_num) >= 1:    
            final.append(int(cur_num))
        return final

def calculate(s):
    tokens = pre_process(s)
    ops = {'+': lambda x,y:x+y, '-': lambda x,y:x-y, "*": lambda x,y:x*y, '/': lambda x,y:x/y}
    cur_ans = None
    
    def evaluate(cur_ans, op, index):
        if index >= len(tokens):
            return cur_ans, len(tokens)

        cur_token = tokens[index]
        #print(index, cur_token, cur_ans)
        
        if cur_token == '(':
            sub_ans, sub_index = evaluate(0, None, index+1)
            
            if op is not None:
                new_ans = ops[op](cur_ans, sub_ans)
                #print("evaluate", new_ans, None, index+1)
                return evaluate(new_ans, None, sub_index+1)
            else:
                #print("evaluate", cur_token, None, index+1)
                return evaluate(sub_ans, None, sub_index+1)

        elif cur_token == ')':
            return cur_ans, index
            
        
        elif isinstance(cur_token, int):
            if op is not None:
                new_ans = ops[op](cur_ans, cur_token)
                #print("evaluate", new_ans, None, index+1)
                return evaluate(new_ans, None, index+1)
            else:
                #print("evaluate", cur_token, None, index+1)
                return evaluate(cur_token, None, index+1)
            
        elif cur_token in '+-*/':
            #print("evaluate", cur_ans, cur_token, index+1)
            return evaluate(cur_ans, cur_token, index+1)
            

    return evaluate(0, None, 0)

def main():
    print(pre_process("2 + (2 - 1)"))
    
    s = "20 * (20 +(3*2) - 1)" # [2, '+', 2, '-', 1]
    #s = "20+100+200-98-2" 
    print(calculate(s)[0])

    

main()

