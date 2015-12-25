call fibonacci(0, 1)

def fibonacci(#x , #y)

    for(#i = 0 | #i <= 10 | #i++)
        #z = #x + #y
        print #z
        print '<br/>'
        #x = #y    
        #y = #z
    end

end