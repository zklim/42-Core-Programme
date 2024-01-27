# Minishell42

<pre>
echo $? = check last exit status  
man errno = check errno meaning  
</pre>

<pre>
\> = output redirection  
< = input redirection  
<< = heredoc  
\>> = append output  
</pre>

<pre>
char *const = constant pointers    
const char* =  pointers to constant characters   
</pre>

<pre>\* don't works as wildcard in C, the arguments and environment are provided as arrays of pointers.  </pre>

<pre>
echo "something""something2" prints somethingsomething2  
echo "something" "something2" prints something something2  
echo "something"     	    "something2" still prints something something2  
echo "something\n""something2" prints something\nsomething2   
</pre>