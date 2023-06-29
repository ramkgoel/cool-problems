***If no parentheses. (simpler_evaluation_no_parentheses.py).***

Keep track of (current answer, if there is an operation queued up, current index). **evaluate(cur_ans, op, index)**. 
Start with evaluate(0, None, 0). (This handles the case of initial -). Go index by index. We do index+1 because it just means we now look at the next index. cur_ans is the current answer before we look at tokens[index], and similarly op is the operation before we look at token = tokens[index]. Now:

- If token is an int, 
    - with a previous operation, that means we combine this int with the current answer using the operation. new_ans = operation(cur_ans, token). Now we used up the operation, so no new operation. So **evaluate(new_ans, None, index+1)**. 

	- with no previous operation, it must be the start of a new expression/subexpression. So ans is now the token, and no new op. So **evaluate(token, None, index+1)**. Note that we expect the next token to be an operation. 

- Else, token must be an operation. Then **evaluate(cur_ans, op, index+1)**.

Example: 2+2-1. Keeping track of (cur_ans, op, index). *Uncomment the print statements to see evaluate statements in code*
- evaluate(0, None, 0)
- evaluate(2, None, 1)
- evaluate(2, +, 2)
- evaluate(4, None, 3)
- evaluate(4, -, 4)
- evaluate(3, None, 5)

***Now full case: including parentheses. (evaluation.py)***




