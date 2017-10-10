.name "nik_zork"
.comment "I'M MORE ALIIIIVE"

l2:		sti r1, %:live, %1
		and r2, %0, r2
test:	fork %10

live:	live %1
		zjmp %:test

l3:		sti r1, %:live1, %1

live1:	live %1
		zjmp %:live1
