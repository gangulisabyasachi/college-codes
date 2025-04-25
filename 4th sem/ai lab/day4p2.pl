and_gate(0, 0, 0).
and_gate(0, 1, 0).
and_gate(1, 0, 0).
and_gate(1, 1, 1).

or_gate(0, 0, 0).
or_gate(0, 1, 1).
or_gate(1, 0, 1).
or_gate(1, 1, 1).

not_gate(0, 1).
not_gate(1, 0).

nand_gate(A, B, X) :- and_gate(A, B, Y), not_gate(Y, X).

nor_gate(A, B, X) :- or_gate(A, B, Y), not_gate(Y, X).

xor_gate(A, B, X) :- or_gate(A, B, OR), nand_gate(A, B, NAND), and_gate(OR, NAND, X).

xnor_gate(A, B, X) :- xor_gate(A, B, Y), not_gate(Y, X).

print_table_header(Gate) :-
    format('~n Truth Table for ~w Gate~n', [Gate]),
    format('------------------------~n').

print_table(Gate) :-
    print_table_header(Gate),
    format(' A | B | Result ~n'),
    format('----------------~n'),
    forall(
        (member(A, [0,1]), member(B, [0,1]), call(Gate, A, B, X)),
        format(' ~w | ~w | ~w ~n', [A, B, X])
    ).

print_not_table :-
    print_table_header('NOT'),
    format(' A | Result ~n'),
    format('------------~n'),
    forall(
        (member(A, [0,1]), not_gate(A, X)),
        format(' ~w | ~w ~n', [A, X])
    ).

print_all_tables :-
    print_table(and_gate), nl,
    print_table(or_gate), nl,
    print_not_table, nl,
    print_table(nand_gate), nl,
    print_table(nor_gate), nl,
    print_table(xor_gate), nl,
    print_table(xnor_gate).
