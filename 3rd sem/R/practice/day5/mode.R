getmode <- function(v) {
    uniqv <- unique(v)
    uniqv[which.max(tabulate(match(v, uniqv)))]
}
#with numbers
v <- c(2,1,2,3,1,2,3,4,1,5,5,3,2,3)
result<- getmode(v)
print(result)

result1<- getmode(v)
print(result1)

#with characters
charv<- c("o","it","the","it","it")
mode = which.max(table(charv))
print(mode)

result2<- getmode(charv)
print(result2)

