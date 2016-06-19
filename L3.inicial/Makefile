
TEST=../L3.tests

all: proves_coord proves_direccio proves_casella proves_taulell otelo

util: util.cc util.h
	g++ -c util.cc; \

proves_coord: coord.cc coord.h proves_coord.cc
	g++ -o proves_coord proves_coord.cc coord.cc; \

proves_direccio: direccio.cc coord.h direccio.h proves_direccio.cc
	g++ -o proves_direccio proves_direccio.cc coord.cc direccio.cc; \

proves_casella: casella.h casella.cc proves_casella.cc
	g++ -o proves_casella proves_casella.cc casella.cc; \

proves_taulell: util.h coord.h direccio.h casella.h taulell.h taulell.cc proves_taulell.cc
	g++ -o proves_taulell proves_taulell.cc util.cc coord.cc direccio.cc casella.cc taulell.cc; \

otelo: util.h coord.h direccio.h casella.h taulell.h taulell.cc otelo.cc
	g++ -o otelo otelo.cc util.cc coord.cc direccio.cc casella.cc taulell.cc; \

clean:
	rm -f *.o proves_coord proves_casella proves_taulell otelo

test_coord:
	@echo "--------------------------------------------------"
	./proves_coord < $(TEST)/coord1.in | diff - $(TEST)/coord1.out;
	./proves_coord < $(TEST)/coord2.in | diff - $(TEST)/coord2.out;
	./proves_coord < $(TEST)/coord3.in | diff - $(TEST)/coord3.out;

test_direccio:
	@echo "--------------------------------------------------"
	./proves_direccio < $(TEST)/direccio1.in | diff - $(TEST)/direccio1.out;

test_casella:
	@echo "--------------------------------------------------"
	./proves_casella | diff - $(TEST)/casella.out; 

test_taulell:
	@echo "--------------------------------------------------"
	./proves_taulell | diff - $(TEST)/taulell.out;

test_otelo:
	@echo "--------------------------------------------------"
	./otelo 2 | diff - $(TEST)/otelo2.out;
	./otelo 3 < $(TEST)/otelo3_1.in | diff - $(TEST)/otelo3_1.out;
	./otelo 3 < $(TEST)/otelo3_2.in | diff - $(TEST)/otelo3_2.out;
	./otelo 4 < $(TEST)/otelo4.in | diff - $(TEST)/otelo4.out;
	./otelo 8 < $(TEST)/otelo8.in | diff - $(TEST)/otelo8.out;

test_otelo_mm:
	@echo "--------------------------------------------------"
	./otelo 4 2 1 0 0 < $(TEST)/otelo4a.in | diff - $(TEST)/otelo4a_p1_m0.out;
	./otelo 4 2 1 1 0 < $(TEST)/otelo4a.in | diff - $(TEST)/otelo4a_p1_m1.out;
	./otelo 4 2 2 0 0 < $(TEST)/otelo4a.in | diff - $(TEST)/otelo4a_p2_m0.out;
	./otelo 4 2 2 1 0 < $(TEST)/otelo4a.in | diff - $(TEST)/otelo4a_p2_m1.out;

	./otelo 4 2 1 0 0 < $(TEST)/otelo4b.in | diff - $(TEST)/otelo4b_p1_m0.out;
	./otelo 4 2 1 1 0 < $(TEST)/otelo4b.in | diff - $(TEST)/otelo4b_p1_m1.out;
	./otelo 4 2 2 0 0 < $(TEST)/otelo4b.in | diff - $(TEST)/otelo4b_p2_m0.out;
	./otelo 4 2 2 1 0 < $(TEST)/otelo4b.in | diff - $(TEST)/otelo4b_p2_m1.out;

	./otelo 3 2 1 0 0 < $(TEST)/otelo3.in | diff - $(TEST)/otelo3.out;
	./otelo 3 2 1 1 0 < $(TEST)/otelo3.in | diff - $(TEST)/otelo3.out;
	./otelo 3 2 2 0 0 < $(TEST)/otelo3.in | diff - $(TEST)/otelo3.out;
	./otelo 3 2 2 1 0 < $(TEST)/otelo3.in | diff - $(TEST)/otelo3.out;

	./otelo 8 2 1 0 0 < $(TEST)/otelo8_p1_m0.in | diff - $(TEST)/otelo8_p1_m0.out;
	./otelo 8 2 1 1 0 < $(TEST)/otelo8_p1_m1.in | diff - $(TEST)/otelo8_p1_m1.out;
	./otelo 8 2 2 0 0 < $(TEST)/otelo8_p2_m0.in | diff - $(TEST)/otelo8_p2_m0.out;
	./otelo 8 2 2 1 0 < $(TEST)/otelo8_p2_m1.in | diff - $(TEST)/otelo8_p2_m1.out;

