# Write a function with name ‘roots_quad_eqn’, having three arguments a, b, c. This function would
# find out the roots of a quadratic equation:- ax2 + bx + c = 0 and return the following:
#     (i) Root # 1 : Real part + i (imaginary part)
#     (ii) Root # 2 : Real part - i (imaginary part)
#     (iii) A Boolean value (True if the roots are real and false if the roots are complex)

roots_quad_eqn <- function(a, b, c) {
    # Calculate the discriminant
    discriminant <- b^2 - 4 * a * c

    # Calculate the real part
    real_part <- -b / (2 * a)

    # Check if the roots are real or complex
    if (discriminant >= 0) {
        imaginary_part <- sqrt(discriminant) / (2 * a)
        root1 <- real_part + imaginary_part
        root2 <- real_part - imaginary_part
        roots_real <- TRUE
    } else {
        imaginary_part <- sqrt(-discriminant) / (2 * a)
        root1 <- paste(real_part, "+", imaginary_part, "i")
        root2 <- paste(real_part, "-", imaginary_part, "i")
        roots_real <- FALSE
    }

    return(list(Root1 = root1, Root2 = root2, RootsReal = roots_real))
}

# Example usage
result <- roots_quad_eqn(1, -3, 2)
print(result)

# output
# $Root1
# [1] 2

# $Root2
# [1] 1

# $RootsReal
# [1] TRUE