test_otelo_mm_debug1:
	@echo "--------------------------------------------------"
	./otelo 4 2 1 0 1 < $(TEST)/otelo4a.in | diff - $(TEST)/otelo4a_p1_debug.out;
	./otelo 4 2 2 0 1 < $(TEST)/otelo4a.in | diff - $(TEST)/otelo4a_p2_debug.out;

	./otelo 4 2 1 0 1 < $(TEST)/otelo4b.in | diff - $(TEST)/otelo4b_p1_debug.out;
	./otelo 4 2 2 0 1 < $(TEST)/otelo4b.in | diff - $(TEST)/otelo4b_p2_debug.out;

	./otelo 3 2 1 0 1 < $(TEST)/otelo3.in | diff - $(TEST)/otelo3_p1_debug.out;
	./otelo 3 2 2 0 1 < $(TEST)/otelo3.in | diff - $(TEST)/otelo3_p2_debug.out;

test_otelo_mm_debug2:
	@echo "--------------------------------------------------"
	./otelo 4 2 1 0 2 < $(TEST)/otelo4a.in | diff - $(TEST)/otelo4a_p1_m0_debug.out;
	./otelo 4 2 1 1 2 < $(TEST)/otelo4a.in | diff - $(TEST)/otelo4a_p1_m1_debug.out;
	./otelo 4 2 2 0 2 < $(TEST)/otelo4a.in | diff - $(TEST)/otelo4a_p2_m0_debug.out;
	./otelo 4 2 2 1 2 < $(TEST)/otelo4a.in | diff - $(TEST)/otelo4a_p2_m1_debug.out;

	./otelo 4 2 1 0 2 < $(TEST)/otelo4b.in | diff - $(TEST)/otelo4b_p1_m0_debug.out;
	./otelo 4 2 1 1 2 < $(TEST)/otelo4b.in | diff - $(TEST)/otelo4b_p1_m1_debug.out;
	./otelo 4 2 2 0 2 < $(TEST)/otelo4b.in | diff - $(TEST)/otelo4b_p2_m0_debug.out;
	./otelo 4 2 2 1 2 < $(TEST)/otelo4b.in | diff - $(TEST)/otelo4b_p2_m1_debug.out;

	./otelo 3 2 1 0 2 < $(TEST)/otelo3.in | diff - $(TEST)/otelo3_p1_m0_debug.out;
	./otelo 3 2 1 1 2 < $(TEST)/otelo3.in | diff - $(TEST)/otelo3_p1_m1_debug.out;
	./otelo 3 2 2 0 2 < $(TEST)/otelo3.in | diff - $(TEST)/otelo3_p2_m0_debug.out;
	./otelo 3 2 2 1 2 < $(TEST)/otelo3.in | diff - $(TEST)/otelo3_p2_m1_debug.out;

	./otelo 8 2 1 0 2 < $(TEST)/otelo8_p1_m0.in | diff - $(TEST)/otelo8_p1_m0_debug.out;
	./otelo 8 2 1 1 2 < $(TEST)/otelo8_p1_m1.in | diff - $(TEST)/otelo8_p1_m1_debug.out;
	./otelo 8 2 2 0 2 < $(TEST)/otelo8_p2_m0.in | diff - $(TEST)/otelo8_p2_m0_debug.out;
	./otelo 8 2 2 1 2 < $(TEST)/otelo8_p2_m1.in | diff - $(TEST)/otelo8_p2_m1_debug.out;

